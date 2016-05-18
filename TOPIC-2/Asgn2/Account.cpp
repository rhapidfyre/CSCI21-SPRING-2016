 /*
 * Name        : Account.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include "Assignment2.h"

Account::Account() {
    owner_ = "Unnamed Owner";
    balance_ = 0;
}

Account::Account(string owner, double balance) {
    owner_ = owner;
    balance_ = balance;
}

double Account::GetBalance() const {
    return balance_;
}

void Account::SetBalance(double balance) {
    balance_ = balance;
}

string Account::GetOwner() const {
    return balance_;
}

void Account::SetOwner(string owner) {
    owner_ = owner;
}

void Account::Deposit(double amount, double modifier) {
    if(modifier < 0) {
        cout << "Failure, deposit was negative." << endl;
        cout << "Deposit Canceled.\n" << endl;
    } else {
        balance_ = balance_ + modifier;
    }
}
void Account::Withdrawal(double amount, double modifier) {
    if(modifier < 0) {
        cout << "Failure, withdraw amount was negative." << endl;
        cout << "Withdrawal Canceled.\n" << endl;
    } else {
        balance_ = balance_ - modifier;
    }
}

string Account::ToString() const {   
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    
    ss << owner_ << "'s Account\n";
    ss << "CURRENT BALANCE: $" << balance_;
    
    return ss.str();
}