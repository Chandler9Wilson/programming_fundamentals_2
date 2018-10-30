/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 7:
  1. Implement Inventory class (pg: 501)
  2. Write driver code that tests Inventory at least twice
  3.
  4.  */

class Inventory
{
private:
  int item_number;
  int quantity;
  double cost;

public:
  Inventory()
  {
    item_number, quantity, cost = 0;
  }

  Inventory(int item_number, int quantity, double cost)
  {
    item_number, quantity, cost = 0;
    // TODO this could have undefined behavior if one of these fails
    set_item_number(item_number);
    set_quantity(quantity);
    set_cost(cost);
  }

  void set_item_number(int new_item_number)
  {
    if (new_item_number >= 0)
    {
      item_number = new_item_number;
    }
  }

  void set_quantity(int new_quantity)
  {
    if (new_quantity >= 0)
    {
      quantity = new_quantity;
    }
  }

  void set_cost(double new_cost)
  {
    if (new_cost >= 0)
    {
      cost = new_cost;
    }
  }

  int get_item_number()
  {
    return item_number;
  }

  int get_quantity()
  {
    return quantity;
  }

  double get_cost()
  {
    return cost;
  }

  double get_total_cost()
  {
    return (cost * quantity);
  }
};
