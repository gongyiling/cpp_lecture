#include <iostream>

struct factor
{
	int f;
};

struct term
{

	factor a;
	factor b;
};

term operator+(factor a, factor b)
{
	return term{a, b};
}

int calc(term t)
{
	return t.a.f + t.b.f;
}

int main()
{
	factor a{1}, b{2};
	term t = a + b;
	std::cout << calc(t) << std::endl;
	return 0;
}

