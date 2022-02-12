#include <iostream>
#include <stdint.h>

struct request
{
	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
};

//typedef const char* char_cp_t;
typedef const char* __restrict char_cp_t;

static void parse(char_cp_t  data, request& req)
{
	req.a = *(const uint32_t*)data; data += sizeof(uint32_t);
	req.b = *(const uint32_t*)data; data += sizeof(uint32_t);
	req.c = *(const uint32_t*)data; data += sizeof(uint32_t);
	req.d = *(const uint32_t*)data; data += sizeof(uint32_t);
}

static __attribute__((noinline)) void test(const char* data, request& req)
{
	const int N = 1000000000;
	for (int i = 0; i < N; i++)
	{
		parse(data, req);
		asm volatile("": :"r,m"(req): "memory");
	}
}

int main()
{
	char data[128];
	for (int i = 0; i < 128; i++)
	{
		data[i] = rand();
	}
	request req;
	test(data, req);
	return 0;
}

