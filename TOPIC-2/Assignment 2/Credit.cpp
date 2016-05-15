 /*
 * Name        : Credit.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
 #include "Credit.h"
Credit::Credit(): Account() {
    interest_ = 4.25; 
}

Credit::Credit(double balance, double deposit, double withdrawl): Account(balance, deposit, withdrawl) {
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
        ss << "CURRENT INTEREST RATE: " << interest_;
        
        return ss.str();
}
    
    