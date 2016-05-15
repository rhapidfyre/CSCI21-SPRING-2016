 /*
 * Name        : Debit.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */

 
#include "Savings.h"

Savings::Savings(): Account() {
    interest_ = 0.15; 
}

Savings::Savings(double balance, double deposit, double withdrawl): Account(balance, deposit, withdrawl) {

    interest_ = 0.15;
}
double Savings::interest() const {
    return interest_;
}

void Savings::set_interest(double interest) {
    interest_ = interest;
}

string Savings::ToString() const {
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    ss << "SAVINGS INTEREST RATE: " << interest_;
    
    return ss.str();
}
    
    