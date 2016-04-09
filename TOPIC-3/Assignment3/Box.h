/*
    Michael Harris
    04/01/2016
    Assignment #3 Box File
*/

// Includes
#include "Prize.h"

#ifndef BOX
#define BOX

class Box {
    public:
        Box();
        Box(unsigned int boxNumber, string boxColor, unsigned int prizeCapacity);
        ~Box();
        void setBoxNumber(unsigned int boxNumber);
        void setBoxColor(string boxColor);
        unsigned int getBoxNumber();
        string getBoxColor();
        unsigned int getPrizeCapacity();
        unsigned int getPrizeCount();
        bool addPrize(Prize prize);
        Prize& getPrize(unsigned int index);
        Prize removePrize(unsigned int index);
    private:
        unsigned int boxNumber_;
        string boxColor_;
        Prize scratch_;
        Prize* prizes_;
        unsigned int prizeCapacity_;
        unsigned int prizeCount_;
};

#endif