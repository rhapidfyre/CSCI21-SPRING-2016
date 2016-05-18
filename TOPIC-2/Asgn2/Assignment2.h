 /*
 * Name        : Credit.h
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
using namespace std;
 
#ifndef ACCOUNT
#define ACCOUNT

class Account
{
    public:
        Account();
        Account(string owner, double balance);
        string GetOwner() const;
        double GetBalance() const;
        void Deposit(double modifier);
        void Withdrawal(double modifier);
        void SetOwner(string owner);
        void SetBalance(double balance);
    protected:
        double balance_;
        string owner_;
};

class Credit: public Account
{
    public:
        Credit();
        Credit(string owner, double balance, double interest);
        double GetInterestRate() const;
        void SetInterestRate(double interest);
        string ToString() const;
    protected:
       double interest_;
};

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
 
class Debit: public Account
{
    public:
        Debit();
        Debit(string owner, double balance, double fee);
        double GetFee() const;
        void SetFee(double fee);
        string ToString() const;
    protected:
       double fee_;
};

#endif