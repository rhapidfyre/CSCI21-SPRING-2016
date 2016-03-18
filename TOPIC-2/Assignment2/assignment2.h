/*
    Assignment: Assignment 2 (ATM)
    Author:     Michael Harris
    Credit:     None Thus Far

*/

#include <iostream>
#include <cmath>
using namespace std;

// Define bank "account" (base)
class account
{
  public:
    MyAccount();
    MyAccount(int dollars, int cents);
    ~MyAccount();
    friend class Credit;
    friend class Debit;
    friend class Savings;
  protected:
    string name;
    string description;
};

// Define credit "account"
class Credit: class account
{
  public:
    Credit();
    Credit(int dollars, int cents, double interest_rate);
    ~Credit();
    void SetInterestRate(double interest_rate);
    double GetInterestRate();
  private:
    double interest_rate;
};

// Define checking "account"
class Debit: class account
{
  public:
    Debit();
    Debit(int dollars, int cents, double atm_fee);
    ~Debit();
    void SetFee(double atm_fee);
    double GetFee();
  private:
    double atm_fee;
};

// Define the Savings "account"
class Savings: class account
{
  public:
    Savings();
    Savings(int dollars, int cents, double dividend);
    ~Savings();
    void SetDividend(double dividend);
    double GetDividend();
  private:
    double dividend;
};