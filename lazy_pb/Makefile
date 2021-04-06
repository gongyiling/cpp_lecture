all: main

PROTOBUF_SRC=/home/fractal/protobuf/src/
PROTOBUF_LIB=${PROTOBUF_SRC}/.libs

main: main.o user.pb.o
	g++ main.o user.pb.o -o main -O2 -std=c++11 -I${PROTOBUF_SRC} -L${PROTOBUF_LIB} -lprotobuf

main.o: main.cpp
	g++ main.cpp -c -o main.o -O2 -std=c++11 -I${PROTOBUF_SRC}

user.pb.o: user.pb.cc user.pb.h
	g++ user.pb.cc -c -o user.pb.o -O2 -std=c++11 -I${PROTOBUF_SRC}
clean:
	rm -f main main.o user.pb.o
