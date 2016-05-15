 /*
 * Name        : Account.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include "Account.h"

Account::Account() {
    balance_ = 0;
    deposit_ = 0;
    withdrawl_ = 0;
}

Account::Account(double balance, double deposit, double withdrawl) {
    balance_ = balance;
    deposit_ = deposit;
    withdrawl_ = withdrawl;
}

double Account::GetBalance() const {
    return balance_;
}

double Account::GetDeposit() const {
    return deposit_;
}

double Account::GetWithdrawl() const {
    return withdrawl_;
}

void Account::SetBalance(double balance) {
    balance_ = balance;
}

void Account::SetDeposit(double deposit) {
    deposit_ = deposit;
}

void Account::SetWithdrawl(unsigned int withdrawl) {
    withdrawl_ = withdrawl;
}

string Account::ToString() const {   
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    ss << "CURRENT BALANCE: $" << balance_;
    
    return ss.str();
}