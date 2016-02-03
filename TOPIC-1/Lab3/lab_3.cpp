/*
 * Name        : lab_3.cpp
 * Author      : Michael Harris
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include "lab_3.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */
string Goldilocks(string item, int number) {
  if(item == "porridge"){if(number == 1){return "This porridge is too hot";}
  if(number == 2){return "This porridge is too cold";}
  if(number == 3){return "This porridge is just right";}
  else{return "Invalid Number";}}
  if(item == "chair"){if(number == 1){return "This chair is too big";}
  if(number == 2){return "This chair is too small";}
  if(number == 3){return "This chair is just right";}
  else{return "Invalid Number";}}
  if(item == "bed"){if(number == 1){return "This bed is too hard";}
  if(number == 2){return "This bed is too soft";}
  if(number == 3){return "This bed is just right";}
  else{return "Invalid Selection";}}
  else{return "You did not spell it correctly or chose something not listed.";}
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw,
 *               0 if invalud inputs
 */
int RockScissorPaper(char player_one, char player_two) {
  // Switch Reference: http://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm
  switch(player_one)
  {
    case 'R':player_one == 'R';break;
    case 'P':player_one == 'P';break;
    case 'S':player_one == 'S';break;
  }
  switch(player_two)
  {
    case 'R':player_one == 'R';break;
    case 'P':player_one == 'P';break;
    case 'S':player_one == 'S';break;
  }
  if(player_one == 'R')
  {
    if(player_two == 'R'){return 3;}
    else if(player_two == 'P'){return 2;}
    else if(player_two == 'S'){return 1;}
    else{return 0;}
  }
  else if(player_one == 'P')
  {
    if(player_two == 'R'){return 2;}
    else if(player_two == 'P'){return 3;}
    else if(player_two == 'S'){return 1;}
    else{return 0;}
  }
  else if(player_one == 'S')
  {
    if(player_two == 'R'){return 2;}
    else if(player_two == 'P'){return 1;}
    else if(player_two == 'S'){return 3;}
    else{return 0;}
  }
  else{return 0;}
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {
  string convert = "";
 for(int i = 0; i < input.size(); i++)
 {
   convert += tolower(input[i]);
 }
 return convert;
}


/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  string convert = "";
 for(int i = 0; i < input.size(); i++)
 {
   // I found += on cplusplus operators.
   // Instead of doing VARIABLE = VARIABLE + 1, you just use VARIABLE += 1.
   convert += toupper(input[i]);
 }
 return convert;
}

int main()
{
    string convert = "String";
    string input;
    char player_one;
    char player_two;
    string player_one_convert;
    string player_two_convert;
    string item;
    int number = 1;
    
    while(number != 0)
    {
      cout << "\n\nTime to tell the story of Goldilocks! Pick \"porridge\", \"chair\", or \"bed\"." << endl;
      cin >> item;
      
      cout << "\nGreat! Now pick one of the following...\n[1] Result 1      [2] Result 2      [3] Result 3      [0] Exit" << endl;
      cin >> number;
      
      cout << Goldilocks(item,number);
    }
    
    cout << "ROCK PAPER SCISSORS!" <<endl;
    cout << "Player 1: [R] Rock    [S] Scissors   [P] Paper" << endl;
    cin >> input;
    ToUpper(input);
    input = ToUpper(input);
    player_one = input[0];
    
    cout << "Player 2: [R] Rock    [S] Scissors   [P] Paper" << endl;
    cin >> input;
    ToUpper(input);
    input = ToUpper(input);
    player_two = input[0];\
    
    cout << player_one << player_two << "      DEBUG" << endl;
    // Show results
    cout << "GAME RESULTS: \n" << RockScissorPaper(player_one,player_two);
    
}