all: labtest

labtest: lab labtree unittest
	g++ -Wall -g -o labtest bst_node.o bs_tree.o unittest.o
	
lab:
	g++ -Wall -g -c bst_node.cpp
	
labtree:
	g++ -Wall -g -c bs_tree.cpp
	
unittest:
	g++ -Wall -g -c unittest.cpp
	
clean:
	rm *.o labtest