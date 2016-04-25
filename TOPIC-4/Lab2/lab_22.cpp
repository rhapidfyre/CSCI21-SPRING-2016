/*
 * Name        : lab_22.cpp
 * Author      : Michael Harris / Gage Smith / Dustin Miner
 * Description : Recursive Functions
 */

#include "lab_22.h"

// CODE FUNCTION DEFINITIONS HERE

unsigned int Factorial(unsigned int value) {
    // If greater than 1
    // Call Factorial() until value is 1
    while(value >= 1)
    {
        if(value == 1)
        {
            return value;
        }
        else
        {
            return (value * Factorial(value - 1));
        }
    }
    // Else, return 1;
    return 1;
}

unsigned int Fibonacci(unsigned int fib_value) {
    // If greater than 0
   // unsigned int temp = 1;
    if(fib_value == 0) {return 0;}
    if(fib_value == 1) {return 1;}
  
        return  Fibonacci(fib_value - 1) + Fibonacci(fib_value - 2);
}
bool WordIsPalindrome(string word) {
    // Initialize Temp as word size minus 1
    int temp = (word.size() - 1);
    bool tempy = false;
    // If the word is NULL or empty
    if(temp <= 0) {
        // return true;
        tempy = true;}
    // If the word is size 1
    else if(temp == 1) {
        // return true;
        tempy =  true;}
    // Else, Get size of string
    else {
        // Get first and last character
        // REFERENCE: http://www.cplusplus.com/forum/beginner/60399/
        string first = word.substr(0,1);
        string last = word.substr(temp);
        // If first letter of string matches last letter
        if(first == last) {
            // Remove first and last letter
            word = word.substr((0+1), (temp - 1));
            // If remaining length is 0 or 1
            cout<<word.size()<<endl;
            if(word.size() == 0 || word.size() == 1) {
                    // return true;
                    tempy = true;
            } else {
                // Else, Send it to: WordIsPalindrome(remaining_word)
                tempy = WordIsPalindrome(word);
            }
        } else {
            tempy = false;
        }
    }
    return tempy;
}
string ArrayForwardsAsString(int array[], unsigned int start,
                             unsigned int size) {
                                 
    // Initialize stringstream for output
    stringstream ss;
     // If start is the size,
    if(start == size) {
        // Return empty
        return "";
    } else {
        
        /* I couldn't figure out how to get this guy to work,
           so I referenced Russel's code to figure out what I did wrong.
           Turns out I was putting the array[start] inside of the if check.
           Whoops.
         */
        // Dump current array slot
        ss << array[start] << " ";
        if((start + 1) < size) {
            // Catch the return of the recursion
            ss << ArrayForwardsAsString(array, (start + 1), size);
        }
    }
    return ss.str();
}
string ArrayBackwardsAsString(int array[], int start, unsigned int size) {
    // Same as above with slight variation
    stringstream ss;
    if(start<0) {
        return "";
    }
    // Put current number into stringstream
    ss << array[start] << " ";
    if(start > 0) {
        // Catch the incoming return
        ss << ArrayBackwardsAsString(array, (start - 1), size);
    }
    return ss.str();
}