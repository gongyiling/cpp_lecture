all: corrupt protect leak

corrupt: memory_corrupt.cpp
	clang++ memory_corrupt.cpp -fsanitize=address -o corrupt

protect: memory_protect.cpp
	clang++ memory_protect.cpp -fsanitize=address -o protect 

# perf record -e page-faults --callgraph dwarf -p pid
# perf script
leak: memory_leak.cpp
	clang++ memory_leak.cpp -o leak

clean:
	rm -rf corrupt protect leak

