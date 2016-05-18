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
        Savings(string owner, double balance, double interest);
        double GetInterestRate() const;
        void SetInterestRate(double interest);
        string ToString() const;
    protected:
       double interest_;
};

#endif 