all: labtest

labtest: lab3 lab3ut
	g++ -Wall -g -o labtest Assignment3.o unittest.o
	
lab3:
	g++ -Wall -g -c Assignment3.cpp
	
lab3ut:
	g++ -Wall -g -c unittest.cpp
	
clean:
	rm *.o labtest
