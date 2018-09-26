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
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Problem
{
private:
  int first_number;
  int second_number;
  int operation;

  int addition_problem();

public:
  // init constructor
  Problem()
  {
    change_problem();
  };

  int get_first_number()
  {
    return first_number;
  }

  int get_second_number()
  {
    return second_number;
  }

  char get_operation()
  {
    switch (operation)
    {
    case 1:
      return '+';
      break;
    case 2:
      return '-';
      break;
    case 3:
      return '*';
      break;
    case 4:
      return '/';
      break;
    default:
      return '+';
      break;
    }
  }

  // Returns the correct answer if a natural number, will return -1 if not.
  int correct_answer()
  {
    double answer{-1};

    switch (operation)
    {
    case 1:
      answer = first_number + second_number;
      break;
    case 2:
      answer = first_number - second_number;
      break;
    case 3:
      answer = first_number * second_number;
      break;
    case 4:
      // Cast to double to catch fractional problems later
      answer = static_cast<double>(first_number) / static_cast<double>(second_number);
      break;
    default:
      answer = first_number + second_number;
      break;
    }

    // check if answer is whole number
    if (floor(answer) == answer)
    {
      return answer;
    }
    else
    {
      // return failure state of -1
      return -1;
    }
  }

  int change_problem()
  {
    // Seed random generator
    unsigned seed = time(0);
    srand(seed);

    const int NUMBER_OF_OPERATIONS{4};
    const int MAX_NUMBER{100};
    bool valid_problem{false};

    while (!valid_problem)
    {
      // randomly select an operation
      operation = rand() % NUMBER_OF_OPERATIONS + 1;

      first_number = rand() % MAX_NUMBER + 1;
      second_number = rand() % MAX_NUMBER + 1;

      if (correct_answer() >= 0 and correct_answer() <= 100)
      {
        valid_problem = true;
      }
    }
  }
};

// Utility function to convert string input to int
int sanitize_input(string input)
{
  int converted_input{-2};

  try
  {
    converted_input = stoi(input);
  }
  catch (invalid_argument e)
  {
    // returns a failure state of -2
    return converted_input;
  }
  catch (out_of_range e)
  {
    // returns a failure state of -2
    return converted_input;
  }

  // catch negative numbers not -1
  if (converted_input < -1)
  {
    return -2;
  }

  return converted_input;
}

// loop through different problems
void problem_loop(int number_of_problems)
{
  Problem user_problem;
  string user_input{"\0"};
  int user_number{0};
  //stat keeping numbers
  int correct_answers{0};
  int incorrect_answers{0};

  for (int i = 1; i <= number_of_problems; i++)
  {
    user_problem.change_problem();
    cout << user_problem.get_first_number() << " " << user_problem.get_operation() << " "
         << user_problem.get_second_number() << " = ";

    cin >> user_input;

    user_number = sanitize_input(user_input);

    if (user_number == -1)
    {
      cout << endl
           << "Goodbye!" << endl;
      return;
    }
    else if (user_number == -2)
    {
      incorrect_answers++;
      cout << "You answered incorrectly. The correct answer is " << user_problem.correct_answer() << endl;
    }
    else if (user_number == user_problem.correct_answer())
    {
      correct_answers++;
      cout << "Correct!" << endl;
    }
    else
    {
      incorrect_answers++;
      cout << "You answered incorrectly. The correct answer is " << user_problem.correct_answer() << endl;
    }
  }

  // display stats
  cout << "You answered " << correct_answers << " questions correctly and " << incorrect_answers
       << " incorrectly. That is " << ((correct_answers * 100) / incorrect_answers)
       << "% correct." << endl
       << "Goodbye!" << endl;
}

// one time collection
int collect_number_of_problems()
{
  while (true)
  {
    cout << "How many problems would you like? (-1 to quit at anytime): ";
    string user_input{'\0'};

    cin >> user_input;

    int user_number = sanitize_input(user_input);

    if (user_number == -1)
    {
      cout << endl
           << "Goodbye!" << endl;
      return 0;
    }
    else if (user_number < -1)
    {
      cout << user_input << " is not a natural number. Try again" << endl;
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
};

int main()
{
  int number_of_problems = collect_number_of_problems();

  if (number_of_problems)
  {
    problem_loop(number_of_problems);
  }
}