/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 1:
  1. Provide menu-driven option loop that:
    * Calculates restaurant bill
    * Calculates BMI
    * Quits the loop */
#include <iostream>
#include <iomanip>

using namespace std;

int calculate_bill()
{
  cout << "  What was the cost of the food?: $";
  double food_cost{0};
  cin >> food_cost;

  cout << "  What percent would you like to tip? (e.g. 10 is 10%): ";
  double tip_percent{0};
  cin >> tip_percent;

  const double tax_rate = 0.0825;

  double bill_no_tip = food_cost + (food_cost * tax_rate);
  // Based tip on bill w/ tax
  double bill_total = food_cost * (tip_percent / 100) + bill_no_tip;

  // Surely there is a better way to do this? taken from pg 113
  cout << "  Your total bill is $" << fixed << showpoint << setprecision(2) << bill_total << endl;
}

int calculate_bmi()
{
  cout << "  What is your weight in pounds?: ";
  double weight{0};
  cin >> weight;

  cout << "  What is your height in inches?: ";
  double height{0};
  cin >> height;

  double bmi = (weight / (height * height)) * 703;
  cout << "  Your BMI is: " << fixed << showpoint << setprecision(2) << bmi << endl;
}

int main()
{
  while (true)
  {
    cout << "Options: a) Amount of restaurant bill; b) BMI; q) Quit: ";
    char option{'\0'};

    cin >> option;

    option = tolower(option);

    if (option == 'a')
    {
      calculate_bill();
    }
    else if (option == 'b')
    {
      calculate_bmi();
    }
    else if (option == 'q')
    {
      break;
    }
    else
    {
      cout << option << " Is not a valid option. Try again" << endl;
    }
  }
}

/* Test output:
Options: a) Amount of restaurant bill; b) BMI; q) Quit: a
  What was the cost of the food?: $10.00
  What percent would you like to tip? (e.g. 10 is 10%): 10
  Your total bill is $11.82
Options: a) Amount of restaurant bill; b) BMI; q) Quit: b
  What is your weight in pounds?: 150
  What is your height in inches?: 60
  Your BMI is: 29.29
Options: a) Amount of restaurant bill; b) BMI; q) Quit: j
j Is not a valid option. Try again
Options: a) Amount of restaurant bill; b) BMI; q) Quit: jfk
j Is not a valid option. Try again
Options: a) Amount of restaurant bill; b) BMI; q) Quit: f Is not a valid option. Try again
Options: a) Amount of restaurant bill; b) BMI; q) Quit: k Is not a valid option. Try again
Options: a) Amount of restaurant bill; b) BMI; q) Quit: A
  What was the cost of the food?: $10
  What percent would you like to tip? (e.g. 10 is 10%): 10
  Your total bill is $11.82
Options: a) Amount of restaurant bill; b) BMI; q) Quit: q */