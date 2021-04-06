#include <iostream>

// term = factor factor | term factor
struct factor
{
	int f;
};

template <typename term_or_factor_t>
struct term
{
	term_or_factor_t a;
	factor b;
};

template <typename term_or_factor_t>
term<term_or_factor_t> operator+(term_or_factor_t a, factor b)
{
	return term<term_or_factor_t>{a, b};
}

template <typename term_t>
int calc(term<term_t> t)
{
	return calc(t.a) + t.b.f;
}

template <>
int calc<factor>(term<factor> t)
{
	return t.a.f + t.b.f;
}

int main()
{
	factor a{1}, b{2};
	auto t = a + b + b;
	//b + b => 2 * b
	std::cout << calc(t) << std::endl;
	return 0;
}

