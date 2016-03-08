// Name       : Inheritance Lab H
// Author     : Michael Harris
// Description: Class Inheritance

#ifndef ITEM
#define ITEM

#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Item {
  public:
    Item();
    Item(string name, int value);                                               
    virtual ~Item();                                                                    
    void set_name(string name);                                                       
    void set_value(int value);                                                        
    string name();                                                       
    int value();                                                        
    string ToString();                                                                 
  protected:
    string name_;
    unsigned int value_;    
};

#endif