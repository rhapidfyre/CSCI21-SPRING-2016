 /*
 * Name        : Account.h
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
 
#ifndef ACCOUNT
#define ACCOUNT

class Account
{
    public:
        Account();
        Account(const double, const double, const double);
        double GetBalance() const;
        double GetDeposit() const;
        double GetWithdrawl() const;
        void SetBalance(double balance);
        void SetDeposit(double deposit);
        void SetWithdrawl(unsigned int withdrawl);
        string ToString() const;
    protected:
        double balance_;
        double deposit_;
        double withdrawl_;
};

#endif 