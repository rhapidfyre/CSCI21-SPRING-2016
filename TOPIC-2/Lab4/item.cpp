#include "item.h"

Item::Item()
{
    name_ = "item";
    value_ = 0;
}
Item::Item(string name, int value)
{
    name_ = name;
    value_ = value;
}
Item::~Item()
{
    
}
void Item::set_name(string name)
{
    name_ = name;
}
void Item::set_value(int value)
{
    value_ = value;
}
string Item::name()
{
    return name_;
}
int Item::value()
{
    return value_;
}
string Item::ToString()
{
    stringstream ss;
    ss.clear();
    
    ss << name_ << ", $" << value_;
    return ss.str();
}