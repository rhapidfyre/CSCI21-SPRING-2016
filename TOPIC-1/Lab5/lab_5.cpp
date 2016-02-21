/*
 * Name        : lab_5.cpp
 * Author      : FILL IN
 * Description : Practicing Functions. Use this file to write your
 *               Function Definitions (what goes below main()).
 */

#include "lab_5.h"


void Hello()
{
    cout << "Hello world!";
}

void PrintMessage(const string& message)
{
    cout << message << std::flush;
}

int FindLarger(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else if(x < y)
    {
        return y;
    }
    else if(x == y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

string BuildMessage(string message, bool uppercase)
{
    if(message.empty())
    {
        message = "Message: empty";
    }
    else if(uppercase == true)
    {
        for(int i = 0; i < message.length(); i++)
        {
            message[i] = toupper(message[i]);
        }
        message = "Message: " + message;
    }
    else
    {
        message = "Message: " + message;
    }
    return message;
}

int GetAnswer()
{
    return 42;
}