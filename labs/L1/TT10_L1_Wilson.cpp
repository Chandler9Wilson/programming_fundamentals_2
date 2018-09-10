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

int main()
{
  while (true)
  {
    cout << "Options: a) Amount of restaurant bill; b) BMI; q) Quit: ";
    char option{' '};
    cin >> option;

    if (option == 'a')
    {
      break;
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