#include "money.h"

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents)
      : dollars_(dollars),
        cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
  dollars_ = dollars;
}

void Money::set_cents(int cents) {
  cents_ = cents;
}

// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// REST OF CLASS FUNCTION DEFINITIONS GO HERE
const Money operator -(const Money& amount1, const Money& amount2)
{
  int ttl1 = amount1.cents_ + amount1.dollars_ * 100;
  int ttl2 = amount2.cents_ + amount2.dollars_ * 100;
  int ttl = ttl1 - ttl2;
  int absttl = abs(ttl);
  int final_dollars = absttl / 100;
  int final_cents = absttl % 100;
  if (ttl < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

bool operator ==(const Money &amount1, const Money &amount2)
{
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  if(all_cents1 == all_cents2) {return true;} else {return false;}
}

const Money operator -(const Money &amount)
{
  int sum_all = amount.cents_ + amount.dollars_ * 100;
  int abs_all = abs(sum_all);
  int final_dollars = abs_all / 100;
  int final_cents = abs_all % 100;
  if (sum_all < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  final_dollars = final_dollars * (-1);
  final_cents = final_cents * (-1);
  return Money(final_dollars, final_cents); 
}

ostream& operator <<(ostream &out, const Money &amount)
{
  bool negative;
  int sum_all = amount.cents_ + amount.dollars_ * 100;
  int abs_all = abs(sum_all);
  int final_dollars = abs_all / 100;
  int final_cents = abs_all % 100;
  if (sum_all < 0) {
    negative = true;
  }
  else
  {
    negative = false;
  }
  if (negative == true)
  {
    out.precision(2);
    out.setf(ios::fixed);
    out << "$-" << final_dollars << "." << setfill('0') << setw(2) << final_cents;
  }
  else
  {
    out.precision(2);
    out.setf(ios::fixed);
    out << "$" << final_dollars << "." << setfill('0') << setw(2) << final_cents;
  }
  return out;
}