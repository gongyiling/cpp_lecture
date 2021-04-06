#include <cpuid.h>
#include <stdio.h>

int main()
{
	unsigned int level  = 0x0a;
	unsigned int eax, ebx, ecx, edx;
	if (__get_cpuid(level, &eax, &ebx, &ecx, &edx))
	{
		printf("eax=%08x\tebx=%08x\tecx=%08x\tedx=%08x\n", eax, ebx, ecx, edx);
	}
	else
	{
		printf("__get_cpuid failed\n");
	}
	return 0;
}
