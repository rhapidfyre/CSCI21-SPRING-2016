 /*
 * Name        : Debit.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include "Assignment2.h"
 
Debit::Debit(): Account() {
    fee_ = 2.50; 
}

Debit::Debit(string owner, double balance, double fee) {
    owner_ = owner;
    balance_ = balance;
    fee_ = fee;
}
double Debit::GetFee() const {
    return fee_;
}

void Debit::SetFee(double fee) {
    fee_ = fee;
}

string Debit::ToString() const {
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    
    ss << owner_ << "'s Account\n";
    ss << "DEBIT USE FEE: $" << fee_;
    
    return ss.str();
}
    
    