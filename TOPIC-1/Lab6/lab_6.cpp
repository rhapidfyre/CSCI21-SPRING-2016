/*
 * Name        : lab_6.cpp
 * Author      : Michael Harris
 * Description : Working with Arrays
 */

#include "lab_6.h"

string PrepareForDisplay(int values[], int size, char separator)
{
    stringstream my_string;
    for(int i = 0; i < size; i++)
    {
        if(i == size-1)
        {
            my_string << values[i];
        }
        else
        {
            my_string << values[i] << separator;
        }
    }
    return my_string.str();
}

bool HasValue(int values[], int size, int value)
{
    size = sizeof(values);
    bool boolean = false;
    for(int i = 0; i < size; i++)
    {
        if(values[i] == value)
        {
            boolean = true;
        }
    }
    return boolean;
}

int ValueAt(int values[], int size, int index, bool &error)
{
    int i = 0;
    int new_index = 0;
    i = i + index;
    size = sizeof(values);
    if(index >= size)
    {
    }
    else
    {
        int new_index = values[i];
    }
    return new_index;
}

int Sum(int values[], int size)
{
    int running_total = 0;
    size = sizeof(values);
    for(int i = 0; i <= size; i++)
    {
        running_total = running_total + values[i];
    }
}

bool SwapValues(int values[], int size, int index1, int index2)
{
    size = sizeof(values);
    index2 = values[1];
    index1 = values[0];
    bool boolean = false;
    
    return boolean;
}