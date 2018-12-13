// Author:                      Chandler Wilson
// Assignment Number:           Lab 11
// File Name:                   TT10_L11_Wilson.cpp
// Course/Section:              COSC 1337 Fall 2018
// Due Date:                    12/11/18
// Instructor:                  Thayer
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Day_Of_Year
{
private:
  int int_of_day;

public:
  static int days_in_month[];
  static string month_of_year[];

  Day_Of_Year(int day)
  {
    // sets everything to 0 incase one of the user provided values fails
    int_of_day = 1;

    set_day(day);
  }

  Day_Of_Year(string Month, int day)
  {
    // sets everything to 0 incase one of the user provided values fails
    int_of_day = 1;

    int total_days{0};
    bool more_days_than_month = true;
    int month_index{0};
    int given_months_index{0};
    const int number_of_months{12};

    // Loop to find the correct index (just a linear search)
    for (; given_months_index < number_of_months; given_months_index++)
    {
      if (month_of_year[given_months_index] == Month)
      {
        break;
      }
    }

    // Sum the number of days
    // for (month_index; month_index < given_months_index && more_days_than_month; month_index++)
    // {
    //   if (day_of_month > days_in_month[month_index])
    //   {
    //     day_of_month -= days_in_month[month_index];
    //   }
    //   else
    //   {
    //     more_days_than_month = false;
    //   }
    // }

    set_day(day);
  }

  void set_day(int new_day)
  {
    if (new_day >= 1 && new_day <= 365)
    {
      int_of_day = new_day;
    }
  }

  string to_str()
  {
    int day_of_month = int_of_day;
    bool more_days_than_month = true;
    int month_index{0};
    const int number_of_months{12};

    for (month_index; month_index < number_of_months && more_days_than_month; month_index++)
    {
      if (day_of_month > days_in_month[month_index])
      {
        day_of_month -= days_in_month[month_index];
      }
      else
      {
        more_days_than_month = false;
      }
    }

    return month_of_year[--month_index] + " " + to_string(day_of_month);
  }
};

int Day_Of_Year::days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string Day_Of_Year::month_of_year[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main()
{
  Day_Of_Year first(1);
  cout << first.to_str() << endl;

  Day_Of_Year halfway(365 / 2);
  cout << halfway.to_str();
};