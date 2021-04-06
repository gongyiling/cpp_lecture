#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <sched.h>

#define CACHELINE_SIZE 64
int test(int M, const std::vector<int>& c)
{
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		for (size_t j = 0; j < c.size(); j+= CACHELINE_SIZE / sizeof(int))
		{
			sum += c[j];
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "elapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return sum;
}

int main()
{
	cpu_set_t set;
        CPU_ZERO(&set);
        CPU_SET(0, &set);
        sched_setaffinity(0, sizeof(set), &set);

	const int N = 1024 * 1024 * 16;
	std::vector<int> va;
	for (int i = 0; i < N; i++)
	{
		va.push_back(rand());
	}
	const int M = 100;
	int sum = test(M, va);
	std::cout << sum << std::endl;
	return 0;
}

