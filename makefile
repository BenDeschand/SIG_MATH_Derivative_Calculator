test: test01.o derivative.o
	g++ -o test test01.o derivative.o

test.o: test*.cpp derivative.h
	g++ -g -c test*.cpp

derivative.o: derivative.cpp derivative.h
	g++ -g -c derivative.cpp

clean: 
	rm test01.o derivative.o test