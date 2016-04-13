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

bool operator ==(const Prize& prize1, const Prize& prize2) {
   /* string temp = prize1.getPrizeName();
    int tempi = prize2.getPrizeName();
    string temp2 = prize2.getPrizeValue();
    int tempi2 = prize2.getPrizeValue();
    
    if(temp == temp2 && tempi == tempi2) {
        return true;
    } else {
        return false;
    }*/
    if(prize1.prizeName_ == prize2.prizeName_) {
        if(prize1.prizeValue_ == prize2.prizeValue_) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

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
    prizes_ = new Prize[prizeCapacity_];
}

Box::Box(unsigned int boxNumber, string boxColor, unsigned int prizeCapacity) {
    // Applies given values for overload
    boxNumber_ = boxNumber;
    boxColor_ = boxColor;
    prizeCapacity_ = prizeCapacity;
    prizeCount_ = 0;
    prizes_ = new Prize[prizeCapacity_];
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
    return prizeCapacity_;
}

unsigned int Box::getPrizeCount() {
    return prizeCount_;
}

bool Box::addPrize(Prize prize) {
    if(prizeCount_ < prizeCapacity_) {
        unsigned int i = 0;
        for(; i < prizeCount_;i++) {
            
        }
        prizes_[i] = prize;
        prizeCount_++;
        return true;
    }
    return false;
}

Prize& Box::getPrize(unsigned int index) {
    if(index + 1 > prizeCount_) {
        return scratch_;
    }
    for(unsigned int i = index; i < prizeCount_ ;i++)
    {
        return prizes_[index];
    }
    return scratch_;
}

Prize Box::removePrize(unsigned int index) {
    if(index < prizeCount_ && prizeCount_ > 0) {
        Prize temp = prizes_[index];
        for(unsigned int i = index; i < (prizeCount_ -1 );i++) {
            prizes_[i] = prizes_[i + 1];
        }
        prizeCount_--;
        return temp;
    }
    return scratch_;
}