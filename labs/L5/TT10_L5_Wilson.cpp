/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 5:
  1. Graph a population file*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// flag if file opens correctly
bool attempt_open(string file_to_open)
{
  ifstream inFile(file_to_open);

  if (inFile)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// prints out a bar chart from a population file
void graph_population(string file_to_graph)
{
  string graph_title = "Coleman County Population Growth";
  string graph_legend = "(each * represents 1000 people)";
  int year{1900};

  ifstream inFile(file_to_graph);

  cout << graph_title << endl
       << graph_legend << endl;

  while (!inFile.eof())
  {
    int population{0};
    inFile >> population;

    // break if eof before printing out
    if (inFile.eof())
    {
      break;
    }

    int number_of_stars = population / 1000;
    cout << year << " " << string(number_of_stars, '*') << endl;

    year += 20;
  }
}

int main()
{
  string file_name = "people.txt";
  bool file_opened = attempt_open(file_name);

  if (file_opened)
  {
    graph_population(file_name);
  }
  else
  {
    cout << "There was a problem opening " << file_name << endl;
  }
}

/* Test Output:

Given File:
Coleman County Population Growth
(each * represents 1000 people)
1900 **
1920 ****
1940 *****
1960 *********
1980 **************
2000 ******************
Extra poulations:
Coleman County Population Growth
(each * represents 1000 people)
1900 **
1920 ****
1940 *****
1960 *********
1980 **************
2000 ******************
2020 *
2040 *****
2060 *********
2080 **************
File not found:
There was a problem opening peopple.txt
*/