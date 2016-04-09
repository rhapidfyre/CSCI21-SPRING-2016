// Includes
#include "Box.h"

// Prize Class Definitions
Prize::Prize() {
    // Applies default values as per instructions
    prizeName_ = "NO NAME";
    prizeValue_ = 0;
}

Prize::Prize(string prizeName, int prizeValue) {
    // Applies given values for overload
    prizeName_ = prizeName;
    prizeValue_ = prizeValue;
}

Prize::~Prize() {
    // Empty
}

//bool operator ==(prize1, prize2) {
//    return false;
//}

void Prize::setPrizeName(string prizeName) {
    prizeName_ = prizeName;
}

void Prize::setPrizeValue(int prizeValue) {
    prizeValue_ = prizeValue;
}

string Prize::getPrizeName() {
    return prizeName_;
}

int Prize::getPrizeValue() {
    return prizeValue_;
}

// Box Class Definitions
Box::Box() {
    // Declare default values as per instructions
    boxNumber_ = 0;
    boxColor_ = "NO COLOR";
    prizeCapacity_ = 5;
    prizeCount_ = 0;
    prizes_[prizeCapacity_];
}

Box::Box(unsigned int boxNumber, string boxColor, unsigned int prizeCapacity) {
    // Applies given values for overload
    boxNumber_ = boxNumber;
    boxColor_ = boxColor;
    prizeCapacity_ = prizeCapacity;
}

Box::~Box() {
    // Come back to this
}

void Box::setBoxNumber(unsigned int boxNumber) {
    boxNumber_ = boxNumber;
}

void Box::setBoxColor(string boxColor) {
    boxColor_ = boxColor;
}

unsigned int Box::getBoxNumber() {
    return boxNumber_;
}

string Box::getBoxColor() {
    return boxColor_;
}

unsigned int Box::getPrizeCapacity() {
    
}

unsigned int Box::getPrizeCount() {
    
}

bool Box::addPrize(Prize prize) {
    
}

Prize& Box::getPrize(unsigned int index) {
    
}
Prize Box::removePrize(unsigned int index) {
    
}