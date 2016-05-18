 /*
 * Name        : Account.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include "Assignment2.h"

Savings::Savings(): Account() {
    interest_ = 0.15; 
}

Savings::Savings(string owner, double balance, double interest) {
    owner_ = owner;
    balance_ = balance;
    interest_ = 0.15;
}
double Savings::GetInterestRate() const {
    return interest_;
}

void Savings::SetInterestRate(double interest) {
    interest_ = interest;
}

string Savings::ToString() const {
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    
    ss << owner_ << "'s Savings Account\n";
    ss << "Savings Interest Rate: " << interest_;
    ss << "\n NEW BALANCE: $" << balance_;
    
    return ss.str();
}
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
    
    ss << owner_ << "'s Debit Account\n";
    ss << "DEBIT USE FEE: $" << fee_;
    ss << "\n NEW BALANCE: $" << balance_;
    
    return ss.str();
}
    
Credit::Credit(): Account() {
    interest_ = 4.25; 
}

Credit::Credit(string owner, double balance, double interest) {
    owner_ = owner;
    balance_ = balance;
    interest_ = 4.25;
}
double Credit::GetInterestRate() const {
    return interest_;
}

void Credit::SetInterestRate(double interest) {
    interest_ = interest;
}

string Credit::ToString() const {
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.setf(std::ios::showpoint);
    ss.setf(std::ios::right);
    ss.precision(2);
    
    ss << owner_ << "'s Credit Account\n";
    ss << "INTEREST RATE: " << interest_;
    ss << "\n NEW BALANCE: $" << balance_;
    
    return ss.str();
}
    
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
    return owner_;
}

void Account::SetOwner(string owner) {
    owner_ = owner;
}

void Account::Deposit(double modifier) {
    if(modifier < 0) {
        cout << "Failure, deposit was negative." << endl;
        cout << "Deposit Canceled.\n" << endl;
    } else {
        balance_ = balance_ + modifier;
    }
}
void Account::Withdrawal(double modifier) {
    if(modifier < 0) {
        cout << "Failure, withdraw amount was negative." << endl;
        cout << "Withdrawal Canceled.\n" << endl;
    } else {
        balance_ = balance_ - modifier;
    }
}
























int main() {
    
    Debit MyDebit;
    Credit MyCredit;
    Savings MySavings;
    
    double start_balance, set_fee, set_dividend, set_rate;
    string myname = "Unnamed";

    cout << "Starting Balance (You will only see this upon initial start):" << endl;
    cout << "NOTE: For the purpose of this project, all fees and rates will be applied each time it is requested." << endl;
    cin >> start_balance;
    
    cout << "Set the fee for debit withdrawals" << endl;
    cin >> set_fee;
    
    cout << "Set the rate for savings maturity" << endl;
    cin >> set_dividend;
    
    cout << "Set the rate for credit interest (APR)" << endl;
    cin >> set_rate;
    
    cout << "Set the owner's name" << endl;
    cin >> myname;

    cout << "Building Accounts......" << endl;
        MyDebit.SetBalance(start_balance);
        MyCredit.SetBalance(start_balance);
        MySavings.SetBalance(start_balance);
        MyDebit.SetFee(set_fee);
        MyCredit.SetInterestRate(set_rate);
        MySavings.SetInterestRate(set_dividend);
        MyDebit.SetOwner(myname);
        MyCredit.SetOwner(myname);
        MySavings.SetOwner(myname);
    cout << "Build Success.\n\n\n\n" << endl;
    
    
    
    
    int decision = 1;
    int decision_two = 1;
     
    while(decision != 0) {
        
        cout << "Welcome to the MyFyre Banking System!\n"
                "Please choose an account...\n" << endl;
        cout << "[1] Checking    [3] Savings" << endl;
        cout << "[2] Credit      [0] Exit" << endl;
        
        cin >> decision;
        
        if (decision == 1) {
            cout << "MyFyre Banking Checking Account" << endl;
            cout << MyDebit.ToString() << endl;
            cout << "\n What would you like to do today?" << endl;
            cout << "[1] Deposit     [3] Cancel" << endl;
            cout << "[2] Withdrawal" << endl;
            cin >> decision_two;
            if(decision_two == 1) {
                double deposit = 0;
                cout << "Enter amount to DEPOSIT:" << endl;
                cin >> deposit;
                if(deposit < 0) {
                    cout << "Invalid Amount." << endl;
                } else {
                    MyDebit.Deposit(deposit);
                    cout << MyDebit.ToString() << endl;;
                }
            }
            else if (decision_two == 2) {
                double withdrawal = 0;
                cout << "Enter amount to WITHDRAW:" << endl;
                cin >> withdrawal;
                if(withdrawal < 0) {
                    cout << "Invalid Amount." << endl;
                } else {
                    MyDebit.Withdrawal(withdrawal);
                    cout << MyDebit.ToString() << endl;
                }
            } else {
                // Do nothing
            }
        }
        else if (decision == 2) {
            cout << "MyFyre Banking Savings Account" << endl;
            cout << MySavings.ToString() << endl;
            cout << "\n What would you like to do today?" << endl;
            cout << "[1] Deposit     [3] Cancel" << endl;
            cout << "[2] Withdrawal" << endl;
            cin >> decision_two;
            if(decision_two == 1) {
                double deposit = 0;
                cout << "Enter amount to DEPOSIT:" << endl;
                cin >> deposit;
                if(deposit < 0) {
                    cout << "Invalid Amount." << endl;
                } else {
                    MySavings.Deposit(deposit);
                    cout << MySavings.ToString() << endl;
                }
            }
            else if (decision_two == 2) {
                double withdrawal = 0;
                cout << "Enter amount to WITHDRAW:" << endl;
                cin >> withdrawal;
                if(withdrawal < 0) {
                    cout << "Invalid Amount." << endl;
                } else {
                    MySavings.Withdrawal(withdrawal);
                    cout << MySavings.ToString() << endl;
                }
            } else {
                // Do nothing
            }
        }
        else if (decision == 3) {
            cout << "MyFyre Banking Credit Account" << endl;
            cout << MyCredit.ToString() << endl;
            cout << "\n What would you like to do today?" << endl;
            cout << "[1] Charge Credit [3] Cancel" << endl;
            cout << "[2] Apply Payment" << endl;
            cin >> decision_two;
            if(decision_two == 1) {
                double deposit = 0;
                cout << "Enter amount to Charge:" << endl;
                cin >> deposit;
                if(deposit < 0) {
                    cout << "Invalid Amount." << endl;
                } else {
                    MyCredit.Deposit(deposit);
                    cout << MyCredit.ToString() << endl;
                }
            }
            else if (decision_two == 2) {
                double withdrawal = 0;
                cout << "Enter amount to pay towards balance:" << endl;
                cin >> withdrawal;
                if(withdrawal < 0) {
                    cout << "Invalid Amount." << endl;
                } else {
                    MyCredit.Withdrawal(withdrawal);
                    cout << MyCredit.ToString() << endl;
                }
            } else {
                // Do nothing
            }
        } else {
            cout << "Exiting...\n\n" << endl;
        }
    }
    cout << "Thank you for using MyFyre Bank!" << endl;
    cout << "Press any key to exit..." << endl;
    cin.get();
}