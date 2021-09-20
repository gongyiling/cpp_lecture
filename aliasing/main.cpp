#include <iostream>
#include <stdint.h>

__attribute__((noinline)) void foo(int32_t& i, uint32_t& __restrict ui)
{
	i = ui + 1;
	i = ui + 1;
} 

__attribute__((noinline)) void bar(int32_t& i, int64_t& i64)
{
	i = i64 + 1;
	i = i64 + 1;
} 

int main()
{
	uint32_t ui = 1;
	int32_t i = 1;
	int64_t i64 = 1;

	foo(i, ui);
	bar(i, i64);

	ui = 1;
	i = 1;
	i64 = 1;
	int32_t* pui = reinterpret_cast<int32_t*>(&ui);
	foo(*pui, ui);
	std::cout << ui << std::endl;

	ui = 1;
	i = 1;
	i64 = 1;
	int32_t* pi64 = reinterpret_cast<int32_t*>(&i64);
	bar(*pi64, i64);
	std::cout << i64 << std::endl;

	return 0;
}

