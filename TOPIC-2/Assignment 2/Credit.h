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
        Credit(const double, const double, const double);
        double GetInterestRate() const;
        void SetInterestRate(double interest);
        string ToString() const;
    private:
       double interest_;
};
#endif 