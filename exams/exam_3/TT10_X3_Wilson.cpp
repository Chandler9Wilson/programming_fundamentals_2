/*
  COSC 1337 Exam 3 Lab portion Fall 2018
  Name: Chandler Wilson
  Filename: TT10_X3_Wilson.cpp
  Date: 12/13/2018
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Product
{ // This is used for step 1 and step 2; leave as is.
  string name;
  double price;
  string made_in;
  int weight;
};

// Put class Item definition code for steps 1 an 2 here.
class Item
{
private:
  string name;
  double price;

public:
  Item(string new_name = "generic", double new_price = 1.00)
  {
    if (new_name.length() > 1 && new_price > 1.00)
    {
      name = new_name;
      price = new_price;
    }
    else
    {
      name = "generic";
      price = 1.00;
    }
  }

  // used for black umbrella (step 2)
  string get_name()
  {
    return name;
  }

  void print_out()
  {
    cout << name << " is $" << fixed << setprecision(2) << price << endl;
  }
};

void step1()
{
  // ------------------ below this line, code is provided, do not change
  // The section between the lines is provided startup code for step 1. DO NOT CHANGE UNLESS COMPILER ERROR.
  // Below, a std::vector is used. It works as-is.
  // It creates an vector (array) as described in the instructions. It provides
  // intial startup data for you to save time. Use this data to load your store with items.

  vector<Product> warehouse{
      {"hat", 8.00, "china", 6},
      {"t-shirt", 15.00, "usa", 14},
      {"coffee mug", 6.50, "canada", 22},
      {"candy bar", 0.79, "mexico", 3},
      {"", 34.59, "japan", 122},
      {"mixing bowl", 4.99, "brazil", 20}};

  cout << "Step 1:\n";
  cout << "Contents of vector warehouse, already loaded:\n";
  for (auto &item : warehouse)
  { // If this does not compile, see the note below
    // If the for (auto &t:warehouse) code has a compilation error, you can do this:
    //   1) recommended: enable C++11/14 features on your compiler with option: -std=c++11
    //   2) alternative: change to a regular for loop: for (int i=0; i<warehouse.length(); ++i), etc.
    // The section above is provided startup code. DO NOT CHANGE UNLESS COMPILER ERROR
    cout << setw(12) << item.name << setw(8) << item.price << setw(8) << item.made_in << setw(6) << item.weight << endl;
  }
  cout << endl;
  // ------------------ above this line, code is provided, do not change

  // Put your new code for step 1 here, it will be called from main:
  const int store_length{6};
  Item store[store_length];

  // loop to add items from warehouse to store
  for (int i{0}; i < warehouse.size(); i++)
  {
    store[i] = Item(warehouse[i].name, warehouse[i].price);
  }

  // loop to print out store
  for (int i{0}; i < warehouse.size(); i++)
  {
    store[i].print_out();
  }
}

void step2()
{
  cout << "\nStep 2:\n";

  Item *p_item = new Item("black umbrella", 19.95);

  cout << p_item->get_name() << " is at address " << &p_item << endl;
  p_item->print_out();

  delete p_item;
  p_item = nullptr;
}

// Step 3: The initial code for class Fraction is provided. You will add to it further down...
class Fraction
{
  // A fraction can be written as: top/bot (numerator/denominator), such as: 1/3, 2/7, etc.
private:
  int top = 0; // numerator
  int bot = 1; // denominator
public:
  Fraction(int top = 0, int bot = 1)
  {
    if (bot != 0)
    { // guard against division by 0
      this->top = top;
      this->bot = bot;
    }
  }
  double get() const
  {
    return top / static_cast<double>(bot);
  }

  // Put new code for step 3 here:
  Fraction operator++()
  {
    ++top;
  }

  Fraction operator--()
  {
    --top;
  }

  Fraction operator*(const Fraction &second_fraction)
  {
    Fraction new_fraction;

    new_fraction.top = this->top * second_fraction.top;
    new_fraction.bot = this->bot * second_fraction.bot;

    return new_fraction;
  }
};

void step3()
{
  cout << "\nStep 3:\n";
  // This is testing code for step 3; it will be called from main.
  // After you have implemented: operator++, operator--, and operator*,
  // Uncomment the code below. It should work.

  // test code, expect: 6, uncomment when ready
  Fraction a = 4;
  ++a;
  ++a;
  cout << "a=" << a.get() << endl;

  // test code, expect: 3, uncomment when ready
  Fraction b = 5;
  --b;
  --b;
  cout << "b=" << b.get() << endl;

  // test code, expect: 42, uncomment when ready
  Fraction c = 6, d = 7, e = c * d;
  cout << "e=" << e.get() << endl
       << endl;

  // add code here to initialize Fraction evens[] with 2 4 6 8 10 and display its contents
  Fraction evens[] = {2, 4, 6, 8, 10};

  // magic number is length of initialization list above; didnt have time to fix
  for (int i = 0; i < 5; i++)
  {
    cout << evens[i].get() << " ";
  }
  cout << endl;
};

// The code below is for step 4, recursion
// This startup code may be helpful when developing your recursive functions.
void recurse(int times_to_call)
{
  // a generalized recursion outline; has 5 locations to do work...
  cout << "recurse head... "
       << "(" << times_to_call << ") " << endl;
  if (times_to_call > 1)
  {
    cout << "recurse before call... "
         << "(" << times_to_call << ") " << endl;
    recurse(times_to_call - 1); // work can also be done inside the parameter list!
    cout << "recurse after call... "
         << "(" << times_to_call << ") " << endl;
  }
  else
  {
    cout << "recurse else option... "
         << "(" << times_to_call << ") " << endl;
  }
  cout << "recurse ...tail "
       << "(" << times_to_call << ") " << endl;
}

// Below are working iterative versions of line, left_arrow, right_arrrow, double_arrow
void line_iterative(int n)
{ // Provided, do not change
  for (int i = 0; i < n; ++i)
    cout << "-";
}

void left_arrow_iterative(int n)
{ // Provided, do not change
  cout << "<";
  for (int i = 0; i < n; ++i)
    cout << "-";
}

void right_arrow_iterative(int n)
{ // Provided, do not change
  for (int i = 0; i < n; ++i)
    cout << "-";
  cout << ">";
}

void double_arrow_iterative(int n)
{ // Provided, do not change
  cout << "<";
  for (int i = 0; i < n; ++i)
    cout << "-";
  cout << ">";
}

// Put your new recursive versions for step 4 here...
void line_recursive(int n)
{
  if (n > 1)
  {
    // print out 1 line and call itself with n-1
    cout << "-";
    line_recursive(n - 1);
  }
  else
  {
    cout << "-";
  }
}

void left_arrow_recursive(int n, bool first_call = true)
{
  if (first_call)
  {
    cout << "<";
  }

  if (n > 1)
  {
    cout << "-";
    left_arrow_recursive(n - 1, false);
  }

  else
  {
    cout << "-";
  }
}

void right_arrow_recursive(int n)
{
  if (n > 1)
  {
    // print out 1 line and call itself with n-1
    cout << "-";
    right_arrow_recursive(n - 1);
  }
  else
  {
    cout << "-"
         << ">";
  }
}

void double_arrow_recursive(int n, bool first_call = true)
{
  // This one is a challenge. Hint: add another parameter
  // fill this in with recursive code for double_arrow
  if (first_call)
  {
    cout << "<";
  }

  if (n > 1)
  {
    cout << "-";
    double_arrow_recursive(n - 1, false);
  }

  else
  {
    cout << "-"
         << ">";
  }
}

void step4()
{
  // Below is testing code for step 4; it will be called from main. No changes needed.
  // recurse(3); // call to recurse example for experimentation, if desired
  cout << "\nStep 4:\n";
  cout << "Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:\n";
  for (int n = 1; n <= 5; ++n)
  { // test provided iterative functions
    cout << "n=" << setw(2) << n << ":";
    line_iterative(n);
    cout << ' ';
    left_arrow_iterative(n);
    cout << ' ';
    right_arrow_iterative(n);
    cout << ' ';
    double_arrow_iterative(n);
    cout << endl;
  }
  cout << "\nTest student's new recursive versions of line, left_arrow, right_arrow, double_arrow:\n";
  for (int n = 1; n <= 5; ++n)
  { // test student's new recursive functions
    cout << "n=" << setw(2) << n << ":";
    line_recursive(n);
    cout << ' ';
    left_arrow_recursive(n);
    cout << ' ';
    right_arrow_recursive(n);
    cout << ' ';
    double_arrow_recursive(n);
    cout << ' ' << endl;
  }
};

void step5()
{
  // 5 different ways to cause undefined behavior, and possibly crash a C++ program.
  // in main, step5() is commented out.
  // To verify your bad code is really bad, test it by uncommenting step5() in main.
  cout << "Step 5:\n";
  // Put all your code for step 5 here:
};

int main()
{
  // No new code goes in main. Put all new code where designated in the steps above.
  cout << "Start...\n";
  step1();
  step2();
  step3();
  step4();
  // step5(); // Extra credit: 5 ways to possibly crash a C++ program
  cout << "\n...end.\n";
  return 0;
}

/* Original startup code test output:
Start...
Step 1:
Contents of vector warehouse, already loaded:
         hat       8   china     6
     t-shirt      15     usa    14
  coffee mug     6.5  canada    22
   candy bar    0.79  mexico     3
               34.59   japan   122
 mixing bowl    4.99  brazil    20

Step 2:
Step 3:

Step 4:
Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:
n= 1:- <- -> <->
n= 2:-- <-- --> <-->
n= 3:--- <--- ---> <--->
n= 4:---- <---- ----> <---->
n= 5:----- <----- -----> <----->

Test student's new recursive versions of line, left_arrow, right_arrow, double_arrow:
n= 1:
n= 2:
n= 3:
n= 4:
n= 5:

...end.
*/

/* Paste your test output here:
Step 1:
Contents of vector warehouse, already loaded:
         hat       8   china     6
     t-shirt      15     usa    14
  coffee mug     6.5  canada    22
   candy bar    0.79  mexico     3
               34.59   japan   122
 mixing bowl    4.99  brazil    20

hat is $8.00
t-shirt is $15.00
coffee mug is $6.50
generic is $1.00
generic is $1.00
mixing bowl is $4.99

Step 2:
black umbrella is at address 0x62fec8
black umbrella is $19.95

Step 3:
a=6.00
b=3.00
e=42.00

2.00 4.00 6.00 8.00 10.00

Step 4:
Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:
n= 1:- <- -> <->
n= 2:-- <-- --> <-->
n= 3:--- <--- ---> <--->
n= 4:---- <---- ----> <---->
n= 5:----- <----- -----> <----->

Test student's new recursive versions of line, left_arrow, right_arrow, double_arrow:
n= 1:- <- -> <->
n= 2:-- <-- --> <-->
n= 3:--- <--- ---> <--->
n= 4:---- <---- ----> <---->
n= 5:----- <----- -----> <----->

...end.
*/
