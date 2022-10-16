#include <chrono>
#include <iostream>
#include <vector>
#include <sched.h>

void bind_to_cpu(int index)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(index, &set);
    sched_setaffinity(index, sizeof(set), &set);
}

template <typename data_t, int j>
struct unroll
{
	static void do_unroll(data_t* totals, const data_t* a)
	{
		totals[j] += a[j];
		unroll<data_t, j - 1>::do_unroll(totals, a);
	}
};

template <typename data_t>
struct unroll<data_t, -1>
{
	static void do_unroll(data_t* totals, const data_t* a)
	{
	}
};

template <typename data_t, int N>
__attribute__((noinline)) data_t sum(const data_t* a, int count)
{
	data_t totals[N] ={0};
	for (int i = 0; i < count; i += N)
	{
		unroll<data_t, N - 1>::do_unroll(totals, a + i);
	}	

	data_t total = 0;
	for (int j = 0; j < N; j++)
	{
		total += totals[j];
	}
	return total;
}

template <typename data_t, int N>
void test(const std::vector<data_t>& nums)
{
	auto start = std::chrono::high_resolution_clock::now();
	data_t s = 0;
	for (int i = 0; i < 1024 * 256; i++)
	{
		s += sum<data_t, N>(nums.data(), nums.size());
		asm volatile("": :"r,m"(s): "memory");

	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << s << '\t' << N << "\telapsed : " << elapsed << std::endl;
}

int main()
{
	bind_to_cpu(0);
	const int N = 1024 * 4;
	std::vector<float> numsf(N);
	std::vector<int> numsi(N);
	for (int i = 0; i < N;i++)
	{
		numsi[i] = numsf[i] = rand();
	}
	test<int, 1>(numsi);
	test<float, 1>(numsf);
	std::cout << std::endl;

	test<int, 2>(numsi);
	test<float, 2>(numsf);
	std::cout << std::endl;

	test<int, 3>(numsi);
	test<float, 3>(numsf);
	std::cout << std::endl;

	test<int, 4>(numsi);
	test<float, 4>(numsf);
	std::cout << std::endl;

	test<int, 8>(numsi);
	test<float, 8>(numsf);
	std::cout << std::endl;

	return 0;
}

