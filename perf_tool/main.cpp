#include <asm/perf_regs.h>
#include <asm/unistd.h>
#include <fcntl.h>
#include <linux/perf_event.h>
#include <signal.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <assert.h>

#define barrier() __asm__ __volatile__("" : : : "memory")

static const uint64_t PERF_BUFF_SIZE_SHIFT = 4;
static const uint64_t PERF_MMAP_DATA_SIZE = 10 * 1024 * 1024;

static int perf_event_open(struct perf_event_attr *hw_event, pid_t pid, int cpu,
                           int group_fd, unsigned long flags) {
  int ret = syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
  return ret;
}

static uint64_t get_page_size() { return sysconf(_SC_PAGESIZE); }

static uint64_t perf_mmap_size()
{
  return ((1U << PERF_BUFF_SIZE_SHIFT) + 1) * get_page_size();
}

struct perf_record_time
{
  struct perf_event_header header;
  uint64_t time;
};

struct perf_data
{
  perf_event_mmap_page *page = NULL;
  uint64_t pages_size = 0;
  uint64_t data_offset = 0;
  uint64_t data_size = 0;
  int fd = -1;
  uint8_t* perf_data = NULL;
  uint64_t perf_data_length = 0;
};

static perf_data g_perf_data;

static void read_perf_data()
{
  perf_event_mmap_page *page = g_perf_data.page;

  uint64_t tail = page->data_tail;
  const uint64_t head = page->data_head;
  const uint64_t buffer_size = g_perf_data.data_size;
  const uint64_t page_size = g_perf_data.data_offset;
  uint8_t * perf_data = g_perf_data.perf_data;
  uint64_t perf_data_length = g_perf_data.perf_data_length;
  auto time = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  barrier();
  const uint8_t *base = reinterpret_cast<const uint8_t *>(page) + page_size;

  // https://android.googlesource.com/platform/external/bcc/+/fd247435dfdfe9a6daa159620127f2724f6d1d7a/src/cc/perf_reader.c
  while (tail + sizeof(perf_event_header) <= head ) {
    const uint8_t *begin = base + tail % buffer_size;
    const perf_event_header *e = (const perf_event_header *)begin;
    if (e->type == PERF_RECORD_SAMPLE && perf_data_length + e->size <= PERF_MMAP_DATA_SIZE)
    {
      const uint8_t *end = base + (tail + e->size) % buffer_size;
      perf_record_time* record = (perf_record_time*)(perf_data + perf_data_length);
      if (end < begin)
      {
        // perf event wraps around the ring, make a contiguous copy
        const uint8_t *sentinel = base + buffer_size;
        const size_t len = sentinel - begin;

        memcpy(perf_data + perf_data_length, begin, len);
        perf_data_length += len;

        memcpy(perf_data + perf_data_length, base, e->size - len);
        perf_data_length += e->size - len;
      }
      else
      {
        memcpy(perf_data + perf_data_length, base, e->size);
        perf_data_length += e->size;
      }
      record->time = time;
    }
    tail += e->size;
  }

  barrier();
  page->data_tail = tail;
  g_perf_data.perf_data_length = perf_data_length;
}

static void perf_event_handler(int signum, siginfo_t *info, void *ucontext)
{
  if (info->si_code == POLL_IN)
  {
    read_perf_data();
  }
}

void worker()
{
  auto start = std::chrono::high_resolution_clock::now();
  int s = 0;
  for (int i = 0; i < 100000000; i++)
  {
    s += rand();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  printf("s: %d, elapsed milliseconds: %ld\n", s, elapsed);
}

int main()
{
  if (access("/proc/sys/kernel/perf_event_paranoid", F_OK) == -1)
  {
    return -1;
  }

  struct sigaction sa;
  memset(&sa, 0, sizeof(struct sigaction));
  sa.sa_sigaction = perf_event_handler;
  sa.sa_flags = SA_SIGINFO;
  int ret = sigaction(SIGIO, &sa, NULL);
  assert(ret != -1);

  struct perf_event_attr attr;
  memset(&attr, 0, sizeof(attr));
  attr.type = PERF_TYPE_HARDWARE;
  attr.sample_type = PERF_SAMPLE_TIME;
  attr.size = sizeof(attr);
  attr.config = PERF_COUNT_HW_CPU_CYCLES;
  //attr.config = PERF_COUNT_HW_INSTRUCTIONS;
  attr.sample_period = 10000000ULL;
  attr.exclude_kernel = 1;
  attr.exclude_hv = 1;
  attr.disabled = 1;

  int fd = perf_event_open(&attr, 0, -1, -1, 0);
  assert(fd !=0);

  g_perf_data.fd = fd;
  fcntl(fd, F_SETFL, O_RDWR | O_NONBLOCK | O_ASYNC);
  fcntl(fd, F_SETSIG, SIGIO);
  fcntl(fd, F_SETOWN, getpid());

  const size_t pages_size = perf_mmap_size();
  void *page = mmap(NULL, pages_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  assert(page != MAP_FAILED);

  g_perf_data.pages_size = pages_size;
  g_perf_data.page = reinterpret_cast<perf_event_mmap_page *>(page);
  g_perf_data.data_offset = get_page_size();
  g_perf_data.data_size = pages_size - g_perf_data.data_offset;

  void *perf_data =  mmap(NULL, PERF_MMAP_DATA_SIZE, 
    PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE | MAP_POPULATE, -1, 0);
  assert(perf_data != MAP_FAILED);

  g_perf_data.perf_data = (uint8_t*)perf_data;
  g_perf_data.perf_data_length = 0;

  uint64_t time = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  ioctl(fd, PERF_EVENT_IOC_ENABLE);
  worker();
  ioctl(fd, PERF_EVENT_IOC_DISABLE);

  const perf_record_time* r = (const perf_record_time*)g_perf_data.perf_data;
  const perf_record_time* e = (const perf_record_time*)(g_perf_data.perf_data + g_perf_data.perf_data_length);
  
  int sample_count = 0;
  for (; r < e; r++)
  {
    printf("%d, %ld\n", r->header.size, (r->time - time) / (1000 * 1000));
    sample_count++;
  }
  printf("sample_count=%d\n", sample_count);
  return 0;
}
