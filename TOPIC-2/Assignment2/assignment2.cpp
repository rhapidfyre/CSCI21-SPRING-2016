/*
    Assignment: Assignment 2 (ATM)
    Author:     Michael Harris
    Credit:     None Thus Far

*/

#include 'assignment2.h'

// Definition of our Functions


// Start the function called "ATM"
int ATM()
{
    // Declare Vars
    int account_type; = 1;
    int start_balance_checking = 0;
    int start_balance_savings = 0;
    int start_balance_credit = 0;
    double start_balance_rate = 0;
    double start_balance_dividend = 0;
    double atm_rate = 0;
    
    // Create Classes
    cout << "Insert Starting Amount in Checking" << endl;
    cin >> start_balance_checking;
    cout << "Insert Starting Amount in Savings" << endl;
    cin >> start_balance_savings;
    cout << "Insert Starting Credit Debt" << endl;
    cin >> start_balance_credit;
    cout << "Insert Starting Credit Interest Rate" << endl;
    cin >> start_balance_rate;
    cout << "Insert Starting Savings Dividend Rate" << endl;
    cin >> start_balance_dividend;
    cout << "Insert ATM Fee" << endl;
    cin >> atm_rate;
    
    account MyAccount;
    debit MyDebit;
    credit MyCredit;
    savings MySavings;
    
    // Turn our amounts into dollars/cents separated for accuracy
    int start_dollars = (start_balance_checking * 100) / 100;
    int start_cents = (start_balance_checking * 100) % 100;
    MyDebit.Debit(start_dollars, start_cents, atm_rate);
    
    start_dollars = (start_balance_credit * 100) / 100;
    start_cents = (start_balance_credit * 100) % 100;
    MyCredit.Credit(start_dollars, start_cents, start_balance_rate);
    
    start_dollars = (start_balance_savings * 100) / 100;
    start_cents = (start_balance_savings * 100) % 100;
    MySavings.Savings(start_dollars, start_cents, start_balance_dividend);
    
    // Free up the memory from the no longer necessary vars
    start_balance_checking.clear();
    start_balance_credit.clear();
    start_balance_dividend.clear();
    start_balance_rate.clear();
    start_balance_savings.clear();
    atm_rate.clear();
    start_dollars.clear();
    start_cents.clear();
    
    // Greet the User
    cout << "Welcome to MyRhapidFyre Account!\nPress any key to continue..." << endl;
    cin >> cin.get();
    
    // PIN number for immersion
    cout << "Please enter your PIN number (for the purpose of this project any number will work)\n";
    cin >> cin.get();
    
        
    while(account_type != 0)
    {
        int prompt = 0;
        // Request Account Type
        cout << "\n\n\n\n\n\n" << endl;
        cout << "[1] - Checking Account\n[2] - Savings Account\n[3] - Credit Account\n[0] - Cancel/Return" << endl;
        cin >> account_type;
        
        // Account Type Catch
        if(account_Type == 1)
        {
            // User Input
            cout << "ACCOUNT TYPE: Checking\n" << endl;
            cout << "[0] Cancel/Return\n[1] - Balance Inquiry\n[2] - Withdrawal\n[3] - Deposit\n" << endl;
            cin >> prompt;
            if (prompt == 1)
            {
                cout << "MyRhapidFyre Checking Account\nCURRENT BALANCE: $" << MyDebit.GetBalance();
            }
            else if (prompt == 2)
            {
                cout << "MyRhapidFyre Checking Account\nCURRENT BALANCE: $" << MyDebit.GetBalance();
            }
            else
            {
                
            }
            
            // Run the Checking Class and make changes
            
        }
        else if(account_type == 2)
        
        {
            cout << "ACCOUNT TYPE: Savings\n" << endl;
            cout << "[0] Cancel/Return\n[1] - Balance Inquiry\n[1] - Withdrawal\n[2] - Deposit\n" << endl;
            cin >> prompt;
            if (prompt == 1)
            {
                cout << "MyRhapidFyre Savings Account\nCURRENT BALANCE: $" << MySavings.GetBalance();
            }
            else if (prompt == 2)
            {
                
            }
            else
            {
                
            }
            
        }
        else if(account_type == 3)
        {
            cout << "ACCOUNT TYPE: Credit\n" << endl;
            cout << "[0] Cancel/Return\n[1] - Balance Inquiry\n[1] - Withdrawal\n[2] - Deposit\n" << endl;
            cin >> prompt;
            if (prompt == 1)
            {
                cout << "MyRhapidFyre Credit Account\nCURRENT BALANCE DUE: $" << MyCredit.GetBalance();
            }
            else if (prompt == 2)
            {
                
            }
            else
            {
                
            }
            
        }
        else
        {
            // All other options, cancel
            cout << "Canceling..." << endl;
        }
        
        // Restart or End Prompt
        cout << "Do you have any other requests?\n[0] - No\n[1] - Yes"
        cin >> account_type;
        if(account_type == 0)
        {
            cout << "Thank you for using MyRhapidFyre Account." << endl;
        }
    }
    
}