#include <iostream>
#include <algorithm>
#include <queue>
#include <chrono>

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

int main()
{
	const int kary = 8;
	// 4^10 - 1
	const int N = (1 << (2 * 12)) - 1;
	std::vector<int> data, tree;
	data.resize(N);
	tree.resize(N);
	for (int i = 0; i < N; i++)
	{
		data[i] = i;
	}
	int* p = tree.data();
	build_tree(data.data(), N, p, kary);
	std::random_shuffle(data.begin(), data.end());
	int s = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		s += *find<kary>(tree.data(), 0, data[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	int n = N;
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() <<  std::endl;
	std::cout << s << '\t' <<  n * ((n - 1) / 2) <<  std::endl;
	return 0;
}

