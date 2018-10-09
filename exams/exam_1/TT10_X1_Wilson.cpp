/*
  Name: Chandler Wilson
  COSC 1337 Fall 2018 Section: TT10
  Exam 1, Programming portion
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// step 1 (10 points) function get_input() goes here ---
int get_input(const string &prompt,
              const string &error_message,
              int min_value,
              int max_value,
              bool range_check = true)
{
  while (true)
  {
    cout << prompt;

    int value{0};
    if (cin >> value)
    {
      if (range_check)
      {
        if (value >= min_value and value <= max_value)
        {
          return value;
        }
        else
        {
          cout << error_message << endl;

          cin.clear();
          cin.ignore(10000, '\n');
          continue;
        }
      }
      else
      {
        return value;
      }
    }
    else
    {
      cout << error_message << endl;

      cin.clear();
      cin.ignore(10000, '\n');
    }
  }
}

// step 4 (10 points) function isvalid_day_month() goes here ---
bool isvalid_day_month(int day, int month)
{
  const int days_in_Jan = 31, days_in_Feb = 28, days_in_Mar = 31, days_in_Apr = 30,
            days_in_May = 31, days_in_Jun = 30, days_in_Jul = 31, days_in_Aug = 31,
            days_in_Sep = 30, days_in_Oct = 31, days_in_Nov = 30, days_in_Dec = 31;

  const int Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8,
            Sep = 9, Oct = 10, Nov = 11, Dec = 12;

  switch (month)
  {
  case Jan:
    if (day >= 1 and day <= days_in_Jan)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Feb:
    if (day >= 1 and day <= days_in_Feb)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Mar:
    if (day >= 1 and day <= days_in_Mar)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Apr:
    if (day >= 1 and day <= days_in_Apr)
    {
      return true;
    }
    else
    {
      return false;
    }
  case May:
    if (day >= 1 and day <= days_in_May)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Jun:
    if (day >= 1 and day <= days_in_Jun)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Jul:
    if (day >= 1 and day <= days_in_Jul)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Aug:
    if (day >= 1 and day <= days_in_Aug)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Sep:
    if (day >= 1 and day <= days_in_Sep)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Oct:
    if (day >= 1 and day <= days_in_Oct)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Nov:
    if (day >= 1 and day <= days_in_Nov)
    {
      return true;
    }
    else
    {
      return false;
    }
  case Dec:
    if (day >= 1 and day <= days_in_Dec)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

int main()
{
  cout << "COSC 1337 Exam 1 Lab Portion" << endl;

  string month_prompt = "What is your birth month?: ";
  string day_prompt = "What is your birth day?: ";
  string year_prompt = "What is your birth year?: ";

  string month_error = "Error: Months should be 1-12";
  string day_error = "Error: days should be 1-31";
  string year_error = "Error: Years should be 1900-2018";

  int min_month = 1;
  int max_month = 12;
  int min_day = 1;
  int max_day = 31;
  int min_year = 1900;
  int max_year = 2018;

  // step 2 (10 points) 3 calls to get_input() goes here ---
  int month = get_input(month_prompt, month_error, min_month, max_month);
  int day = get_input(day_prompt, day_error, min_day, max_day);
  int year = get_input(year_prompt, year_error, min_year, max_year);

  bool unaccepted_birthdate = true;

  while (unaccepted_birthdate)
  {
    cout << "Birthday is " << month << "/" << day << "/" << year
         << " Options: Change: m)onth; d)ay; y)ear; OR a)ccept, r)efuse?: ";

    char option{'\0'};
    cin >> option;

    option = tolower(option);

    switch (option)
    {
    case 'm':
      month = get_input(month_prompt, month_error, min_month, max_month);
      break;
    case 'd':
      day = get_input(day_prompt, day_error, min_day, max_day);
      break;
    case 'y':
      year = get_input(year_prompt, year_error, min_year, max_year);
      break;
    case 'a':
      if (isvalid_day_month(day, month))
      {
        unaccepted_birthdate = false;
        break;
      }
      else
      {
        cout << "There are not " << day << " days in the " << month
             << " month. Please correct." << endl;
        break;
      }
    case 'r':
      month = 0;
      day = 0;
      year = 0000;
      unaccepted_birthdate = false;
      break;
    default:
      cout << option << " is not a valid option try again.";

      cin.clear();
      cin.ignore(10000, '\n');
      continue;
    }
  }

  // step 5 (3 points, optional extra credit) call to won_prize() if user entered valid birthday
  // step 6 (2 points, optional extra credit) test if won_prize() in loop of 10,000

  cout
      << endl
      << "Goodbye!" << endl; // this should appear as the last line of your output
  return EXIT_SUCCESS;       // Use return 0 if EXIT_SUCCESS is undefined
}

/*
COSC 1337 Exam 1 Lab Portion
What is your birth month?: 2
What is your birth day?: 31
What is your birth year?: asdf
Error: Years should be 1900-2018
What is your birth year?: 1997
Birthday is 2/31/1997 Options: Change: m)onth; d)ay; y)ear; OR a)ccept, r)efuse?: a
There are not 31 days in the 2 month. Please correct.
Birthday is 2/31/1997 Options: Change: m)onth; d)ay; y)ear; OR a)ccept, r)efuse?: m
What is your birth month?: 5
Birthday is 5/31/1997 Options: Change: m)onth; d)ay; y)ear; OR a)ccept, r)efuse?: a

Goodbye!
chandler@chandler-G551JM:~/ACC/programming_fundamentals_2/exams/exam_1$ ./a.out
COSC 1337 Exam 1 Lab Portion
What is your birth month?: asdf
Error: Months should be 1-12
What is your birth month?: asdf
Error: Months should be 1-12
What is your birth month?: 3
What is your birth day?: 2
What is your birth year?: 2005
Birthday is 3/2/2005 Options: Change: m)onth; d)ay; y)ear; OR a)ccept, r)efuse?: r

Goodbye!

*/
