#include <iostream>
#include <chrono>
#include <assert.h>

struct Point2D
{
	float x;
	float y;
};

struct Rect2D
{
	Point2D minimum;
	Point2D maximum;
};

#define AND &&

inline bool intersect1d(float a_minimum, float a_maxinum, float b_minimum, float b_maximum)
{
	return (a_minimum <= b_maximum) AND (b_minimum <= a_maxinum);
}

inline bool intersect2d(const Rect2D& a, const Rect2D& b)
{
	return intersect1d(a.minimum.x, a.maximum.x, b.minimum.x,  b.maximum.x) AND
			intersect1d(a.minimum.y, a.maximum.y, b.minimum.y,  b.maximum.y);
}

static const int N = 4;
__attribute__((noinline)) int test(const Rect2D* boxes1, const Rect2D* boxes2)
{
	int intersects = 0;	
	for (int i = 0; i < N; i++)
	{
		intersects += intersect2d(boxes1[i], boxes2[i]);
		asm volatile("": :"r,m"(intersects): "memory");
	}
	return intersects;
}

int main()
{
	Rect2D box{{0, 0}, {1, 1}};
	Rect2D boxes1[N] = {box, box, box, box};
	Rect2D boxes2[N] = {box, box, box, box};

	static const int M = 1024 * 1024 * 100;
	int sum = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		sum += test(boxes1, boxes2);
	}
	auto end = std::chrono::high_resolution_clock::now();
    std::cout << sum << "\telapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	return 0;
}

