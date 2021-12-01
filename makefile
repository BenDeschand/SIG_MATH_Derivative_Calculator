test: test*.o derivative.o
	g++ -o test test*.o derivative.o

test*.o: test*.cpp derivative.h
	g++ -g -c test*.cpp

derivative.o: derivative.cpp derivative.h
	g++ -g -c derivative.cpp

clean: 
	rm test*.o derivative.o test
