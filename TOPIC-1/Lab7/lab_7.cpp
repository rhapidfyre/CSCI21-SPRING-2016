/*
 * Name        : lab_7.cpp
 * Author      : Michael Harris
 * Description : Working with File I/O
 */
#include "lab_7.h"

// Process File Boolean
bool ProcessFile(string filename)
{
    // Declare File I/O name it myFile and open the sucker. (Step 1 & 2 of File I/O!)
    ifstream myFile;
    myFile.open(filename.c_str());
    
    // Use the opened file (Step 3)
    if(myFile.is_open())
    {
        // Prepare a string for file I/O
        string file_variable;
        
        // Loop the file until the end.
        while(!myFile.eof())
        {
            // Assign place in file to string
            myFile >> file_variable;
            
            // Check against our functions
            if(file_variable == "10")
                {OnTen();}
            else if(file_variable == "20")
                {OnTwenty();}
            else if(file_variable == "30")
                {OnThirty();}
            else if(file_variable == "40")
                {OnForty();}
            else if(file_variable == "50")
                {OnFifty();}
            else
                {OnError();}
        }
        // We're done, always close the file (Step 4)
        myFile.close();
        return true;
    }
    else
    {
        cout << "Unable to Open File!" << endl;
    }
    
    // Close it, we're d-d-done (Step 4)
    myFile.close();
    return false;
}

void ProcessArguments(int argc, char* argv[])
{
    // Loop through all the arrays as long as it's less than our argument
    for(int i = 0; i < argc; i++)
    {
        // Test our functions
        if(argv[i] == "10")
            {OnTen();}
        else if(argv[i] == "20")
            {OnTwenty();}
        else if(argv[i] == "30")
            {OnThirty();}
        else if(argv[i] == "40")
            {OnForty();}
        else if(argv[i] == "50")
            {OnFifty();}
        else
            {OnError();}
    }
}