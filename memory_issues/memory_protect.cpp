#include <sanitizer/asan_interface.h>

int main()
{
	volatile char buffer[8];
	ASAN_POISON_MEMORY_REGION(buffer, 8);
	buffer[0] = '\0';
	return 0;
}
