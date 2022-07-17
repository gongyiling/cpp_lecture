#include <iostream>

struct FSMStatBase
{
	FSMStatBase()
	{
		std::cout << "base constructor called" << std::endl;
	}
	FSMStatBase(const FSMStatBase& other)
	{
		std::cout << "base copy constructor called" << std::endl;
	}
};

struct FSMStat : public FSMStatBase
{
	FSMStat()
	{
		std::cout << "derived constructor called" << std::endl;
	}
	FSMStat(const FSMStat& other)
	{
		std::cout << "derived copy constructor called" << std::endl;
	}
};

void foo(const FSMStatBase& stat)
{
}

int main()
{
	FSMStat* stat = new FSMStat();
	foo(stat != nullptr ? *stat: FSMStatBase());
	return 0;
}

