#include <iostream>
#include <chrono>
#include <xmmintrin.h>

typedef __m128 float4;

struct Point2D
{
	float4 x;
	float4 y;
};

struct Rect2D
{
	Point2D minimum;
	Point2D maximum;
};

inline float4 intersect1d(float4 a_minimum, float4 a_maxinum, float4 b_minimum, float4 b_maximum)
{
	float4 i = _mm_cmple_ps(a_minimum, b_maximum);
	float4 j = _mm_cmple_ps(b_minimum, a_maxinum);
	return _mm_and_ps(i, j);
}

inline int intersect2d(const Rect2D& a, const Rect2D& b)
{
	float4 i = intersect1d(a.minimum.x, a.maximum.x, b.minimum.x,  b.maximum.x);
	float4 j = intersect1d(a.minimum.y, a.maximum.y, b.minimum.y,  b.maximum.y);
	return __builtin_popcount(_mm_movemask_ps(_mm_and_ps(i, j)));
}

__attribute__((noinline)) int test(const Rect2D& boxes1, const Rect2D& boxes2)
{
	int intersects = intersect2d(boxes1, boxes2);
	return intersects;
}

int main()
{
	float a_minimum[] = {0, 0, 0, 0};
	float b_minimum[] = {0, 0, 0, 0};
	float a_maximum[] = {1, 1, 1, 1};
	float b_maximum[] = {1, 1, 1, 1};
	Rect2D boxes1 = {{_mm_load_ps(a_minimum), _mm_load_ps(b_minimum)}, {_mm_load_ps(a_maximum), _mm_load_ps(b_maximum)}};
	Rect2D boxes2 = boxes1;

	static const int M = 1024 * 1024 * 100;
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		sum += test(boxes1, boxes2);
		asm volatile("": :"r,m"(sum): "memory");
	}
	auto end = std::chrono::high_resolution_clock::now();
    std::cout << sum << "\telapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return 0;
}

