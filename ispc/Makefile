main: main.o sum_ispc.o
	g++ sum_ispc.o main.o -o main

main.o: main.cpp
	g++ main.cpp -O2 -c -o main.o

sum_ispc.o: sum_ispc.ispc
	ispc -O2 --target=sse4 sum_ispc.ispc -o sum_ispc.o -h sum_ispc.h	

clean:
	rm -f main.o sum_ispc.o main
