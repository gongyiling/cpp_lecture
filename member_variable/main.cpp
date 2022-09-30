#include <chrono>
#include <iostream>
#include <vector>

struct A
{
	int m_total;
	__attribute__((noinline)) void sum1(const int* a, int count)
	{
		m_total = 0;
		for (int i = 0; i < count; i++)
		{
			m_total += a[i];
		}	
	}
	__attribute__((noinline)) void sum2(const int* a, int count)
	{
		int total = 0;
		for (int i = 0; i < count; i++)
		{
			total += a[i];
		}	
		m_total = total;
	}

};

int main()
{
	A a;
	const int N = 1024*1024*100;
	std::vector<int> nums(N);
	for (int i = 0; i < N;i++)
	{
		nums[i] = rand();
	}
	auto start = std::chrono::high_resolution_clock::now();
	a.sum1(nums.data(), N);
	auto end1 = std::chrono::high_resolution_clock::now();
	a.sum2(nums.data(), N);
	auto end2 = std::chrono::high_resolution_clock::now();
	auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start).count();
	auto elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - end1).count();
	std::cout <<"elapsed1: " << elapsed1 << std::endl;
	std::cout <<"elapsed2: " << elapsed2 << std::endl;
	return 0;
}

