/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 3:
  1. Provide menu-driven option loop that:
    * Ask a user defined number of questions
    * Option to quit at any time via sentinel
    * Keep track of question stats*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

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

int collect_problems_number()
{
  while (true)
  {
    cout << "How many problems would you like? (0 to quit now): ";
    string user_input{'\0'};

    cin >> user_input;

    int user_number = sanitize_input(user_input);

    if (user_number == 0)
    {
      cout << endl
           << "Goodbye!" << endl;
      return 0;
    }
    else if (user_number < 0)
    {
      continue;
    }
    else if (user_number)
    {
      return user_number;
    }
    else
    {
      cout << user_input << " is not a valid number of questions. Try again" << endl;
    }
  }
}

bool check_addition(int first_number, int second_number)
{
  int result = first_number + second_number;

  if (result >= 0 and result <= 100)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void generate_problems(int number_of_problems)
{
  for (int i = 1; i <= number_of_problems; i++)
  {
    cout << "This is problem " << i << endl;

    // setup vars
    int MAX{100};
    int first_number{0};
    int second_number{0};
    bool not_valid_problem = true;

    // Seed random generator
    unsigned seed = time(0);
    srand(seed);

    while (not_valid_problem)
    {
      first_number = rand() % MAX + 1;
      second_number = rand() % MAX + 1;

      if (check_addition(first_number, second_number))
      {
        not_valid_problem = false;
      }
    }

    // Interactive problem
    string attempt_input{"\0"};

    cout << first_number << " + " << second_number << " = ";
    cin >> attempt_input;

    int attempt_number = sanitize_input(attempt_input);

    cout << "You answered " << attempt_number << endl;
  }
}

int main()
{
  int number_of_problems = collect_problems_number();

  if (number_of_problems)
  {
    generate_problems(number_of_problems);
  }

  return 0;
}