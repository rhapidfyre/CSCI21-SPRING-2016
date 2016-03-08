// Name       : Inheritance Lab CPP
// Author     : Michael Harris
// Description: Class Inheritance

#include "food_item.h"

FoodItem::FoodItem()
{
    name_ = "fooditem";
    value_ = 0;
    calories_ = 0;
    unit_of_measure_ = "nounits";
    units_ = 0;
}
FoodItem::FoodItem(string name, int value, int calories, string unit_of_measure, double units)
{
    name_ = name;
    value_ = value;
    calories_ = calories;
    unit_of_measure_ = unit_of_measure;
    units_ = units;
}
FoodItem::~FoodItem()
{
    
}
void FoodItem::set_calories(int calories)
{
    calories_ = calories;
}
void FoodItem::set_unit_of_measure(string unit_of_measure)
{
    unit_of_measure_ = unit_of_measure;
}
void FoodItem::set_units(double units)
{
    units_ = units;
}
int FoodItem::calories()
{
    return calories_;
}
double FoodItem::units()
{
    return units_;
}
string FoodItem::unit_of_measure()
{
    return unit_of_measure_;
}
string FoodItem::ToString()
{
    stringstream ss;
    ss.clear();
    ss.precision(2);
    ss.setf(ios::fixed);
    ss << Item::ToString() << ", " << std::setfill('0') << std::setw(2) << units_ << " " << unit_of_measure_ << ", ";
    ss.clear();
    ss << calories_ << " calories";
    return ss.str();
}