/*
 * Name        : FILL IN
 * Author      : FILL IN
 * Description : FILL IN
 * Sources     : 1) IsAlpha         http://www.cplusplus.com/reference/cctype/isalpha/
                 2) Cesar Cipher    https://en.wikipedia.org/wiki/Caesar_cipher
                 3) Strings         http://www.cplusplus.com/reference/string/string/
 */

#include "assignment_1.h"

// Definition for func to check if string is alphabetical
bool CheckAlphabetic(string message)
{
    if(message.empty())
    {
        return false;
    }
    for(int i = 0; i < message.size(); i++)
    {
        if(!isalpha(message[i])) // If the character spot is not an alpha char, set false
        {
            return false;
        }
    }
    return true;
}

// Count words in a string definition
int CountWords(string message)
{
    // Declare word count
    int word_count = 1;

    // First, make sure the message isn't empty!
    if(message.empty())
    {
        word_count = 0;
    }
    else
    {
        // Loop through the string, if a space is detected, increase the word count.
        for(int i = 0; i < message.size(); i++){
            if(isspace(message[i])){word_count++;}
        }
    }
    return word_count;
}

// Caesar Cipher Shift unless string contains non-alpha chars
bool EncryptString(string &message, int amount)
{
    if(message.empty())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < message.size(); i++)
        {
            if(amount > 26)
            {
                amount = amount % 26;
            }
            if(amount < 0)
            {
                amount = (amount % (-26)) + 26;
            }
            if(message[i] >= 'A' && message[i] <= 'Z')
            {
                if((message[i]+amount) >= 'A' && (message[i]+amount) <= 'Z')
                {
                    message[i] = message[i] + amount;
                }
                else
                {
                    message[i] = (message[i] + amount) - 26;
                }
            }
            else if(message[i] >= 'a' && message[i] <= 'z')
            {
                if((message[i]+amount) >= 'a' && (message[i]+amount) <= 'z')
                {
                    message[i] = message[i] + amount;
                }
                else
                {
                    message[i] = (message[i] + amount) - 26;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}

// DecryptString Function unless contain non-alpha char
bool DecryptString(string &message, int amount)
{
    if(message.empty())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < message.size(); i++)
        {
            if(amount > 26)
            {
                amount = amount % 26;
            }
            if(amount < 0)
            {
                amount = (amount % (-26)) + 26;
            }
            if(message[i] >= 'A' && message[i] <= 'Z')
            {
                if((message[i]-amount) >= 'A' && (message[i]-amount) <= 'Z')
                {
                    message[i] = message[i] - amount;
                }
                else
                {
                    message[i] = (message[i] - amount) + 26;
                }
            }
            else if(message[i] >= 'a' && message[i] <= 'z')
            {
                if((message[i]-amount) >= 'a' && (message[i]-amount) <= 'z')
                {
                    message[i] = message[i] - amount;
                }
                else
                {
                    message[i] = (message[i] - amount) + 26;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}

// Determine average of values in array. At least size of 1
double ComputeAverage(double numbers[], int size)
{
    // Declare Variables
    double total = 0;
    int counter = 0;
    
    // Run the loop to build our total. Count each run for the division.
    // Stops when it reaches the declared array size or the default (1), whichever is highest
    for(int i = 0; i < size; i++)
    {
        // Add current number to the running total & increase the counter total of which we're going to use to get the average with division
        total = numbers[i] + total;
        counter++;
    }
    
    // Average = total of numbers divided by the count.
    total = total / counter;
    return total;
}

// Find and return smallest value in array
double FindMinValue(double numbers[], int size)
{
    // Assign the first array number to the "lowest" var
    double lowest = numbers[0];

    for(int i = 0; i < size; i++)
    {
        // If the lowest number is bigger than current array place, assign new number to the var
        if(lowest > numbers[i])
        {
            lowest = numbers[i];
        }
        else // Do nothing
        {
            
        }
    }
    return lowest;
}

// Find and return highest value in array
double FindMaxValue(double numbers[], int size)
{
    double highest = numbers[0];
    
    for(int i = 1; i < size; i++)
    {
        if(highest < numbers[i])
        {
            highest = numbers[i];
        }
        else
        {
            
        }
    }
    return highest;
}