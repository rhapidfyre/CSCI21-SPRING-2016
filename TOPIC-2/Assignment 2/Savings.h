 /*
 * Name        : Debit.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include "Account.h"

#ifndef SAVINGS
#define SAVINGS

class Savings: public Account
{
    public:
        Savings();
        Savings(const double, const double, const double);
        double GetInterestRate() const;
        void SetInterestRate(double interest);
        string ToString() const;
    private:
       double interest_;
};

#endif 