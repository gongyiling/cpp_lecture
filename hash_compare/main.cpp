#include "fhash_table.h"
#include "absl/container/flat_hash_map.h"
#include <map>
#include <stdlib.h>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <chrono>
#include <cmath>

template <bool remove_duplicated>
std::vector<int32_t> gen_random_data(int32_t N)
{
	std::vector<int32_t> data;
	data.reserve(N);
	std::unordered_set<int32_t> numbers;
	for (int32_t i = 0; i < N; i++)
	{
		int32_t r = rand();
		if (remove_duplicated)
		{
			if (numbers.insert(r).second)
			{
				data.push_back(r);
			}
		}
		else
		{
			data.push_back(r);
		}
	}
	return data;
}

static void test_find_success()
{
	for (int32_t i = 1; i < 15; i++)
	{
		const int32_t N = std::pow(3, i);
		std::cout << "N = " << N << std::endl;
		std::vector<int32_t> data = gen_random_data<false>(N);
		{
			std::unordered_map<int64_t, int64_t> m;
			for (int32_t i : data)
			{
				m.emplace(i, i);
			}
			std::vector<int32_t> shuffled_data = data;
			std::random_shuffle(shuffled_data.begin(), shuffled_data.end());
			int64_t sum = 0;
			auto start = std::chrono::high_resolution_clock::now();
			for (int32_t i = 0; i < 100000000 / N; i++)
			{
				for (int32_t i : shuffled_data)
				{
					sum += m.find(i)->second;
				}
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			std::cout << "std::unordered_map, elapsed milliseconds: " << elapsed << " sum: " << sum << std::endl;
		}
		{
			absl::flat_hash_map<int64_t, int64_t> m;
			for (int32_t i : data)
			{
				m.emplace(i, i);
			}
			std::vector<int32_t> shuffled_data = data;
			std::random_shuffle(shuffled_data.begin(), shuffled_data.end());
			int64_t sum = 0;
			auto start = std::chrono::high_resolution_clock::now();
			for (int32_t i = 0; i < 100000000 / N; i++)
			{
				for (int32_t i : shuffled_data)
				{
					sum += m.find(i)->second;
				}
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			std::cout << "absl::flat_hash_map, elapsed milliseconds: " << elapsed << " sum: " << sum << std::endl;
		}
		{
			fhash_table<int64_t, int64_t> m;
			for (int32_t i : data)
			{
				m.insert(i, i);
			}
			std::vector<int32_t> shuffled_data = data;
			std::random_shuffle(shuffled_data.begin(), shuffled_data.end());
			auto start = std::chrono::high_resolution_clock::now();
			int64_t sum = 0;
			for (int32_t i = 0; i < 100000000 / N; i++)
			{
				for (int32_t i : shuffled_data)
				{
					sum += *m.find(i);
				}
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			std::cout << "fhash_table, elapsed milliseconds: " << elapsed << " sum: " << sum << " load_factor: " << m.load_factor() << std::endl;
		}
	}
}

static void perf_test()
{
	test_find_success();
}

int main()
{
	//functional_test();
	perf_test();
	return 0;
}
