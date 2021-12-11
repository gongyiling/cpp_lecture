#include <stdio.h>
#include <thread>
#include <asm/prctl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <immintrin.h>

static unsigned long readfsbase()
{
	unsigned long addr;
	syscall(SYS_arch_prctl, ARCH_GET_FS, &addr);
	return addr;
}

static void foo()
{
	thread_local int i = 0;
	i++;
	printf("i=%d, tid=%d, fs=%lx\n", i, gettid(), readfsbase());
}

int main()
{
	foo();
	foo();

	std::thread t([](){
		foo();
		foo();
		foo();
	});

	t.join();
	return 0;
}

