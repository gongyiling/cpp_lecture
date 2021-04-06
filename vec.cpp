#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int test(int M, const std::vector<int>& c)
{
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		for (auto v: c)
		{
			__asm volatile("#LLVM-MCA-BEGIN test");
			sum += v;
		}
		__asm volatile("#LLVM-MCA-END");
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "elapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return sum;
}

int test(int M, const std::list<int>& c)
{
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		for (auto v: c)
		{
			__asm volatile("#LLVM-MCA-BEGIN test");
			sum += v;
		}
		__asm volatile("#LLVM-MCA-END");
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "elapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return sum;
}

int main()
{
	const int N = 10000;
	std::vector<int> va;
	std::list<int> la;
	for (int i = 0; i < N; i++)
	{
		va.push_back(rand());
		la.push_back(rand());
	}
	const int M = 100000;
	int sum = test(M, va);
	sum += test(M, la);
	std::cout << sum << std::endl;
	return 0;
}

