// Name       : Inheritance Lab H
// Author     : Michael Harris
// Description: Class Inheritance

#ifndef FOOD_ITEM
#define FOOD_ITEM

#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "item.h"
using namespace std;

class FoodItem: public Item {
    friend class Item;
  public:
    FoodItem();
    FoodItem(string name, int value, int calories, string unit_of_measure, double units);
    virtual ~FoodItem();
    void set_calories(int calories);
    void set_unit_of_measure(string unit_of_measure);
    void set_units(double units);
    int calories();
    double units();
    string unit_of_measure();                                         
    string ToString();        
  protected:
    unsigned int calories_;
    string unit_of_measure_;
    double units_;
};

#endif