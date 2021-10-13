#include <iostream>
#include <chrono>
#include <string.h>

template <typename element_t, int N>
struct matrix
{
	element_t ele[N][N];
	inline int size() const
	{
		return N;
	}

	inline const element_t& operator[](int index) const
	{
		return *(ele[0] + index);
	}

	inline element_t& operator[](int index)
	{
		return *(ele[0] + index);
	}

	inline void operator=(float x)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ele[i][j] = x;
			}
		}
	}

	inline void operator += (const matrix& o)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ele[i][j] += o.ele[i][j];
			}
		}
	}
};

int get_index(int N, int i, int j)
{
	return j + i * N;
}

template <typename matrix_t>
matrix_t operator*(const matrix_t& __restrict a, const matrix_t& __restrict b)
{
	const int N = a.size();
	matrix_t r;
	for (int i  = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			const int ri = get_index(N, i, j);
			r[ri] = 0;
			for (int k = 0; k < N; k++)
			{
				r[ri] += a[get_index(N, i, k)] * b[get_index(N, k, j)];	
			}
		}
	}
	return r;
}

static const int TILE_SIZE = 16;
static const int MATRIX_SIZE = 512;

template <typename matrix_t>
void init_matrix(matrix_t& m)
{
	float* f = reinterpret_cast<float*>(&m);
	float ff = 1.01f;
	for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++)
	{
		*f++ = ff;
	}
}

template <typename matrix_t>
float sum_matrix(matrix_t& m)
{
	float* f = reinterpret_cast<float*>(&m);
	float ff = 0;
	for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++)
	{
		ff += *f++;
	}
	return ff;
}

template <typename matrix_t>
float test_mul(int N)
{
	matrix_t n, a, b;
	memset(&n, 0, sizeof(matrix_t));
	init_matrix(a);
	init_matrix(b);
	for (int i = 0; i < N; i++)
	{
		n = a * b;			
	}
	return sum_matrix(n);
}

int main()
{
	typedef matrix<float, TILE_SIZE> tile_t;
	typedef matrix<float, MATRIX_SIZE> normal_matrix_t;
	typedef matrix<tile_t, MATRIX_SIZE / TILE_SIZE> block_matrix_t;

	const int N = 10;
	if (true)
	{
		auto start = std::chrono::high_resolution_clock::now();
		float f = test_mul<normal_matrix_t>(N);
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << '\t' << f << std::endl;
	}
	if (false)
	{
		auto start = std::chrono::high_resolution_clock::now();
		float f = test_mul<block_matrix_t>(N);
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << '\t' << f << std::endl;
	}
	return 0;
}

