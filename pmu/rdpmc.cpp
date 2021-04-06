#include <iostream>
#include <vector>
#include <sched.h>

uint64_t rdpmc(int index, int fixed)
{

	uint32_t a, d, c;
	c = (fixed << 30) + index;
	__asm__ volatile ("rdpmc": "=a"(a), "=d"(d): "c"(c));
	return ((uint64_t)a | ((uint64_t)d << 32));
}

int sum(const std::vector<int>& v, int M)
{
	int s = 0;
	for (int i = 0; i < M; i++)
	{
		for (auto k: v)
		{
			s += k;
		}
	}
	return s;
}

int main()
{
	cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    sched_setaffinity(0, sizeof(set), &set);   
	std::vector<int> v(1024);
	const int M = 1024;
	for (auto&& k: v)
	{
		k = rand();
	}
	const uint64_t start_instruction_retired = rdpmc(0, 0);
	const uint64_t start_cycles = rdpmc(1, 0);
	const int s = sum(v, M);
	const uint64_t end_instruction_retired = rdpmc(0, 0);
	const uint64_t end_cycles = rdpmc(1, 0);
	const uint64_t instruction_retired = end_instruction_retired - start_instruction_retired;
	const uint64_t cycles = end_cycles - start_cycles;
	printf("sum: %d, instruction retired: %ld, cycles: %ld, instructions per cycle: %f\n", 
		s, instruction_retired, cycles, instruction_retired/float(cycles));
	return 0;
}

