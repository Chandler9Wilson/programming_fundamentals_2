/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 6:
  1. Use functions
  2. Use function overloading
  3. Use pass-by-value and pass-by-reference
  4. Use static local variables
  5. Use default parameters
  6. Use const parameters*/
#include <iostream>
#include <string>

using namespace std;

// Gets a letter and returns letter
char input(const string prompt, const string error_message);

// Gets a number and returns a number
double input(const double min_number, const double max_number, const string prompt, const string error_message);

// Gets one point and sets via reference
void input(double &x, double &y, const string prompt);

// Returns the distance between two letters in the alphabet
int distance_between(char first_letter, char second_letter);

// Returns the distance between two numbers
double distance_between(double first_number, double second_number);

// Returns the distance between two points on a cartesian plane
double distance_between(double first_point_x, double first_point_y, double second_point_x, double second_point_y);

// Display two letters and the distance between
void display(const string &message, char ch1, char ch2);

// Display two numbers and the distance between
void display(const string &message, double first_number, double second_number);

// Display two points and the distance between
void display(const string &message, double first_point_x, double first_point_y, double second_point_x, double second_point_y);

int main()
{
  // Greeting message
  cout << "Display the distance between two items: letters, numbers, or points." << endl
       << endl;
}