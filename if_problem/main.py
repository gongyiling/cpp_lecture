#!/usr/bin/env python

import os

def gen_program():
	templates = '''
#include <chrono>
#include <iostream>
#include <array>
#include <stdint.h>
#include <stdlib.h>
#include <sched.h>

void bind_to_cpu(int index)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(index, &set);
    sched_setaffinity(index, sizeof(set), &set);
}

int main()
{
	bind_to_cpu(0);
	auto start = std::chrono::high_resolution_clock::now();
	int first = 0, second = 0;
	for (int i = 0; i < %d; i++)
	{
%s
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "%d: elapsed " << elapsed << " milliseconds" << std::endl;
	return 0;
}'''
	f = open('main.cpp', 'w')
	n = 1024
	lc = 1024
	s = ''
	for i in range(0, lc):
		s += '\t\tif (i) first++; else second++;\n'	
	print(templates % (n, s, lc), file = f)

def compile_and_run():
	os.system('g++ -O2 main.cpp -o main')
	os.system('./main')

if __name__ == '__main__':
	gen_program()
	compile_and_run()
