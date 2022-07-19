#include <stdio.h>
#include <iostream>
#include <type_traits>

struct B
{
	int i;
};

struct D : B
{
	int j;
	virtual ~D(){}
};

int main()
{
	std::aligned_storage_t<sizeof(D), alignof(D)> buffer;	

	B* b = reinterpret_cast<B*>(new (&buffer) D);
	D* d = static_cast<D*>(b);

	const int offset = reinterpret_cast<uint8_t*>(d) - reinterpret_cast<uint8_t*>(&buffer);
	printf("offset=%d\n", offset);

	return 0;
}

