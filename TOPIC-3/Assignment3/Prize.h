/*
    Michael Harris
    04/01/2016
    Assignment #3 Prize File
*/

// Includes
#include <cstdlib>
#include <iostream>
using namespace std;

#ifndef PRIZE
#define PRIZE

class Prize {
    public:
        Prize();
        Prize(string prizeName, int prizeValue);
        ~Prize();
        friend bool operator ==(const Prize& prize1, const Prize& prize2);
        void setPrizeName(string prizeName);
        void setPrizeValue(int prizeValue);
        string getPrizeName();
        int getPrizeValue();
    private:
        string prizeName_;
        int prizeValue_;
};

#endif