#include <atomic>


int A, B, V;
std::atomic<int> VV;

void plain()
{
	A = V;
	B = V;
}


void atom()
{
	A = VV.load(std::memory_order_relaxed);
	B = VV.load(std::memory_order_relaxed);
}

int main()
{
	plain();
	atom();
	return 0;
}

