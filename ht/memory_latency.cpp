#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <sched.h>
#include <unistd.h>

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

const Node* test(int M, const std::vector<Node>& c)
{
	const Node* node = &c[0];
	for (int i = 0; i < M; i++)
	{
		const size_t s = c.size() / 1024;
		for (int j = 0; j < s; j++)
		{
			N1024(node);
		}
	}
	return node;
}

void set_affinity(pid_t pid, int cpu)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(cpu, &set);
    int ret = sched_setaffinity(pid, sizeof(set), &set);   
    if (ret != 0)
    {   
        fprintf(stderr, "sched_setaffinity failed\n");
    }   
}

int main(int argc, char* argv[])
{
	const int N = 1024 * 1024 * 16;
	std::vector<Node> va;
	va.resize(N);
	for (int i = 0; i < N - 1; i++)
	{
		va[i].next = &(va[i + 1]);
	}
	va[N - 1].next = &va[0];
	const int M = 10;
	const bool child_run_hyper_thread = true;
	pid_t pid = fork();
    if (pid == 0)
    {   
        set_affinity(0, 0); 
    }   
    else
    {   
        set_affinity(0, child_run_hyper_thread ? 1: 2); 
    }   
    auto start = std::chrono::high_resolution_clock::now();
	const Node* node = test(M, va);
    auto end = std::chrono::high_resolution_clock::now();
    printf("%p,%p, memory latency elapsed milliseconds=%ld\n", 
		node, &node[0],
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	return 0;
}

