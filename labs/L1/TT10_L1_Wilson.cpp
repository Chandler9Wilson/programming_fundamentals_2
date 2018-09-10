/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 1:
  1. Provide menu-driven option loop that:
    * Calculates restaurant bill
    * Calculates BMI
    * Quits the loop */
#include <iostream>

using namespace std;

int calculate_bill()
{
  cout << "What was the cost of the food?: $";
  double food_cost{0};
  cin >> food_cost;

  cout << "What percent would you like to tip? (whole number): ";
  double tip_percent{0};
  cin >> tip_percent;

  const double tax_rate = 0.0825;

  double bill_no_tip = food_cost + (food_cost * tax_rate);
  // Based tip on bill w/ tax
  double bill_total = food_cost * (tip_percent / 100) + bill_no_tip;

  cout << bill_total << endl;
}

int main()
{
  while (true)
  {
    cout << "Options: a) Amount of restaurant bill; b) BMI; q) Quit: ";
    char option{' '};
    cin >> option;

    if (option == 'a')
    {
      calculate_bill();
    }
    else if (option == 'b')
    {
      break;
    }
    else if (option == 'q')
    {
      break;
    }
    else
    {
      cout << option + " Is not a valid option. Try again";
    }
  }
}