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
    for(int i = 0; i < size; i++)
    {
        if(values[i] == value)
        {
            return true;
        }
    }
    return false;
}

int ValueAt(int values[], int size, int index, bool &error)
{
    if(index >= size)
    {
        error = true;
        return 0;
    }
    else
    {
        error = false;
        return values[index];
    }
}

int Sum(int values[], int size)
{
    int running_total = 0;
    for(int i = 0; i < size; i++)
    {
        running_total = running_total + values[i];
    }
    return running_total;
}

bool SwapValues(int values[], int size, int index1, int index2)
{
    
    if(index1 < 0 || index2 < 0)
    {
        return false;
    }
    else if(index1 < size)
    {
        if(index2 < size)
        {
            int x = 0;
            x = values[index1];
            values[index1] = values[index2];
            values[index2] = x;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}