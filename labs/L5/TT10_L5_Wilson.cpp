/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 5:
  1. Open user specified file
  2. Graph the file and exit*/
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

void graph_population(string file_to_graph)
{
  string graph_title = "Coleman County Population Growth";
  string graph_legend = "(each * represents 1000 people)";
  int year{1900};

  ifstream inFile(file_to_graph);

  while (!inFile.eof())
  {
    string population;
    inFile >> population;

    // break if eof before printing out
    if (inFile.eof())
    {
      break;
    }
    cout << year << " " << population << endl;

    year += 20;
  }
}

int main()
{
  string file_name = "people.txt";
  bool file_opened = attempt_open(file_name);

  if (file_opened)
  {
    cout << "opened ok" << endl;
    graph_population(file_name);
  }
  else
  {
    cout << "There was a problem opening " << file_name << endl;
  }
}