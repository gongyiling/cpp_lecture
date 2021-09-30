#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <sched.h>

#define NOOP asm("nop");
#define NOOP2 NOOP NOOP
#define NOOP4 NOOP2 NOOP2
#define NOOP8 NOOP4 NOOP4
#define NOOP16 NOOP8 NOOP8

__attribute__((noinline)) void foo(int r)
{
	if (r != 0) [[likely]]
	{
		NOOP;
	}
	else
	{
		NOOP16;
	}
}

void bind_to_cpu(int index)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(index, &set);
    sched_setaffinity(index, sizeof(set), &set);   
}

int main()
{
	bind_to_cpu(0);
	const int N = 1024 * 1024 * 1000;
	const int r = rand();
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		foo(r);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return 0;
}

