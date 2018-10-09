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
double input(const double min_number, const double max_number, const string prompt, const string error_message)
{
}

// Gets one point and sets via reference
void input(double &x, double &y, const string prompt) {}

// Returns the distance between two letters in the alphabet
int distance_between(char first_letter, char second_letter)
{
  int first_ascii = tolower(first_letter);
  int second_ascii = tolower(second_letter);

  int distance = abs(first_ascii - second_ascii);

  return distance;
}

// Returns the distance between two numbers
double distance_between(double first_number, double second_number) {}

// Returns the distance between two points on a cartesian plane
double distance_between(double first_point_x, double first_point_y, double second_point_x, double second_point_y) {}

// Display two letters and the distance between
void display(const string &message, char first_letter, char second_letter)
{
  int distance = distance_between(first_letter, second_letter);

  cout << message << first_letter << " and " << second_letter << " is " << distance << endl;
}
// Use static local variable to keep count of how many times called

// Display two numbers and the distance between
void display(const string &message, double first_number, double second_number) {}
// Use static local variable to keep count of how many times called

// Display two points and the distance between
void display(const string &message, double first_point_x, double first_point_y, double second_point_x, double second_point_y) {}
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
      string display_message = "  The distance between letters ";

      char first_letter = input(first_letter_prompt, error_message);
      char second_letter = input(second_letter_prompt, error_message);

      display(display_message, first_letter, second_letter);
    }
    else if (option == 'n')
    {
    }
    else if (option == 'p')
    {
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