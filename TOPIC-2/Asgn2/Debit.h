 /*
 * Name        : Debit.h
 * Author      : Michael Harris
 * Assignment  : Assignment #2
 */
 
 #include "Account.h"

 #ifndef DEBIT
 #define DEBIT
 
class Debit: public Account
{
    public:
        Debit();
        Debit(string owner, double balance, double fee);
        double GetFee() const;
        void SetFee(double fee);
        string ToString() const;
    private:
       double fee_;
};

#endif 