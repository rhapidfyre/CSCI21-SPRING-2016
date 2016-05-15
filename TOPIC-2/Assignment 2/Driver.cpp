 /*
 * Name        : Account.cpp
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
#include "Account.h"
#include "Savings.h"
#include "Credit.h"
#include "Debit.h"
using namespace std;

void ATM {
    int decision = 0;
    cout << "Welcome to the MyFyre Banking System!\n"
            "Please choose an account...\n" << endl;
    cout << "[1] Checking    [3] Savings" << endl;
    cout << "[2] Credit      [0] Exit" << endl;
    cin >> decision;
    
    /*
     *
     *  Borrowed Russel's switch code for this as I wasn't sure how they worked.
     *  So instead of spending an hour researching I referenced what he completed.
     *
     */
     
    while(decision != 0) {
        switch (decision) {
                case 1:
                    Debit();
                    break;
                case 2:
                    Credit();
                    break;
                case 3:
                    Savings();
                    break;
                default:
                    break;
            }
        }
}