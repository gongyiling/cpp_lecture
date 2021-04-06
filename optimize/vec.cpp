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
			sum += v;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "vector elapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return sum;
}

int test(int M, const std::vector<int*>& c)
{
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		for (auto v: c)
		{
			sum += *v;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "vector pointer elapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
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
			sum += v;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "list elapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return sum;
}

int main()
{
	const int N = 10000;
	std::vector<int*> va;
	std::vector<int> vva;
	std::list<int> la;
	for (int i = 0; i < N; i++)
	{
		vva.push_back(rand());
		va.push_back(new int(rand()));
		la.push_back(rand());
	}
	const int M = 100000;
	int sum = test(M, vva);
	sum += test(M, va);
	sum += test(M, la);
	std::cout << sum << std::endl;
	return 0;
}

