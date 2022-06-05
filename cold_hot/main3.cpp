#include <chrono>
#include <iostream>
#include <array>
#include <stdint.h>
#include <stdlib.h>
#include <sched.h>

struct data_cold
{
	char padding[64 - sizeof(int32_t)];
	int32_t d1;
	char padding2[64 - sizeof(int32_t)];
};

struct data
{
	int32_t d;
	data_cold* cold;
};

void bind_to_cpu(int index)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(index, &set);
    sched_setaffinity(index, sizeof(set), &set);
}

static std::array<data*, 1014 * 1024> datas;
static std::array<data, 1014 * 1024> data_pool;
static std::array<data_cold, 1014 * 1024> data_cold_pool;

int main()
{
	bind_to_cpu(0);
	for (int i = 0; i < datas.size(); i++)
	{
		datas[i] = &data_pool[i];
		datas[i]->cold = &data_cold_pool[i];
		datas[i]->d = rand();
		datas[i]->cold->d1 = rand();
	}

	const int N = 100;
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < datas.size(); j++)
		{
			const data& d = *datas[j];
			sum += d.d;
			if (j % 128 == 0)
			{
				sum += d.cold->d1;
				asm volatile("": :"r,m"(sum): "memory");
			}
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::cout << "elabsed: " << elapsed << " milliseconds, sum: " << sum << std::endl; 
	return 0;
}

