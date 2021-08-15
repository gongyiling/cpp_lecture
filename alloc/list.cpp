#include <chrono>
#include <stdlib.h>
#include <sched.h>
#include <algorithm>
#include <iostream>
#include <assert.h>

struct node
{
	int32_t next;
	int32_t x;
	node& operator=(const node&) = delete;
};

static const int N = 1024 * 1024 * 10;
static const int M = 1024 / 100;
static node f[N];
static int32_t pf[N];

void swap_list_element(node& a, node& b, node* array, int32_t* prev)
{
	const int32_t ai = &a - array;
	const int32_t bi = &b - array;
	const int32_t pai = prev[ai];
	const int32_t pbi = prev[bi];
	const int32_t nai = array[ai].next;
	const int32_t nbi = array[bi].next;

	// fix prev.next
	array[pai].next = bi;			
	array[pbi].next = ai;			

	// fix next.prev
	prev[nai] = bi;
	prev[nbi] = ai;

	// fix a and b.
	std::swap(a.next, b.next);
	std::swap(prev[ai], prev[bi]);
}

void swap(node& a, node& b)
{
	swap_list_element(a, b, f, pf);
}

void check_list(node* array, int32_t* prev, int N)
{
	int32_t p = 0;
	for (int i = 0; i < N; i++)
	{
		assert(prev[array[p].next] == p);
		assert(array[prev[p]].next == p);
		p = array[p].next;
	}
	std::cout << p << '\t' << std::endl;
}

int32_t sum(const node* f, int N)
{
	int32_t s = 0;
	int32_t p = 0;
	for (int i = 0; i < N; i++)
	{
		s += f[p].x;
		p = f[p].next;
	}
	return s;
}

void bind_to_cpu(int index)
{
	cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(index, &set);
    sched_setaffinity(index, sizeof(set), &set);   
}

void init_data()
{
	for (int i = 0; i < N; i++)
	{
		f[i].x = i;
		f[i].next = i + 1;	
		pf[i] = i - 1;
	}
	f[N - 1].next = 0;
	pf[0] = N - 1;	
}

int main()
{
	bind_to_cpu(0);

	for (int step = 256; step < N / 4; step += 256)
	{
		init_data();
		for (int i = 0; i < N - step; i += step)
		{
			std::random_shuffle(f + i, f + i + step);
		}
		int32_t s = 0;
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < M; i++)
		{
			s += sum(f, N);
		}
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << '\t' << s << std::endl;
	}

	return 0;
}

