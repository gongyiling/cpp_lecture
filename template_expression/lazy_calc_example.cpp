#include <iostream>

int very_heavy_calc()
{
	return 42;
}

typedef int (*func_t)();

int bad(int a, int b)
{
	return a? b: 0;
}

int good(int a,  func_t b)
{
	return a? b(): 0;
}

int main()
{
	int ret1 = bad(0, very_heavy_calc());
	int ret2 = good(0, very_heavy_calc);
	return 0;
}

