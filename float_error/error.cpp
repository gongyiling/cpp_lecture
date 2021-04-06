#include <stdio.h>
#include <stdint.h>

float det(float a, float b, float c ,float d)
{
	return a * d - b * c;
}

int main()
{
	float M[2][2] = {{1.0, 1.0}, {1.0, 1.0}};
	float c[2] = {1.0, 1.0};
	uint32_t& u10 = *(uint32_t*)&M[1][0];
	for (int i = 0; i < 100; i++)
	{
		float d = det(M[0][0], M[0][1], M[1][0], M[1][1]);
		float x = det(c[0], M[0][1], c[1], M[1][1]) / d;
		float y = det(M[0][0], c[0], M[1][0], c[1]) / d;
		printf("det=%e\tx=%e\ty=%e\n", d, x, y);
		
		u10--;
		M[1][1] = 2 - M[1][0];
	}
	return 0;
}

