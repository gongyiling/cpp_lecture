#include <stdio.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include <chrono>

constexpr int N = 128;

class hash_table
{
public:
	hash_table()
	{
		for (int i = 0; i < N; i++)
		{
			m_data[i] = rand() % N;
		}
	}

	int find_index(int key) const
	{
		if (key >= 0 && key < N)
		{
			return m_data[key]; 
		}
		else
		{
			return -1;
		}
	}

	__attribute__((noinline)) const int* find(int key) const
	{
		int index = find_index(key);
		if (index == -1)
		{
			return nullptr;
		}
		else
		{
			return &m_data[index];
		}
	}	

private:

	std::array<int, N> m_data;
};

int main()
{
	hash_table h;
	std::array<int, N> keys;
	for (int i = 0; i < keys.size(); i++)
	{
		keys[i] = rand() % (2 * N);
	}
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++)
	{
		for (int j = 0; j < keys.size(); j++)
		{
			const int* p = h.find(keys[j]);
			asm volatile("": :"r,m"(p): "memory");
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	printf("sum=%d, elapsed %ld milliseconds\n", sum, elapsed);
	return 0;
}

