#include <iostream>
#include <algorithm>
#include <queue>
#include <chrono>
#include <sched.h>

struct node
{
	const int* b;
	int N;
};

void build_tree(const int* b, int N, int* & out, int kary)
{
	std::queue<node> q;
	q.push(node{b, N});
	while (!q.empty())
	{
		node nd = q.front(); q.pop();
		const int count = (nd.N - kary + 1) / kary;
		for (int i = 0; i < kary; i++)
		{
			if (i > 0)
			{
				*out++ = *nd.b;
				nd.b++;
			}
			if (count > 0)
			{
				q.push(node{nd.b, count});
				nd.b += count;
			}
		}			
	}
}

template <int kary>
const int* find(const int* b, int index, int value)
{
	const int* root = b + index;
	int child_base_index = kary * index + kary - 1;
	for (int i = 0; i < kary - 1; i++)
	{
		if (root[i] == value)
		{
			return &root[i];
		}
		else if (root[i] > value)
		{
			return find<kary>(b, child_base_index, value);
		}
		child_base_index += kary - 1;
	}
	return find<kary>(b, child_base_index, value);
}

void bind_to_cpu(int index)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(index, &set);
    sched_setaffinity(index, sizeof(set), &set);   
}

int main()
{
	bind_to_cpu(0);
	const int kary = 1;
	// 4^12 - 1
	const int N = (1 << (2 * 12)) - 1;
	std::vector<int> data, tree;
	data.resize(N);
	tree.resize(N);
	for (int i = 0; i < N; i++)
	{
		data[i] = i;
	}
	if (kary == 1)
	{
		tree = data;
	}
	else
	{
		int* p = tree.data();
		build_tree(data.data(), N, p, kary);
	}
	std::random_shuffle(data.begin(), data.end());
	int s = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		if (kary == 1)
		{
			int d = data[i];
			s += *std::lower_bound(tree.begin(), tree.end(), d);
		}
		else
		{
			int d = data[i];
			s += *find<kary>(tree.data(), 0, d);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	int n = N;
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() <<  std::endl;
	std::cout << s << '\t' <<  n * ((n - 1) / 2) <<  std::endl;
	return 0;
}

