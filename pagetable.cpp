#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>

struct Page
{
	uint64_t address;
	uint64_t entry[512]; 	
};

uint64_t get_phys_address(uint64_t entry)
{
	static const uint64_t mask = (1LL << 63) | ((1 << 12) - 1);
	return entry & ~mask;
}

bool writable(uint64_t entry)
{
	return (entry & (1 << 1)) != 0;
}

bool executable(uint64_t entry)
{
	return (entry & (1LL << 63)) == 0;
}

bool user_mode(uint64_t entry)
{
	return (entry & (1 << 2)) != 0;
}

void print_entry(FILE* fp, int level, uint64_t entry, uint64_t virtual_address)
{
	fprintf(fp, "%d\t0x%016lx\t0x%016lx\t%d\t%d\t%d\n", level, get_phys_address(entry), virtual_address, writable(entry), executable(entry), user_mode(entry));
}

void dump(FILE* fp, const Page*& page, int level, uint64_t virtual_address)
{
	const Page* cur_page = page++;
	for (int i = 0; i < 512; i++)
	{
		const uint64_t entry = cur_page->entry[i];
		const uint64_t child_virtual_address = (virtual_address << 9) | i;
		if (level > 0)
		{
			if (entry & 1)
			{
				if (!(entry&(1<<7)))
				{
					dump(fp, page, level - 1, child_virtual_address);
				}
				else
				{
					print_entry(fp, level, entry, child_virtual_address << (level * 9 + 12));
				}
			}
		}
		else
		{
			
			if (entry)
			{
				print_entry(fp, level, entry, child_virtual_address << 12);
			}
		}
	}
}

void dump_pagetable(FILE* fp)
{
	std::ifstream ifs("/proc/page_table_3", std::ios::binary);
	if (!ifs)
	{
		return;
	}
	std::string content((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	const Page* page = (const Page*)&content[0];
	const Page* end_page = (const Page*)(&content[0] + content.length());
	dump(fp, page, 3, 0);
	std::cout << (const void*)end_page << '\t' <<  (const void*)page << std::endl;
	std::flush(std::cout);
}

int main()
{
	const int N = 1024 * 1024 * 8;
	const bool hugetable = true;
	const bool do_fork = false;

	char* m = (char*)mmap(NULL, N, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED | (hugetable ? MAP_HUGETLB: 0), -1, 0); 
			std::cout << *m << std::endl;
	FILE* fp = NULL;
	if (do_fork)
	{
		pid_t pid = fork();	
		if (pid == 0)
		{
			fp = fopen("/home/fractal/lecture/child.log", "w");
		}
		else
		{
			fp = fopen("/home/fractal/lecture/father.log", "w");
		}
	}
	else
	{
		fp = fopen("/home/fractal/lecture/father.log", "w");
	}

	fprintf(fp, "mmap address: %p\n", m);
	dump_pagetable(fp);

	fclose(fp);
	while (true)
	{
		usleep(10000);
	}
	return 0;
}
