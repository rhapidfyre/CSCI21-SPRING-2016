 /*
 * Name        : Debit.h
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
 #include "Account.h"

 #ifndef DEBIT
 #define DEBIT
 
class Checking: public Account
{
    public:
        Checking();
        Checking(const double, const double, const double);
        double GetFee() const;
        void SetFee(double fee);
        string ToString() const;
    private:
       double fee_;
};

#endif 