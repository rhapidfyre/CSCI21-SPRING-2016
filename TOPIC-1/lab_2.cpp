/*
 * Name        : lab_2.cpp
 * Author      : Michael Harris
 * Description : Using Arithmetic to finish the functions MakeChange() and
 *               LaunchHumanCannonball()
 * Sources     :
 */

// Please note the header above. You need to include the name of the file, the
// author, a description of the program and any sources used
#include "lab_2.h"
#include <cmath>
using namespace std;


/*
 * Given an initial integer value (representing change to be given, such as in a
 * financial transaction), break the value down into the number of quarters,
 * dimes, nickels, and pennies that would be given as change.
 * @param int initial_value - The amount of change to be broken down in pennies.
 * @param int quarters  - The number of quarters that come out of initial_value
 * @param int dimes - The number of dimes that come out of initial_value,
 *                    after quarters have been taken out
 * @param int nickels - The number of nickels that come out of initial_value,
 *                      after quarters and dimes have been taken out
 * @param int pennies - The number of pennies that come out of initial_value,
 *                      after quarters, dimes, and nickels have been taken out
 */
void MakeChange(int initial_value, int &quarters, int &dimes, int &nickels, int &pennies)
{
  // Take the total amount of value, create a running total placeholder
  int running_total = initial_value;
  
  // Use the quarters variable to break each dollar amount
  // I used a WHILE loop because I was receiving "Invalid Operand %"
  while(running_total >= 25)
  {
    running_total = running_total - 25;
    quarters = quarters + 1;
  }
  // CATCH: If there are quarters, give a total.
  if(quarters > 0)
  {
    float quarters_price;
    quarters_price = quarters * 0.25;
    cout << quarters << " quarters exchanged from " << initial_value << " pennies, which totals $" << quarters_price << " in quarters." << endl;
  }
  // If there are no quarters, report there are no quarters and move to dimes.
  else
  {
    cout << "No quarters were created from the total given." << endl;;
  }
  // Repeat counter for dimes
  while(running_total >= 10)
  {
    running_total = running_total - 10;
    dimes = dimes + 1;
  }
  // CATCH: If there are dimes, give a total.
  if(dimes > 0)
  {
    float dimes_price;
    dimes_price = dimes * 0.1;
    cout << dimes << " dimes exchanged from " << initial_value << " pennies, which totals $" << dimes_price << " in dimes." << endl;
  }
  // If there are no dimes, report there are no dimes, and move to nickels.
  else
  {
    cout << "No dimes were created from the total given." << endl;
  }
  // Repeat counter for nickels
  while(running_total >= 5)
  {
    running_total = running_total - 5;
    nickels = nickels + 1;
  }
  // CATCH: If there are dimes, give a total.
  if(nickels > 0)
  {
    float nickels_price;
    nickels_price = nickels * 0.05;
    cout << nickels << " nickels exchanged from " << initial_value << " pennies, which totals $" << nickels_price << " in nickels." << endl;
  }
  // If there are no nickels, report there are no nickels, and move to pennies.
  else
  {
    cout << "No nickels were created from the total given." << endl;
  }
  // Repeat counter for pennies
  while(running_total >= 1)
  {
    running_total = running_total - 1;
    pennies = pennies + 1;
  }
  // CATCH: If there are dimes, give a total.
  if(pennies > 0)
  {
    float pennies_price;
    pennies_price = pennies * 0.01;
    cout << pennies << " pennies exchanged from " << initial_value << " pennies, which totals $" << pennies_price << " in pennies." << endl;
  }
  // If there are no dimes, report there are no dimes, and move to nickels.
  else
  {
    cout << "No pennies were created from the total given." << endl;
  }
  
  // Just incase the running total isn't completely used up to 0, OR if it goes negative, we're adding this if/else statement.
  if(running_total == 0)
  {
    cout << "Total Remaining: " << running_total << endl;
    cout << "\nQ: " << quarters << "\nD: " << dimes << "\nN: " << nickels << "\nP: " << pennies << endl;
  }
  else
  {
    cout << "Your calculator thingy majigger did not function correctly." << endl;
    cout << "Total Remaining: " << running_total << endl;
    cout << "\nQ: " << quarters << "\nD: " << dimes << "\nN: " << nickels << "\nP: " << pennies << endl;
  }
};

/*
 * Computes the horizontal distance traveled by a human cannonball given an
 * initial velocity and launch angle. Simplified -- does not account for many
 * factors that affect projectile motion.
 * @param double initial_velocity - Represents the initial velocity of the
 *                                  human cannonball in meters/second
 * @param double launch_angle -  Represents the launch angle of the human
 *                               cannonball in degrees
 * @return double  - Represents the horizontal distance the human cannonball
 *                   will travel
 */
double LaunchHumanCannonball(double initial_velocity, double launch_angle) {
  
  // Declaring variables
  double radian_angle,x_velocity,y_velocity,flight_time,x_distance;
  
  // (1) Convert launch_angle from degrees to radians
  //     [radian_angle = launch_angle * (kPI/180)]
  radian_angle = launch_angle * (kPI/180);

  // (2) Compute final horizontal/x velocity
  //     [x_velocity = initial_velocity * cos(radian_angle)]
  x_velocity = initial_velocity * cos(radian_angle);

  // (3) Compute final vertical/y velocity
  //     [y_velocity = initial_velocity * sin(radian_angle) * -1]
  y_velocity = initial_velocity * sin(radian_angle) * -1;

  // (4) Compute time of flight
  //     [flight_time = (y_velocity) * 2 / -9.8]
  flight_time = (y_velocity) * 2 / -9.8;

  // (5) Compute horizontal/x distance traveled
  //     [x_distance = x_velocity * flight_time]
  x_distance = x_velocity * flight_time;
  
  // (6) Return horizontal/x distance
  return x_distance;
};

int main ()
{
  //Declare Variables
  int initial_value = 0;
  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;
  int launch_angle = 0;
  int initial_velocity = 0;
  
  
  cout << "Time to make change!" << "\n" << "How much (in pennies) am I changing out for you today?" << endl;
  cin >> initial_value;
  
  MakeChange(initial_value,quarters,dimes,nickels,pennies);
  cout << "\n\n\n\n" << endl;
  
  cout << "Time teh' turn ye'self inteh a cannonball fer me pirate crew." << endl;
  cout << "Gimme yer angle of launchin' from me cannon." << endl;
  cin >> launch_angle;
  
  cout << "So we be launchin' at " << launch_angle << "degrees, I like yeh style." << endl;
  cout << "How strong shall the cannon be launchin' yeh?" << endl;
  cin >> initial_velocity;
  
  cout << "It was a miss! Ye' ain' no cannonball, yer food for teh fishes!"<<"\n"<<"Ye' traveled: " << LaunchHumanCannonball(initial_velocity,launch_angle) << " and splashed into the ocean blue!" << endl;
}