/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 4:
  1. Provide menu-driven option loop that:
    * Asks a user for what medium they want to calc
    * Input the number of feet through the medium
    * Return how long that will take */
#include <iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;

double collect_distance()
{
  string error_message = "  Please enter a positive number. Try Again";
  string prompt = "  How far will the sound travel (in feet): ";

  while (true)
  {
    cout << prompt;

    double value{0};
    if (cin >> value and value > 0)
    {
      return value;
    }
    else
    {
      cout << error_message << endl;

      cin.clear();
      cin.ignore(10000, '\n');
    }
  }
}

int main()
{
  enum material
  {
    air = 'a',
    water = 'w',
    steel = 's',
    quit = 'q'
  };
  bool not_quit = true;
  string error_message = "  Not a valid option. Try Again";

  cout << "This computes the time sound will take to travel a given distance" << endl;

  while (not_quit)
  {
    int speed_in{0};
    double distance{0};
    double time_to{0};

    cout << "What material a)ir; w)ater; s)teel; or q)uit: ";

    char option{'\0'};
    cin >> option;

    option = tolower(option);

    switch (option)
    {
    case air:
      speed_in = 1100;
      distance = collect_distance();
      time_to = distance / speed_in;

      cout << "  The time to travel " << distance << " feet in air is " << time_to << " seconds" << endl;
      break;
    case water:
      speed_in = 4900;
      distance = collect_distance();
      time_to = distance / speed_in;

      cout << "  The time to travel " << distance << " feet in water is " << time_to << " seconds" << endl;
      break;
    case steel:
      speed_in = 16400;
      distance = collect_distance();
      time_to = distance / speed_in;

      cout << "  The time to travel " << distance << " feet in steel is " << time_to << " seconds" << endl;
      break;
    case quit:
      not_quit = false;
      break;
    default:
      cout << error_message << endl;

      cin.clear();
      cin.ignore(10000, '\n');
      continue;
    }
  }
}

/* Testing below
This computes the time sound will take to travel a given distance
What material a)ir; w)ater; s)teel; or q)uit: a
  How far will the sound travel (in feet): 5
  The time to travel 5 feet in air is 0.00454545 seconds
What material a)ir; w)ater; s)teel; or q)uit: w
  How far will the sound travel (in feet): 5
  The time to travel 5 feet in water is 0.00102041 seconds
What material a)ir; w)ater; s)teel; or q)uit: s
  How far will the sound travel (in feet): 0
  Please enter a positive number. Try Again
  How far will the sound travel (in feet): 500
  The time to travel 500 feet in steel is 0.0304878 seconds
What material a)ir; w)ater; s)teel; or q)uit: s
  How far will the sound travel (in feet): -500
  Please enter a positive number. Try Again
  How far will the sound travel (in feet): 5
  The time to travel 5 feet in steel is 0.000304878 seconds
What material a)ir; w)ater; s)teel; or q)uit: h
  Not a valid option. Try Again
What material a)ir; w)ater; s)teel; or q)uit: q
 */
