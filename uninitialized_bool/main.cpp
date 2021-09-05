#include <iostream>
#include <stdint.h>

int main()
{
	uint8_t buf1 = 1;
	uint8_t buf255 = 255;
	volatile bool* b1 = new(&buf1) bool();
	volatile bool* b255 = new (&buf255) bool();
	std::cout << (*b1 == *b255) << std::endl;
	return 0;
}

