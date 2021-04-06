#include <atomic>
#include <assert.h>

int A, B, V;

void plain()
{
	A = V + 1;
	B = 1;
}

void thread()
{
	if (B == 1)
	{
		assert(A == V + 1);
	}
}

int main()
{
	plain();
	return 0;
}

