#include <iostream>


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

typedef term<factor> term2_t;
typedef term<term2_t> term3_t;
template <>
int calc<term2_t>(term3_t t)
{
	if (t.b.f == t.a.b.f)
	{
		std::cout << "transformed" << std::endl;
		return 2 * t.b.f + t.a.a.f;
	}
	else
	{
		std::cout << "not transformed" << std::endl;
		return t.b.f + t.a.b.f + t.a.a.f;
	}
}

int main()
{
	factor a{1}, b{2};
	auto t = a + b + b;
	std::cout << calc(t) << std::endl;
	return 0;
}

