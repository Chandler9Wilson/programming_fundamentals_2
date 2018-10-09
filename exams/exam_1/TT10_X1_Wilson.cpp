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
// isvalid_day_month(){}; // edit as appropriate

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

  while (true)
  {
    cout << "Birthday is " << month << "/" << day << "/" << year
         << " Options: Change: m)onth; d)ay; y)ear; OR a)ccept, r)efuse?: ";

    char option{'\0'};
    cin >> option;

    switch (option)
    {
    }
  }

  // step 3 (10 points) loop to enter and reenter birthday until valid
  // step 4's call to isvalid_day_month (enhancement to step 3)

  // step 5 (3 points, optional extra credit) call to won_prize() if user entered valid birthday
  // step 6 (2 points, optional extra credit) test if won_prize() in loop of 10,000

  cout << endl
       << "Goodbye!" << endl; // this should appear as the last line of your output
  return EXIT_SUCCESS;        // Use return 0 if EXIT_SUCCESS is undefined
}

/*
  Paste your test output here

*/
