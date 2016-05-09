/*
 * Name        : sorting.cpp
 * Author      : FILL IN
 * Description : Working with Insertion and Shell Sort
 */
#include "sorting.h"

// CODE HERE -- FUNCTION DEFINITIONS
int BubbleSort(int the_array[], unsigned int size) {
  for(int i = 0; i < size; i++) {
    
  }
}

void SwapValues(int &value_1, int &value_2) {
  // DO NOT ALTER THE NEXT 3 LINES!!!
  if (GRADER) {
    cout << value_1 << " " << value_2 << endl;
  }
  // Code SWAP Algorithm Here
  else {
    int x = value_1;
    value_1 = value_2;
    value_2 = x;
    delete x;
  }
}
