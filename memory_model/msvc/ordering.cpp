#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <intrin.h>
#include <stdio.h>

// Set either of these to 1 to prevent CPU reordering
#define USE_CPU_FENCE              0
#define USE_SINGLE_HW_THREAD       0


//-------------------------------------
//  MersenneTwister
//  A thread-safe random number generator with good randomness
//  in a small number of instructions. We'll use it to introduce
//  random timing delays.
//-------------------------------------
#define MT_IA  397
#define MT_LEN 624

class MersenneTwister
{
    unsigned int m_buffer[MT_LEN];
    int m_index;

public:
    MersenneTwister(unsigned int seed);
    // Declare noinline so that the function call acts as a compiler barrier:
    __declspec(noinline) unsigned int integer();
};

MersenneTwister::MersenneTwister(unsigned int seed)
{
    // Initialize by filling with the seed, then iterating
    // the algorithm a bunch of times to shuffle things up.
    for (int i = 0; i < MT_LEN; i++)
        m_buffer[i] = seed;
    m_index = 0;
    for (int i = 0; i < MT_LEN * 100; i++)
        integer();
}

unsigned int MersenneTwister::integer()
{
    // Indices
    int i = m_index;
    int i2 = m_index + 1; if (i2 >= MT_LEN) i2 = 0; // wrap-around
    int j = m_index + MT_IA; if (j >= MT_LEN) j -= MT_LEN; // wrap-around

    // Twist
    unsigned int s = (m_buffer[i] & 0x80000000) | (m_buffer[i2] & 0x7fffffff);
    unsigned int r = m_buffer[j] ^ (s >> 1) ^ ((s & 1) * 0x9908B0DF);
    m_buffer[m_index] = r;
    m_index = i2;

    // Swizzle
    r ^= (r >> 11);
    r ^= (r << 7) & 0x9d2c5680UL;
    r ^= (r << 15) & 0xefc60000UL;
    r ^= (r >> 18);
    return r;
}


//-------------------------------------
//  Main program, as decribed in the post
//-------------------------------------
HANDLE beginSema1;
HANDLE beginSema2;
HANDLE endSema;

int X, Y;
int r1, r2;

DWORD WINAPI thread1Func(LPVOID param)
{
    MersenneTwister random(1);
    for (;;)
    {
        WaitForSingleObject(beginSema1, INFINITE);  // Wait for signal
        while (random.integer() % 8 != 0) {}  // Random delay

        // ----- THE TRANSACTION! -----
        X = 1;
#if USE_CPU_FENCE
        MemoryBarrier();  // Prevent CPU reordering
#else
        _ReadWriteBarrier();  // Prevent compiler reordering only
#endif
        r1 = Y;

        ReleaseSemaphore(endSema, 1, NULL);  // Notify transaction complete
    }
    return 0;  // Never returns
};

DWORD WINAPI thread2Func(LPVOID param)
{
    MersenneTwister random(2);
    for (;;)
    {
        WaitForSingleObject(beginSema2, INFINITE);  // Wait for signal
        while (random.integer() % 8 != 0) {}  // Random delay

        // ----- THE TRANSACTION! -----
        Y = 1;
#if USE_CPU_FENCE
        MemoryBarrier();  // Prevent CPU reordering
#else
        _ReadWriteBarrier();  // Prevent compiler reordering only
#endif
        r2 = X;

        ReleaseSemaphore(endSema, 1, NULL);  // Notify transaction complete
    }
    return 0;  // Never returns
};

int main()
{
    // Initialize the semaphores
    beginSema1 = CreateSemaphore(NULL, 0, 99, NULL);
    beginSema2 = CreateSemaphore(NULL, 0, 99, NULL);
    endSema = CreateSemaphore(NULL, 0, 99, NULL);

    // Spawn the threads
    HANDLE thread1, thread2;
    thread1 = CreateThread(NULL, 0, thread1Func, NULL, 0, NULL);
    thread2 = CreateThread(NULL, 0, thread2Func, NULL, 0, NULL);

#if USE_SINGLE_HW_THREAD
    // Force thread affinities to the same cpu core.
    SetThreadAffinityMask(thread1, 1);
    SetThreadAffinityMask(thread2, 1);
#endif

    // Repeat the experiment ad infinitum
    int detected = 0;
    for (int iterations = 1; ; iterations++)
    {
        // Reset X and Y
        X = 0;
        Y = 0;
        // Signal both threads
        ReleaseSemaphore(beginSema1, 1, NULL);
        ReleaseSemaphore(beginSema2, 1, NULL);
        // Wait for both threads
        WaitForSingleObject(endSema, INFINITE);
        WaitForSingleObject(endSema, INFINITE);
        // Check if there was a simultaneous reorder
        if (r1 == 0 && r2 == 0)
        {
            detected++;
            printf("%d reorders detected after %d iterations\n", detected, iterations);
        }
    }
    return 0;  // Never returns
}

