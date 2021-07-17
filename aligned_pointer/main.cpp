#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <memory>

struct A
{
	A():a(0), b(0), c(0), d(0){}
	int64_t a;
	int64_t b;
	int64_t c;
	int64_t d;
};

int main()
{
	char* buffer = (char*)__builtin_assume_aligned((char*)malloc(64), 32);
	A* a = new(buffer)A;
	asm volatile("": :"r,m"(a): "memory");
	return 0;
}
