all: labtest

labtest: sorting unittest
	g++ -Wall -o labtest sorting.o unittest.o

sorting:
	g++ -Wall -c sorting.cpp

unittest:
	g++ -Wall -c unittest.cpp