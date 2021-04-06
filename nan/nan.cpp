#include <iostream>
#include <math.h>
#include <stdint.h>
#include <assert.h>

int main()
{
	float nan = 0.0f / 0.0f;
	uint32_t* u = (uint32_t*)&nan;
	std::cout << std::hex << *u << " is nan: " << isnan(nan) << std::endl;
	*u = 0xFFFFFFFF;
	std::cout << std::hex << *u << " is nan: " << isnan(nan) << std::endl;

	float f = nan;
	assert(f == nan);
	return 0;
}

