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
int sanitize_input(string input);

class Diamond
{
private:
  int rows;

  string even_to_string();
  string odd_to_string();

public:
  // init constructor
  Diamond(int r = 7)
  {
    rows = r;
  };

  string to_string();
};

// main here after prototypes, or at the end of the file?
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
      Diamond user_diamond(user_number);
      cout << user_diamond.to_string();
    }
    else
    {
      cout << user_input << " is not a valid number of rows. Try again" << endl;
    }
  }
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

    // returns a failure state of -1
    return converted_input;
  }
  catch (out_of_range e)
  {
    cout << input << " is too big. Try again" << endl;

    // returns a failure state of -1
    return converted_input;
  }

  // catch negative numbers
  if (converted_input < 0)
  {
    cout << input << " is not a natural number. Try again" << endl;

    return -1;
  }

  return converted_input;
}

// Generate diamonds with an even number of rows
string Diamond::even_to_string()
{
  // makes even numbers odd (not the best solution i know)
  rows -= 1;

  return odd_to_string();
}

// Generate diamonds with an odd number of rows
string Diamond::odd_to_string()
{
  // odd mean
  int center_point = ((rows + 1) / 2);
  string end_diamond{"\0"};

  for (int i = 1; i <= rows; i++)
  {
    int space_count = abs(center_point - i);
    int star_count = rows - (space_count * 2);

    end_diamond += (string(space_count, ' ') + string(star_count, '*') + "\n");
  }

  return end_diamond;
}

string Diamond::to_string()
{
  // if even
  if (!(rows % 2))
  {
    return even_to_string();
  }
  else
  {
    return odd_to_string();
  }
}

/* Test output:
Enter number of rows in diamond (0 to quit): abcd
abcd is not a natural number. Try again
Enter number of rows in diamond (0 to quit): 13223132321233223132123
13223132321233223132123 is too big. Try again
Enter number of rows in diamond (0 to quit): 3
 *
***
 *
Enter number of rows in diamond (0 to quit): 7
   *
  ***
 *****
*******
 *****
  ***
   *
Enter number of rows in diamond (0 to quit): 7.2
   *
  ***
 *****
*******
 *****
  ***
   *
Enter number of rows in diamond (0 to quit): 0

Goodbye! */