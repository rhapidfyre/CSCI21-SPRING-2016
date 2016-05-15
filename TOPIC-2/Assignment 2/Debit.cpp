 /*
 * Name        : Debit.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
 #include "Debit.h"
 
Checking::Checking(): Account() {
    fee_ = 2.50; 
}

Checking::Checking(double balance, double deposit, double withdrawl): Account(balance, deposit, withdrawl) {
    fee_ = 2.50;
}
double Checking::GetFee() const {
    return fee_;
}

void Checking::SetFee(double fee) {
    fee_ = fee;
}

string Checking::ToString() const {
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    ss << "DEBIT USE FEE: $" << fee_;
    
    return ss.str();
}
    
    