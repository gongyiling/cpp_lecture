#include <iostream>
#include <linux/perf_event.h>
#include <sched.h>


unsigned long rdpmc_instructions()
{

	unsigned int a, d, c;
	c = (1 << 30) + 2;
	__asm__ volatile ("rdpmc": "=a"(a), "=d"(d): "c"(c));
	return ((unsigned long)a | ((unsigned long)d << 32));
}

int main()
{
	cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    sched_setaffinity(0, sizeof(set), &set);   
	std::cout <<rdpmc_instructions() << std::endl;
	return 0;
}

