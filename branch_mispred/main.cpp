#include <vector>
#include <iostream>
#include <chrono>
#include <chrono>
#include <string.h>
#include <time.h>
#include <array>

typedef std::array<bool, 4096 * 8> bits_t;

__attribute__((noinline)) static int sum(const bits_t& bits)
{
	int sum = 0;
	for (char b: bits)
	{
		if (b)
		{
			sum++;
		}
		asm volatile("": :"r,m"(sum): "memory");
	}
	return sum;
}

static bits_t gen_bits(int NP, int P, bool random)
{
	bits_t bits;
	std::vector<char> patterns;
	patterns.resize(NP);
	for (size_t i = 0; i < NP; i++)
	{
		if (random)
		{
			patterns[i] = rand() & 1;
		}
		else
		{
			if (P & (1 << i))
			{
				patterns[i] = true;
			}
			else
			{
				patterns[i] = false;
			}
		}
		//std::cout << (bool)patterns[i];
	}
	//std::cout << '\n';
	for (size_t i = 0; i <= bits.size() - patterns.size(); i += patterns.size())
	{
		memcpy(&bits[i], &patterns[0], patterns.size());
	}
	return bits;
}

void test(int NP)
{
	int N = 0;
	bool random = false;
	if (NP > 4)
	{
		N = 1 << 4;
		random = true;
	}
	else
	{
		N = 1 << NP;
		random = false;
	}
	int sum_milliseconds = 0;
	for (int P = 0; P < N; P++)
	{
		bits_t bits = gen_bits(NP, P, random);
		const int M = 10000;
		int s = 0;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < M; i++)
		{
			s += sum(bits);
		}	
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		//std::cout << "elapsed: " << elapsed << " milliseconds" << std::endl; 
		sum_milliseconds += elapsed;
	}
	std::cout << NP <<" sum: " << sum_milliseconds / N << " milliseconds" << std::endl; 
}

int main()
{
	srand(time(NULL));
	for (int i = 1; i < 32; i++)
	{
		const int ni = i;
		test(ni);
	}
	return 0;
}
