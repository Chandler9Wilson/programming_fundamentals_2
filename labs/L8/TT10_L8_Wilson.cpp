/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 8:
  1. Tic Tac Toe game */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Player
{
  x,
  o,
  empty
};

class Board
{
private:
  Player state[3][3];

  /* Converts a plot number on 3x3 grid e.g.:
    7 | 8 | 9
    ---------
    4 | 5 | 6
    ---------
    1 | 2 | 3
  */
  int plot_number_to_coordinate(int plot_number, int &column, int &row)
  {
    switch (plot_number)
    {
    case 1:
      column, row = 0;
      return 0;
    case 2:
      column = 0;
      row = 1;
      return 0;
    case 3:
      column = 0;
      row = 2;
      return 0;
    case 4:
      column = 0;
      row = 1;
      return 0;
    case 5:
      column = 1;
      row = 1;
      return 0;
    case 6:
      column = 2;
      row = 1;
      return 0;
    case 7:
      column = 0;
      row = 2;
      return 0;
    case 8:
      column = 1;
      row = 2;
      return 0;
    case 9:
      column = 2;
      row = 2;
      return 0;
    default:
      // invalid plot_number
      return 1;
    }
  }

public:
  Board()
  {
  }

  int move_by_coordinate(int column, int row, Player player)
  {
    if (column >= 0 and column <= 2 and row >= 0 and row <= 2)
    {
      state[column][row] = player;

      return 0;
    }
    else
    {
      // invalid row or column
      return 1;
    }
  }

  int move_by_plot_number(int plot_number, Player player)
  {
    int column, row = 0;
    bool plot_valid = (plot_number >= 0 and plot_number <= 9);

    if (plot_valid)
    {
      // if plot_number converted without error
      if (!plot_number_to_coordinate(plot_number, column, row))
      {
        state[column][row] = player;

        return 0;
      }
      else
      {
        // error in conversion
        return 2;
      }
    }
    else
    {
      // invalid plot_number
      return 1;
    }
  }
};

int main()
{
  Board test;
}