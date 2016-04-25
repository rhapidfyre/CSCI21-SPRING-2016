all: labtest

labtest: labgroup unittest
	g++ -Wall -g -o labtest lab_22.o lab_22_unit_test.o
	
labgroup:
	g++ -Wall -g -c lab_22.cpp
	
unittest:
	g++ -Wall -g -c lab_22_unit_test.cpp
	
clean:
	rm *.o labtest