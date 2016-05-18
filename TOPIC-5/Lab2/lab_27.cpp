/*
 * Name        : lab_27.cpp
 * Author      : Michael Harris
 * Description : Using the STL
 *
 * REF         : http://www.cplusplus.com/reference/vector/vector/
 */

#include "lab_27.h"

// CLASS (and regular) FUNCTION DEFINITIONS GO HERE
void TreasureChest::AddItem(const Item& item_to_add) {
    // Push the new item to the back of the array
    // It doesn't have to be organized, but this will increase the array size
    chest_.push_back(item_to_add);
}
void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position) {
    // If the pos is greater or equal to the size, it goes to the end
    // So that the size gets increased, otherwise SEGABORT
    if (position >= chest_.size()) {
        chest_.push_back(item_to_add);
    } else {
        // Otherwise, it's less than the size, so stick it in where it belongs
        chest_.insert(chest_.begin()+position, item_to_add);
    }
}
const Item* TreasureChest::GetItem(unsigned int position) const {
    if(!chest_.empty()) {
        // If the chest vector is NOT empty, but the requested position is bigger than
        // the size of the vector, return NULL --- It doesn't exist.
        if(position >= chest_.size()) {
            return NULL;
        }
        return (&chest_[position]);
    } else {
        return NULL;
    }
}
Item TreasureChest::RemoveItem(unsigned int position) {
    // We're returning the datatype of Item Object, so we declare a new object for now
    Item temp;
    if (position < chest_.size()) {
        // Set our temp object to whatever object is in the position given
        temp = chest_[position];
        // Kill it
        chest_.erase(chest_.begin()+position);
    } else {
        throw string("ERROR: Remove at invalid position");
    }
    return temp;
}
void TreasureChest::Clear() {
    chest_.clear(); // The clear function 
}
bool TreasureChest::Empty() const {
    if(chest_.empty()) {
        return true;
    } else {
        return false;
    }
}
unsigned int TreasureChest::GetSize() const {
    return chest_.size();
}
void TreasureChest::SortByName() {
    sort(chest_.begin(), chest_.end(), CompareItemsByName);
}
void TreasureChest::SortByValue() {
    sort(chest_.begin(), chest_.end(), CompareItemsByValue);
}
void TreasureChest::SortByQuantity() {
    sort(chest_.begin(), chest_.end(), CompareItemsByQuantity);
}
ostream& operator<<(ostream& outs, const TreasureChest& src) {
    if(!src.Empty()) {
        for(unsigned int i = 0; i < src.GetSize();i++) {
            if(i == 0 || i == src.GetSize()) {
                outs << *src.GetItem(i);
            } else {
                outs << ", " << *src.GetItem(i);
            }
        }
        return outs;
    } else {
        outs << "Chest Empty!";
        return outs;
    }
}
string TreasureChest::ToString() {
    stringstream ss;
    ss << *this;
    return ss.str();
}


bool CompareItemsByName(const Item& lsrc, const Item& rsrc) {
    if(lsrc.name_[0] < rsrc.name_[0]) return true;
    else return false;
}

bool CompareItemsByValue(const Item& lsrc, const Item& rsrc) {
    if(lsrc.value_ < rsrc.value_) return true;
    else return false;
}
bool CompareItemsByQuantity(const Item& lsrc, const Item& rsrc) {
    if(lsrc.quantity_ < rsrc.quantity_) return true;
    else return false;
}