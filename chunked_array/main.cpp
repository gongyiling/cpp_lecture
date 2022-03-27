#include <vector>
#include <iostream>
#include <chrono>
#include <stdint.h>
#include <assert.h>

template <typename T, int32_t N>
class chunked_array
{
public:
    typedef uint32_t size_type;
    struct chunk
    {
        T* data = NULL;
    };
    std::vector<chunk> m_chunks;
    size_type m_num;
    void resize(size_type num)
    {
        assert(m_chunks.empty());
        const size_type chunk_num = (num + N - 1) / N;
        m_chunks.resize(chunk_num);
        for (size_type i = 0; i < chunk_num; i++)
        {
            m_chunks[i].data = new T[N];
        }
		m_num = num;
    }
    T& operator[](size_type index)
    {
		// https://homepage.divms.uiowa.edu/%7Ejones/bcd/divide.html
		const size_type chunk_index = index / N;
		const size_type array_index = index % N;
		return m_chunks[chunk_index].data[array_index];
    }
	size_type size() const 
	{
		return m_num;
	}
};

int main()
{
	chunked_array<int, 1024> ca;
	const int N = 1024 * 1024;
	ca.resize(N);

	for (int i = 0; i < N; i++)
	{
		ca[i] = rand();
	} 	
	const int M = 1024;
	int s = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			s += ca[j];
			asm volatile("": :"r,m"(s): "memory");
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << s << '\t' << elapsed << std::endl;
	return 0;	
}


