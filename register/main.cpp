#include <stdlib.h>
#include <iostream>
#include <chrono>

static const int N = 1024 * 1024 * 1024;

int test_register()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = rand();
	int f = rand();
	int g = rand();
	int h = rand();
	for (int i = 0; i < N; i++)
	{
		a += e;
		b += f;
		c += g;
		d += h;
	}
	return a + b + c + d;
}

int test_memory()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	volatile int e = rand();
	volatile int f = rand();
	volatile int g = rand();
	volatile int h = rand();
	for (int i = 0; i < N; i++)
	{
		a += e;
		b += f;
		c += g;
		d += h;
	}
	return a + b + c + d;
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	test_register();
	auto end_register = std::chrono::high_resolution_clock::now();
	test_memory();
	auto end_all = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_register - start).count() << std::endl;
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_all - end_register).count() << std::endl;
	return 0;
}

