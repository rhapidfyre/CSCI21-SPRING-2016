 /*
 * Name        : Credit.h
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
 #include "Account.h"
 
 #ifndef CREDIT
 #define CREDIT
 
 
class Credit: public Account
{
    public:
        Credit();
        Credit(string owner, double balance, double interest);
        double GetInterestRate() const;
        void SetInterestRate(double interest);
        string ToString() const;
    protected:
       double interest_;
};
#endif 