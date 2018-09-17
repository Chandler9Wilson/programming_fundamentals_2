/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 2:
  1. Provide menu-driven option loop that:
    * Creates a user defined size diamond*/
#include <iostream>
#include <string>

using namespace std;

// Function prototype per books suggestion see pg 334
void construct_diamond(int rows);
int sanitize_input(string input);

int main()
{
  while (true)
  {
    cout << "Enter number of rows in diamond (0 to quit): ";
    string user_input{'\0'};

    cin >> user_input;

    int user_number = sanitize_input(user_input);

    if (user_number == 0)
    {
      cout << endl
           << "Goodbye!" << endl;
      break;
    }
    else if (user_number < 0)
    {
      continue;
    }
    else if (user_number)
    {
      cout << user_number << " is a valid <int>" << endl;
    }
    else
    {
      cout << user_input << " is not a valid number of rows. Try again" << endl;
    }
  }
}

void construct_diamond(int row)
{
  cout << "A Diamond I swear" << endl;
}

int sanitize_input(string input)
{
  int converted_input{-1};

  try
  {
    converted_input = stoi(input);
  }
  catch (invalid_argument e)
  {
    cout << input << " is not a natural number. Try again" << endl;

    // Is returning 0 here counterintuitive to how most programs exit with 0 if successful?
    return -1;
  }
  catch (out_of_range e)
  {
    cout << input << " is too big. Try again" << endl;

    return -1;
  }

  // catch negative numbers
  if (converted_input < 0)
  {
    cout << input << " is not a natural number. Try again" << endl;

    return -1;
  }

  return converted_input;
}