/*
 * Name        : lab_12.cpp
 * Author      : Michael Harris
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
#include "lab_12.h"

// CODE HERE -- FUNCTION DEFINITIONS
int* MakeDynoIntArray(unsigned int size)
{
    // Init the pointer
    int* pointer;
    // Create our array with given size
    pointer = new int[size];
    return pointer;
}
int Sum(int* the_array, unsigned int array_size)
{
    // Initialize our vars
    int* pointer;
    pointer = the_array;
    int sum = 0;
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";
    }
    for(int i = 0; i < array_size; i++)
    {
        sum = sum + pointer[i]; // Keep adding each slot together
    }
    return sum;
}
int Max(int* the_array, unsigned int array_size)
{
    int* pointer;
    pointer = the_array;
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";
    }
    int highest = the_array[0];
    for(int i = 0; i < array_size;i++)
    {
        // If the highest var is lower than the pointer's location, set it to the new slot.
        if(highest < pointer[i]) {highest = pointer[i];}
        else{/*Do Nothing*/}
    }
    return highest;
}
int Min(int* the_array, unsigned int array_size)
{
    int* pointer;
    pointer = the_array;
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";
    }
    int lowest = the_array[0];
    for(int i = 0; i < array_size;i++)
    {
        // If the highest var is lower than the pointer's location, set it to the new slot.
        if(lowest > pointer[i]) {lowest = pointer[i];}
        else{/*Do Nothing*/}
    }
    return lowest;
}