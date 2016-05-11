/*
 * Name        : sorting.cpp
 * Author      : FILL IN
 * Description : Working with Insertion and Shell Sort
 */
#include "sorting.h"




// CODE HERE -- FUNCTION DEFINITIONS

int BubbleSort(int the_array[], unsigned int size) {
  int counter = 0;
  for (unsigned int i = (size-1); i > 0; i--) {
    counter++;
    for (unsigned int z = 0; z < i; z++) {
      if (the_array[z] > the_array[z+1]) {
        SwapValues(the_array[z], the_array[z+1]);
      }
    }
  }
  return counter;
}

int OptimizedBubbleSort(int the_array[], unsigned int size) {
  // Init Counter
  int counter = 0;
  for(unsigned int i = 0; i < size; i++) {
    bool sorted = true;
    counter++;
    for(unsigned int z = 0; z < size; z++) {
      if(!the_array[z+1]) {
        // Do Nothing, END
        // For some reason if I take this out, the unit test fails.
      }
      else if(the_array[z] <= the_array[z+1]) {
        // Do Nothing
      } else {
        // Swap Them, the one on the right is higher!
        SwapValues(the_array[z], the_array[z+1]);
        sorted = false;
      }
    }
    if(sorted) {
      break;
    }
  }
  return counter;
}

int SelectionSort(int the_array[], unsigned int size) {
  // Init Counter & minimum variable, which is spot #1 for now
  int min;
  int counter = 0;
  // For Loop holding the marker
  for(unsigned int i=0;i<size;i++) {
    // Counter + 1 & set minimum to array position
    counter++;
    min = i;
    // For Loop iterating through
    // IMPORTANT: Z's position MUST be one ahead of the beginning marker!
    for(unsigned int z=i+1;z<size;z++) {
      // Find the smallest number
      if(the_array[z] < the_array[min]) {
        // Change array position
        min = z;
      }
    }
    if(the_array[i] != the_array[min]) {
      SwapValues(the_array[i], the_array[min]);
    }
  }
  return counter;
}

int InsertionSort(int the_array[], unsigned int size) {
  int z;
  int counter = 0;
  for (unsigned int i=0; i < size; i++) {
    counter++;
    z = i;
    while ((z > 0) && (the_array[z] < the_array[z-1])) {
      SwapValues(the_array[z], the_array[z-1]);
      z = z - 1;
    }
  }
  return counter;
}

int ShellSort(int the_array[], unsigned int size) {
  int j;
  int counter = 0;
  int gap = size / 2;
  while(gap > 0) {
      counter++;
    for(unsigned int i = gap; i < size;i++){
      int temp = the_array[i];
      j = i;
      while((j >= gap) && (the_array[j-gap] > temp)) {
        the_array[j] = the_array[j-gap];
        j = j - gap;
      }
      the_array[j] = temp;
      DisplayArray(the_array);
    }
    gap = gap / 2;
  }
  return counter;
}

void SwapValues(int &value_1, int &value_2) {
  // DO NOT ALTER THE NEXT 3 LINES!!!
  if (GRADER) {
    cout << value_1 << " " << value_2 << endl;
  }
  // Code SWAP Algorithm Here
  int x = value_1;
  value_1 = value_2;
  value_2 = x;
}

