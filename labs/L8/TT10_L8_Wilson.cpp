/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 8:
  1. Tic Tac Toe game */
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

enum Player
{
  x,
  o,
  empty
};

char display_player(Player player_value)
{
  if (player_value == Player::x)
  {
    return 'X';
  }
  else if (player_value == Player::o)
  {
    return 'O';
  }
}

class Board
{
private:
  const static int size_of_grid = 3;
  Player state[size_of_grid][size_of_grid];

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
    case 7:
      column = 0;
      row = 0;
      return 0;
    case 8:
      column = 0;
      row = 1;
      return 0;
    case 9:
      column = 0;
      row = 2;
      return 0;
    case 4:
      column = 1;
      row = 0;
      return 0;
    case 5:
      column = 1;
      row = 1;
      return 0;
    case 6:
      column = 1;
      row = 2;
      return 0;
    case 1:
      column = 2;
      row = 0;
      return 0;
    case 2:
      column = 2;
      row = 1;
      return 0;
    case 3:
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
    // sets every plot to empty state
    for (int column = 0; column < size_of_grid; column++)
    {
      for (int row = 0; row < size_of_grid; row++)
      {
        state[column][row] = Player::empty;
      }
    }
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

  void get_state(Player return_state[size_of_grid][size_of_grid])
  {
    copy(&state[0][0], &state[0][0] + size_of_grid * size_of_grid, &return_state[0][0]);
  }
};

void display_board(Player state_of_board[3][3])
{
  int num_pad[3][3] =
      {
          {7, 8, 9},
          {4, 5, 6},
          {1, 2, 3}};

  for (int column = 0; column < 3; column++)
  {
    for (int row = 0; row < 3; row++)
    {
      if (state_of_board[column][row] != Player::empty)
      {
        cout << display_player(state_of_board[column][row]);
      }
      else
      {
        cout << num_pad[column][row];
      }

      if (row == 2)
      {
        if (column == 2)
        {
          cout << endl;

          continue;
        }
        else
        {
          cout << endl
               << string(9, '-') << endl;

          continue;
        }
      }

      cout << " | ";
    }
  }
}

int get_input(const string &prompt = "enter value: ",
              const string &error_message = "invalid value, try again.")
{
  while (true)
  {
    cout << prompt;

    int value{0};

    if (cin >> value and value >= 1 and value <= 9)
    {
      return value;
    }
    else
    {
      cout << "  " << error_message << endl;
      cin.clear();
      cin.ignore(INT_MAX, '\n');
    }
  }
}

int main()
{
  Board player_board;

  string prompt_X = "Player X enter the position you would like to move: ";
  string prompt_O = "Player O enter the position you would like to move: ";
  string error_message = "Please enter an unused number between 1 and 9.";
  int player_turn = 2;

  while (true)
  {
    Player board_state[3][3];
    player_board.get_state(board_state);

    display_board(board_state);

    if (player_turn % 2)
    {
      int plot_number = get_input(prompt_O, error_message);
      player_board.move_by_plot_number(plot_number, Player::o);
    }
    else
    {
      int plot_number = get_input(prompt_X, error_message);
      player_board.move_by_plot_number(plot_number, Player::x);
    }

    player_turn++;
  }
}

/* Testing:
7 | 8 | 9
---------
4 | 5 | 6
---------
1 | 2 | 3
Player X enter the position you would like to move: 1
7 | 8 | 9
---------
4 | 5 | 6
---------
X | 2 | 3
Player O enter the position you would like to move: 2
7 | 8 | 9
---------
4 | 5 | 6
---------
X | O | 3
Player X enter the position you would like to move: 5
7 | 8 | 9
---------
4 | X | 6
---------
X | O | 3
Player O enter the position you would like to move: 9\
7 | 8 | O
---------
4 | X | 6
---------
X | O | 3
Player X enter the position you would like to move:   Please enter an unused number between 1 and 9.
Player X enter the position you would like to move: 9
7 | 8 | X
---------
4 | X | 6
---------
X | O | 3
Player O enter the position you would like to move:
 */