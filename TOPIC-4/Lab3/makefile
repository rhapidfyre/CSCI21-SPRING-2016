all: labtest

labtest: lab unittest
	g++ -Wall -g -o labtest bst_node.o unittest.o
	
lab:
	g++ -Wall -g -c bst_node.cpp
	
unittest:
	g++ -Wall -g -c unittest.cpp
	
clean:
	rm *.o labtest