#include <iostream>
#include <chrono>

class B
{
public:
	virtual int foo() = 0;
};

class D1 : public B
{
public:
	virtual int foo() override 
	{
		return 1;
	}
};

class D2 : public B 
{
public:
	virtual int foo() override 
	{
		return 2;
	}
};

int main()
{
	const int N = 1024;
	const int M = 1024 * 1024;
	B* b[N];
	for (int i = 0; i < N; i++)
	{
		b[i] = new D2();
	}
	int s = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			s += b[j]->foo();
		}
	}	
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;	
	return s;
}

