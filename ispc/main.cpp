#include <chrono>
#include <iostream>
#include <vector>
#include "sum_ispc.h"

__attribute__((noinline)) int sum(const int* a, int count)
{
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += a[i];
	}	
	return total;
}


int main()
{
	const int N = 1024*1024*100;
	std::vector<int> nums(N);
	for (int i = 0; i < N;i++)
	{
		nums[i] = rand();
	}
	auto start = std::chrono::high_resolution_clock::now();
	int s = sum(nums.data(), N);
	auto end1 = std::chrono::high_resolution_clock::now();
	int s2 = ispc::sum2(nums.data(), N);
	auto end2 = std::chrono::high_resolution_clock::now();
	auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start).count();
	auto elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - end1).count();
	std::cout <<s << "\telapsed1: " << elapsed1 << std::endl;
	std::cout <<s2 << "\telapsed2: " << elapsed2 << std::endl;
	return 0;
}

