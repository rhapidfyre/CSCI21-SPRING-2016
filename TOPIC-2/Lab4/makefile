all: lab4test

lab4test: lab_10_unit_test.o item.o food_item.o magic_item.o
	g++ -Wall -g -o lab4test lab_10_unit_test.o item.o food_item.o magic_item.o
	
item.o: item.cpp
	g++ -Wall -g -c item.cpp
	
food_item.o: food_item.cpp
	g++ -Wall -g -c food_item.cpp
	
magic_item.o: magic_item.cpp
	g++ -Wall -g -c magic_item.cpp
