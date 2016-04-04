/*
    Michael Harris
    04/01/2016
    Assignment #3 Prize File
*/

using namespace std;

#ifndef PRIZE
#define PRIZE

class Prize {
    public:
        Prize();
        Prize(prizeName, prizeValue);
        ~Prize();
        friend bool operator ==(prize1, prize2);
        void setPrizeName(prizeName);
        void setPrizeValue(prizeValue);
        string getPrizeName();
        int getPrizeValue();
    private:
        string prizeName_;
        unsigned int prizeValue_;
};

#endif