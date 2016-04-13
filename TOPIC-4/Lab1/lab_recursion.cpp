/*
 * Name        : lab_recursion.cpp
 * Author      : Michael Harris
 * Description : Recursive Functions
 */

#include "lab_recursion.h"

// CODE FUNCTION DEFINITIONS HERE

/*
 * UPDATE!!!! to match the requirements
 * Convert a decimal number to binary
 * @param number to be converted.
 * @return a stringstream.
 */
void decToBin(int num)
{
	if (num > 1) //note this makes the base case num = 0
	{
		decToBin(num/2); //recursive call
	}

	cout<<(num%2); //outputs in correct order
}

unsigned int binToDec(int num) {
	unsigned int convert = num;
	if (convert > 0) {
		binToDec(convert/2);
	} return convert;
}