/*
    Michael Harris
    04/01/2016
    Assignment #3 Box File
*/

using namespace std;

#ifndef BOX
#define BOX

class Box {
    public:
        Box();
        Box(boxNumber, boxColor, prizeCapacity);
        ~Box();
        void setBoxNumber(boxNumber);
        void setBoxColor(boxColor);
        int getBoxNumber();
        string getBoxColor();
        int prizeCapacity();
        int prizeCount();
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