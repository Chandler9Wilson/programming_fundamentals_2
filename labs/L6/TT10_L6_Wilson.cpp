/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 6:
  X 1. Use functions
  X 2. Use function overloading
  X 3. Use pass-by-value and pass-by-reference
  X 4. Use static local variables
  5. Use default parameters (possibly combine two display and distance_between using defaults?)
  X 6. Use const parameters*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Gets a letter and returns letter
char input(const string prompt, const string error_message)
{
  while (true)
  {
    cout << prompt;

    char letter{'\0'};
    cin >> letter;

    letter = tolower(letter);

    if (!isalpha(letter))
    {
      // if the first character is not alpha ignore the rest of the input
      cin.clear();
      cin.ignore(256, '\n');

      cout << error_message << endl;

      continue;
    }
    else
    {
      return letter;
    }
  }
}

// Gets a number and returns a number
double input(const string prompt, const string error_message, const double min_number, const double max_number)
{
  while (true)
  {
    cout << prompt;

    double user_number{0.0};

    if (cin >> user_number)
    {
      if (user_number >= min_number and user_number <= max_number)
      {
        return user_number;
      }
    }
    else
    {
      cout << error_message << endl;

      cin.clear();
      cin.ignore(10000, '\n');
      continue;
    }
  }
}

// Gets one point and sets via reference
void input(double &x, double &y, const string prompt)
{
  int min_number = -100;
  int max_number = 100;
  string x_prompt = prompt + "(x): ";
  string y_prompt = prompt + "(y): ";
  string error_message = "Error: Please enter a number between -100 and 100";

  x = input(x_prompt, error_message, min_number, max_number);
  y = input(y_prompt, error_message, min_number, max_number);
}

// Returns the distance between two letters in the alphabet
int distance_between(char first_letter, char second_letter)
{
  // forces the char into an int aka gets the ascii code
  int first_ascii = tolower(first_letter);
  int second_ascii = tolower(second_letter);

  int distance = abs(first_ascii - second_ascii);

  return distance;
}

// Returns the distance between two numbers
double distance_between(double first_number, double second_number)
{
  double distance = abs(first_number - second_number);

  return distance;
}

// Returns the distance between two points on a cartesian plane
double distance_between(double first_point_x, double first_point_y, double second_point_x, double second_point_y)
{
  // Equation for finding the distance between two points
  double distance = sqrt(pow((first_point_x - second_point_x), 2) + pow((first_point_y - second_point_y), 2));

  return distance;
}

// Display two letters and the distance between
void display(const string &message, char first_letter, char second_letter)
{
  static int call_count = 0;
  ++call_count;

  int distance = distance_between(first_letter, second_letter);

  cout << "  (#" << call_count << ") " << message << first_letter << " and "
       << second_letter << " is " << distance << endl;
}
// Use static local variable to keep count of how many times called

// Display two numbers and the distance between
void display(const string &message, double first_number, double second_number)
{
  static int call_count = 0;
  ++call_count;

  double distance = distance_between(first_number, second_number);

  cout << "  (#" << call_count << ") " << message << first_number << " and "
       << second_number << " is " << distance << endl;
}
// Use static local variable to keep count of how many times called

// Display two points and the distance between
void display(const string &message, double first_point_x, double first_point_y, double second_point_x, double second_point_y)
{
  static int call_count = 0;
  ++call_count;

  double distance = distance_between(first_point_x, first_point_y, second_point_x, second_point_y);

  cout << "  (#" << call_count << ") " << message << "(" << first_point_x << ", "
       << first_point_y << ") and (" << second_point_x << ", " << second_point_y
       << ") is " << distance << endl;
}
// Use static local variable to keep count of how many times called

int main()
{
  // Greeting message
  cout << "Display the distance between two items: letters, numbers, or points." << endl
       << endl;

  while (true)
  {
    cout << "Options: l)etter; n)umber; p)oint; q)uit: ";

    char option{'\0'};
    cin >> option;

    option = tolower(option);

    if (!isalpha(option))
    {
      cout << "Please enter a letter" << endl;

      continue;
    }
    else if (option == 'l')
    {
      string first_letter_prompt = "  Please enter the first letter: ";
      string second_letter_prompt = "  Please enter the second letter: ";
      string error_message = "  Error: Please enter a single alphabetic character";
      string display_message = "The distance between letters ";

      char first_letter = input(first_letter_prompt, error_message);
      char second_letter = input(second_letter_prompt, error_message);

      display(display_message, first_letter, second_letter);
    }
    else if (option == 'n')
    {
      int min_number = -100;
      int max_number = 100;
      string first_number_prompt = " Please enter the first number: ";
      string second_number_prompt = " Please enter the second number: ";
      string error_message = " Error: Please enter a number between -100 and 100";
      string display_message = "The distance between numbers ";

      double first_number = input(first_number_prompt, error_message, min_number, max_number);
      double second_number = input(second_number_prompt, error_message, min_number, max_number);

      display(display_message, first_number, second_number);
    }
    else if (option == 'p')
    {
      double first_point_x{0};
      double first_point_y{0};
      double second_point_x{0};
      double second_point_y{0};
      string first_point_prompt = "  Enter the first point ";
      string second_point_prompt = "  Enter the second point ";
      string display_message = "Straight line distance between points ";

      input(first_point_x, first_point_y, first_point_prompt);
      input(second_point_x, second_point_y, second_point_prompt);

      display(display_message, first_point_x, first_point_y, second_point_x, second_point_y);
    }
    else if (option == 'q')
    {
      cout << endl
           << "Goodbye!" << endl;
      break;
    }
    else
    {
      cout << option << " Is not a valid option. Try again" << endl;
    }
  }
}

/* Test Output:
Display the distance between two items: letters, numbers, or points.

Options: l)etter; n)umber; p)oint; q)uit: l
  Please enter the first letter: a
  Please enter the second letter: b
  (#1) The distance between letters a and b is 1
Options: l)etter; n)umber; p)oint; q)uit: l
  Please enter the first letter: A
  Please enter the second letter: d
  (#2) The distance between letters a and d is 3
Options: l)etter; n)umber; p)oint; q)uit: n
 Please enter the first number: -5.5
 Please enter the second number: 20.5
  (#1) The distance between numbers -5.5 and 20.5 is 26
Options: l)etter; n)umber; p)oint; q)uit: n
 Please enter the first number: 10
 Please enter the second number: 50
  (#2) The distance between numbers 10 and 50 is 40
Options: l)etter; n)umber; p)oint; q)uit: P
  Enter the first point (x): 0
  Enter the first point (y): 0
  Enter the second point (x): 1
  Enter the second point (y): 1
  (#1) Straight line distance between points (0, 0) and (1, 1) is 1.41421
Options: l)etter; n)umber; p)oint; q)uit: q

Goodbye! */