#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <sched.h>

#define CACHELINE_SIZE 64
struct Node
{
	Node* next;
	char paddings[CACHELINE_SIZE - sizeof(Node*)];
};

#define N1(node) node=node->next;
#define N2(node) N1(node);N1(node);
#define N4(node) N2(node);N2(node);
#define N8(node) N4(node);N4(node);
#define N16(node) N8(node);N8(node);
#define N32(node) N16(node);N16(node);
#define N64(node) N32(node);N32(node);
#define N128(node) N64(node);N64(node);
#define N256(node) N128(node);N128(node);
#define N512(node) N256(node);N256(node);
#define N1024(node) N512(node);N512(node);

const Node* test(int T, const Node* c, int size)
{
	auto start = std::chrono::high_resolution_clock::now();
	const Node* node = NULL;
	const int M = T / size;
	for (int i = 0; i < M; i++)
	{
		node = c;
		const int s = size / 64;
		for (int j = 0; j < s; j++)
		{
			N64(node);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() ;
	std::cout << "elapsed nanoseconds per elements: " << elapsed / T << std::endl;
	std::cerr << elapsed / T << std::endl;
	return node;
}

int main(int argc, char* argv[])
{
	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET(0, &set);
	sched_setaffinity(0, sizeof(set), &set); 	
	const int N = 1024 * 1024 * 16;
	std::vector<Node> va;
	va.resize(N);
	for (int i = 0; i < N - 1; i++)
	{
		va[i].next = &(va[i + 1]);
	}
	va[N - 1].next = &va[0];
	const int T = 1000000;
	const int begin_kb = atoi(argv[1]);
	const int end_kb = atoi(argv[2]);
	std::cout << "begin_kb: " << begin_kb << '\t' << "end_kb: " << end_kb << std::endl;
	const Node* node = NULL;
	for (int i = begin_kb; i < end_kb; i += 4)
	{
		std::cout << "test kb: " << i << std::endl;
		std::cerr << i << '\t';
		node = test(T, &va[0], i * 1024 / sizeof(Node));
	}
	std::cout << node << '\t' <<  &va[0] << std::endl;
	return 0;
}

