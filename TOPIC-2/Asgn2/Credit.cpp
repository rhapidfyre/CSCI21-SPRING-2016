 /*
 * Name        : Credit.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include "Assignment2.h"
Credit::Credit(): Account() {
    interest_ = 4.25; 
}

Credit::Credit(string owner, double balance, double interest) {
    owner_ = owner;
    balance_ = balance;
    interest_ = 4.25;
}
double Credit_Card::GetInterestRate() const {
    return interest_;
}

void Credit_Card::SetInterestRate(double interest) {
    interest_ = interest;
}

string Credit_Card::ToString() const {
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.setf(std::ios::showpoint);
    ss.setf(std::ios::right);
    ss.precision(2);
    
    ss << owner_ << "'s Account\n";
    ss << "CURRENT INTEREST RATE: " << interest_;
    
    return ss.str();
}
    
    