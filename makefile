SHELL=/bin/bash
CXX=g++
CXXFLAGS=-std=c++11 -Wall -g
RM=rm -rf

.PHONY: clean

# Target rules
main: main.o daily-stats.o
	$(CXX) -o $@ $^

test: test.o daily-stats.o
	$(CXX) -o $@ $^

test-all: test
	./test

# General compilation rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

test-run: main
	./main < input.txt

clean:
	$(RM) *.o main test *.gc* *.dSYM
