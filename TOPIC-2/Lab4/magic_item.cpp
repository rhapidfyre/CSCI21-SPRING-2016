// Name       : Inheritance Lab CPP
// Author     : Michael Harris
// Description: Class Inheritance

#include "magic_item.h"

MagicItem::MagicItem()
{
    // Set the defaults
    name_ = "magicitem";
    value_ = 0;
    description_ = "no description";
    mana_required_ = 0;
}
MagicItem::MagicItem(string name, int value, string description, unsigned int mana_required)
{
    name_ = name;
    value_ = value;
    description_ = description;
    mana_required_ = mana_required;
}
MagicItem::~MagicItem()
{
    
}
void MagicItem::set_description(string description)
{
    description_ = description;
}
void MagicItem::set_mana_required(int mana_required)
{
    mana_required_ = mana_required;
}
string MagicItem::description()
{
    return description_;
}
int MagicItem::mana_required()
{
    return mana_required_;
}
string MagicItem::ToString()
{
    stringstream ss;
    ss.clear();
    
    ss << Item::ToString() << ", " << description_ << ", requires " << mana_required_ << " mana";
    return ss.str();
}