#include <chrono>
#include <iostream>
#include <vector>

template <typename T>
int get_function_vtable_offset(T t)
{
	union
	{
		T ptr;
		int offset;
	};
	ptr = t;
	return (offset - 1) / sizeof(void*);
}

class A;

void* get_virtual_function_address(const A* a, int offset)
{
	void** vtable = *(void***)a;
	return vtable[offset];
}

class A
{
public:
	void init()
	{
		static const int offset = get_function_vtable_offset(&A::update);		
		static const A proto_type;
		static const void* a_update_address = get_virtual_function_address(&proto_type, offset);
		has_update = a_update_address != get_virtual_function_address(this, offset);
	}
	virtual void update(){}
	bool has_update = false;
};

static int count = 0;
class B : public A
{
public:
	virtual void update() override
	{
		count++;	
	}
};

int main()
{
	const int M = 10000;
	const int N = 100000;
	std::vector<A*> va;
	va.reserve(M);
	for (int i = 0; i < M; i++)
	{
		va.push_back(new A());
		va.back()->init();
	}
	auto start = std::chrono::high_resolution_clock::now();	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (va[j]->has_update)
				va[j]->update();
		}
	}
	auto end = std::chrono::high_resolution_clock::now();	
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;	
	return 0;
}


