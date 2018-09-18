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

public:
  Diamond(int r = 7)
  {
    rows = r;
  };

  string diamond_str();
};

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
      // cout << user_number << " is a valid <int>" << endl;
      Diamond user_diamond(user_number);
      user_diamond.diamond_str();
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

string Diamond::diamond_str()
{
  int center_point = (rows / 2) + 1;
  string end_diamond{"\0"};

  // cout << "center point is: " << center_point << endl;

  for (int i = 1; i <= rows; i++)
  {
    int space_count = abs(center_point - i);
    // cout << "space_count is : " << space_count << endl;
    int star_count = rows - (space_count * 2);
    // cout << "star_count is : " << star_count << endl;

    end_diamond += (string(space_count, ' ') + string(star_count, '*') + "\n");
  }

  cout << end_diamond;
}