// Name       : Inheritance Lab H
// Author     : Michael Harris
// Description: Class Inheritance

#ifndef MAGIC_ITEM
#define MAGIC_ITEM

#include <sstream>
#include <iostream>
#include <string>
#include "item.h"
using namespace std;

class MagicItem: public Item
{
  friend class Item;
  public:
    MagicItem();                                                                 // Uses the Defaults of the Class
    MagicItem(string name, int value, string description, unsigned int mana_required); // Defines the values of the Class
    virtual ~MagicItem();                                                        // Destructor for Overload
    void set_description(string description);                                     // Mutator for setting the Description
    void set_mana_required(int mana_required);                                     // Mutator for setting the Mana Required
    string description();                                                     // Accessor for Description
    int mana_required();                                             
    string ToString();                                                             // Accessor to return ALL VALUES in a String Format
  private: 
    string description_;                                                         // Defines the Item Description
    unsigned int mana_required_;                                                 // Defines the Mana Use for the Item
};

#endif