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

	template <typename succ_op_t, typename failed_op_t>
	decltype(auto) find_index(int key, succ_op_t succ_op, failed_op_t failed_op) const
	{
		if (key >= 0 && key < N)
		{
			return succ_op(m_data[key]); 
		}
		else
		{
			return failed_op();
		}
	}

	__attribute__((noinline)) const int* find(int key) const
	{
		return find_index(key, 
			[this](int index){return &m_data[index];},
			[](){return (const int*)nullptr;}
		);
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
	printf("elapsed %ld milliseconds\n", elapsed);
	return 0;
}

