#include <iostream>
#include <vector>
#include <sched.h>
#include <chrono>
#include <unistd.h>

int div(const std::vector<int>& v, const int d, int M)
{
	int s = 0;
	for (int i = 0; i < M; i ++)
	{
		for (auto&& k: v)	
		{	
			s += k / d;
		}
	}
	return s;
}

void set_affinity(pid_t pid, int cpu)
{
	cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(cpu, &set);
   	int ret = sched_setaffinity(pid, sizeof(set), &set);   
	if (ret != 0)
	{
		fprintf(stderr, "sched_setaffinity failed\n");
	}
}

int main(int argc, char* argv[1])
{
	const int M = 1024 * 1024;
	const bool child_run_hyper_thread = atoi(argv[1]);
	std::vector<int> v(1024);
	const int d = rand();
	for (auto&& k: v)
	{
		k = rand();
	}
	pid_t pid = fork();
	if (pid == 0)
	{
		set_affinity(0, 0);
	}
	else
	{
		set_affinity(0, child_run_hyper_thread ? 1: 2);
	}
	auto start = std::chrono::high_resolution_clock::now();
	int s = div(v, d, M);
	auto end = std::chrono::high_resolution_clock::now();
	printf("sum: %d, div elapsed milliseconds=%ld\n", 
		s, std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	return 0;
}

