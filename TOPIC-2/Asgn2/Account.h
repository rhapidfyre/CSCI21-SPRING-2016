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
        Account(string owner, double balance);
        double GetOwner() const;
        double GetBalance() const;
        void SetOwner() const;
        void SetBalance(double balance);
        string ToString() const;
    protected:
        double balance_;
        string owner_;
};

#endif 