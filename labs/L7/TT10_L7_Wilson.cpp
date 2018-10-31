/* Author: Chandler Wilson
Course: COSC 1337 Fall 2018
Instructor: Thayer
Lab 7:
  1. Implement Inventory class (pg: 501)
  2. Write driver code that tests Inventory at least twice
  3. User specified number of items*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Inventory
{
private:
  int item_number;
  int quantity;
  double cost;
  string description;

public:
  Inventory()
  {
    item_number, quantity, cost = 0;
  }

  Inventory(int item_number, int quantity, double cost, string description)
  {
    // sets everything to 0 incase one of the user provided values fails
    item_number, quantity, cost = 0;

    set_item_number(item_number);
    set_quantity(quantity);
    set_cost(cost);
    set_description(description);
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

  void set_description(string new_description)
  {
    description = new_description;
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

  string get_description()
  {
    return description;
  }

  double get_total_cost()
  {
    return (cost * quantity);
  }
};

int get_input(const string &prompt = "enter value: ",
              const string &error_message = "invalid value, try again.")
{
  while (true)
  {
    cout << prompt;

    int value{0};

    if (cin >> value and value >= 1 and value <= 5)
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

Inventory generate_item(int item_number)
{
  Inventory new_item;

  new_item.set_item_number(item_number);
  // Repeats numbers for easy testing
  new_item.set_quantity(2);
  new_item.set_cost(10.00);
  new_item.set_description("I am a generic item");

  return new_item;
}

void display_item(Inventory item, double &total_cost)
{
  cout << "Item number " << item.get_item_number() << endl
       << "  description: " << item.get_description() << endl
       << "  quantity: " << item.get_quantity() << endl
       << "  cost: $" << item.get_cost() << endl;

  // Keep track of the total costs of multiple items
  total_cost += item.get_total_cost();
}

int main()
{
  string user_prompt = "How many items would you like in your inventory? (1-5): ";
  string error_message = "Please enter a whole number between 1 and 5";

  int number_of_items = get_input(user_prompt, error_message);
  Inventory array_of_items[5];
  double total_cost{0};

  // loop to generate each item
  for (int i = 0; i <= (number_of_items - 1); i++)
  {
    Inventory new_item = generate_item((i + 1));

    array_of_items[i] = new_item;
  }

  // loop to display each item and finally display a total cost
  for (int i = 0; i <= (number_of_items - 1); i++)
  {
    display_item(array_of_items[i], total_cost);
  }

  cout << "The total value of the inventory is $" << total_cost << endl;
}

/* Testing:
How many items would you like in your inventory? (1-5): 3
Item number 1
  description: I am a generic item
  quantity: 2
  cost: $10
Item number 2
  description: I am a generic item
  quantity: 2
  cost: $10
Item number 3
  description: I am a generic item
  quantity: 2
  cost: $10
The total value of the inventory is $60 */
