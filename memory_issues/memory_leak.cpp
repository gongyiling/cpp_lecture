#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>

void leak()
{
	char* p = (char*)malloc(128);
	memset(p, 0, 128);
	printf("leak p=%p\n", p);
}

int main()
{
	while (true)
	{
		leak();
		usleep(1000*100);		
	}
	return 0;
}
