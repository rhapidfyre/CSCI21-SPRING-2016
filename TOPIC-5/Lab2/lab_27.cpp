/*
 * Name        : lab_27.cpp
 * Author      : YOUR NAME
 * Description : Using the STL
 */

#include "lab_27.h"

// CLASS (and regular) FUNCTION DEFINITIONS GO HERE
void TreasureChest::AddItem(const Item& item_to_add) {
    chest_.push_back(item_to_add);
}
void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position) {
    chest_.assign(position, item_to_add);
}
const Item* TreasureChest::GetItem(unsigned int position) const {
    if(!chest_.empty()) {
        return (&chest_[position]);
    } else {
        return NULL;
    }
}
Item TreasureChest::RemoveItem(unsigned int position) {
    Item* temp = &chest_.at(position);
    chest_.erase(chest_.begin() + position);
    return *temp;
}
void TreasureChest::Clear() {
    chest_.clear();
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
    
}
void TreasureChest::SortByValue() {
    
}
void TreasureChest::SortByQuantity() {
    
}
ostream& operator<<(ostream& outs, const TreasureChest& src) {
    if(!src.Empty()) {
        for(unsigned int i = 0; i < src.GetSize();i++) {
            if(i == 0 || i == (src.GetSize()-1)) {
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