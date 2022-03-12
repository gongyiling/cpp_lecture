#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <stdlib.h>

static std::array<int, 1024*1024 * 10> vips;

int main()
{
	for (int i = 0; i < vips.size(); i++)
	{
		if (rand() % 10 == 0)
		{
			vips[i] = rand() % 8;
		}
		else
		{
			vips[i] = 0;
		}
	} 

	auto start = std::chrono::high_resolution_clock::now();

	{
		auto end_vip0 = std::partition(vips.begin(), vips.end(), [](int vip){return vip == 0;});
		std::sort(end_vip0, vips.end());	
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "is sorted: " << std::is_sorted(vips.begin(), vips.end()) << ", elapsed: " << elapsed << " milliseconds." << std::endl;
	return 0;
}

