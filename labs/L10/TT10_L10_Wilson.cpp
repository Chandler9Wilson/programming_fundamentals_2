/*
  Author:          Chandler Wilson
  Assignment:      Lab 10
  Topic:           memory diagram with stack, heap structures
  File Name:       TT10_L10_Wilson.cpp
  Course/Section:  COSC 1337
  Instructor:      Thayer
*/

/*
This lab is on pointers. It covers: values, addresses, pointers, the heap,
dynamic memory allocation using new, delete, delete [].
It also has a very brief introduction to linked lists, a basic data structure.

Create a program that uses memory as shown in the memory diagram provided.
Start with this startup code, which has useful macros to display variables.
Wherever possible, set the values of all variables indirectly using
pointers. Use pointer dereferencing to set the values of the "pointed to"
variables. You can "dereference" pointers with the '*' operator.  For example,
to set price to $19.95, do NOT use the variable price. Instead, use the pointer
variable *p_price. To set pi_div_2, dereference p_PI to get 3.141592, divide it
by two, and place the result into PI_div_2.

To create the "linked list" containing Person "Harry" and Person "Sally",
you need the following data structure:

class Person {
  string name;     // name of the person
  Person *next;    // pointer to the next person in the list
};

To create instances of Person, use:
  1) stack allocation: Person wizard will be on the stack, allocated statically when entering scope;
  2) heap allocation:  Persons "Harry" and "Sally" are allocated dynamically on the heap with new

To manipulate an object of class Person, you need to create some constructors,
getters and setters to fill in the name and set the pointers, or, you could make
the data members public and use  "dot" notation, such as: Person wizard;
wizard.name="Gandalf"; wizard.next=nullptr;
For dynamically allocated instances, you can use arrow notation,
such as: personList -> name="Harry".

Use the keyword "nullptr" (since C++11/14) as the recommended way of setting
a pointer to point to nothing. Do NOT use NULL or 0; this invites errors.

To create variables on the heap, with no names, you have to use new to dynamically
allocate the memory. See sample output (bottom page). IMPORTANT: Every new should
be matched by a delete to prevent a memory leak! IMPORTANT: Make sure you delete
all memory you dynamically allocate before leaving main(). Don't allow any memory
leaks. Match all new with delete. When deleting an array, use delete [] array.

After items are placed in memory, use cout statements to output the addresses
and values of all variables. Output the addresses of all variables
(both pointer and named) in hexadecimal format, and output the contents (values)
of all int, float, double and string variables.

You cannot force the memory layout to be exactly in the order in the memory diagram.
As a programmer, you don't  control exactly WHERE in memory the compiler places
variables. The important thing is for you to create the pointer variables,
value variables, and set them up (nearly) as depicted in the memory diagram.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
public:
  string name;  // name of the person
  Person *next; // pointer to the next person in the list
};

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own function that does something similar
#define show_address_value(var, width)                                             \
  cout << "address of " << setw(width) << left << #var << " is: &" << &var << "  " \
       << "contents of " << setw(width) << left << #var << " is: " << var << endl;

#define show_address(var, width) \
  cout << "address of " << setw(width) << left << #var << " is: &" << &var << endl;

int main()
{
  cout << "Output from Lab10 memory diagram on pointers:\n\n";

  float price{0};
  float *p_price = &price;
  *p_price = 19.95;

  show_address_value(price, 8);
  show_address_value(p_price, 8);
  cout << "The contents of *p_price is: " << *p_price << endl;

  // Start PI
  double PI{0};
  double PI_div_2{0};
  double *p_PI = &PI;
  *p_PI = 3.141592;
  PI_div_2 = *p_PI / 2;

  cout << endl;
  show_address_value(PI, 8);
  show_address_value(PI_div_2, 8);
  show_address_value(p_PI, 8);
  cout << "The contents of *p_PI is:    " << *p_PI << endl;

  // Start size
  int maxSize{0};
  int *p_size = &maxSize;
  *p_size = 5028;
  cout << endl;

  show_address_value(maxSize, 8);
  show_address_value(p_size, 8);
  cout << "The contents of *p_size is: " << *p_size << endl;

  // Start amount
  int *p_amount = new int{1234};
  cout << endl;
  show_address_value(p_amount, 8);
  cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
  delete p_amount;
  cout << "After delete, the contents of p_amount is: " << p_amount << endl;
  p_amount = nullptr;
  cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl;

  // Start pArray
  int *pArray = new int[3];
  pArray[0] = 11;
  pArray[1] = 22;
  pArray[2] = 33;

  cout << endl;
  show_address_value(pArray, 8);
  show_address_value(pArray[0], 8);
  show_address_value(pArray[1], 8);
  show_address_value(pArray[2], 8);

  delete[] pArray;
  cout << "After delete, the contents of pArray is: " << pArray << endl;
  pArray = nullptr;
  cout << "After reset to nullptr, the contents of pArray is: " << pArray << endl;

  // Start emptyList
  Person *emptyList = nullptr;

  cout << endl;
  show_address_value(emptyList, 8);

  // Start wizard
  Person wizard;
  wizard.name = "Gandalf";
  wizard.next = nullptr;

  cout << endl
       << "stack allocation (uses: Person wizard):\n";
  show_address(wizard, 8);
  show_address_value(wizard.name, 8);
  show_address_value(wizard.next, 8);

  // Start personList
  Person *personList = new Person;
  personList->name = "Harry";
  personList->next = new Person;
  personList->next->name = "Sally";
  personList->next->next = nullptr;

  cout << endl
       << "heap allocation (uses: personList, Person(\"Harry\"), Person(\"Sally\"):\n";
  show_address_value(personList, 8);
  show_address_value(personList->name, 8);
  show_address_value(personList->next, 8);
  cout << "  <follow link to next Person on personList>" << endl;
  show_address_value(personList->next->name, 8);
  show_address_value(personList->next->next, 8);

  delete personList->next;
  cout << "After delete, the contents of personList->next is: " << personList->next << endl;
  personList->next = nullptr;
  cout << "After reset to nullptr, the contents of personList->next is: " << personList->next << endl;
  delete personList;
  cout << "After delete, the contents of personList is: " << personList << endl;
  personList = nullptr;
  cout << "After reset to nullptr, the contents of personList is: " << personList << endl;

  return 0;
} // end of main

/*
Output from Lab10 memory diagram on pointers:

address of price    is: &0x7ffc7b59c590  contents of price    is: 19.95
address of p_price  is: &0x7ffc7b59c598  contents of p_price  is: 0x7ffc7b59c590
The contents of *p_price is: 19.95

address of PI       is: &0x7ffc7b59c5a0  contents of PI       is: 3.14159
address of PI_div_2 is: &0x7ffc7b59c5a8  contents of PI_div_2 is: 1.5708
address of p_PI     is: &0x7ffc7b59c5b0  contents of p_PI     is: 0x7ffc7b59c5a0
The contents of *p_PI is:    3.14159

address of maxSize  is: &0x7ffc7b59c594  contents of maxSize  is: 5028
address of p_size   is: &0x7ffc7b59c5b8  contents of p_size   is: 0x7ffc7b59c594
The contents of *p_size is: 5028

address of p_amount is: &0x7ffc7b59c5c0  contents of p_amount is: 0x5653fd565280
The contents of *p_amount is: 1234
After delete, the contents of p_amount is: 0x5653fd565280
After reset to nullptr, the contents of p_amount is: 0

address of pArray   is: &0x7ffc7b59c5c8  contents of pArray   is: 0x5653fd565280
address of pArray[0] is: &0x5653fd565280  contents of pArray[0] is: 11
address of pArray[1] is: &0x5653fd565284  contents of pArray[1] is: 22
address of pArray[2] is: &0x5653fd565288  contents of pArray[2] is: 33
After delete, the contents of pArray is: 0x5653fd565280
After reset to nullptr, the contents of pArray is: 0

address of emptyList is: &0x7ffc7b59c5d0  contents of emptyList is: 0

stack allocation (uses: Person wizard):
address of wizard   is: &0x7ffc7b59c5e0
address of wizard.name is: &0x7ffc7b59c5e0  contents of wizard.name is: Gandalf
address of wizard.next is: &0x7ffc7b59c600  contents of wizard.next is: 0

heap allocation (uses: personList, Person("Harry"), Person("Sally"):
address of personList is: &0x7ffc7b59c5d8  contents of personList is: 0x5653fd5652a0
address of personList->name is: &0x5653fd5652a0  contents of personList->name is: Harry
address of personList->next is: &0x5653fd5652c0  contents of personList->next is: 0x5653fd5652d0
  <follow link to next Person on personList>
address of personList->next->name is: &0x5653fd5652d0  contents of personList->next->name is: Sally
address of personList->next->next is: &0x5653fd5652f0  contents of personList->next->next is: 0
After delete, the contents of personList->next is: 0x5653fd5652d0
After reset to nullptr, the contents of personList->next is: 0
After delete, the contents of personList is: 0x5653fd5652a0
After reset to nullptr, the contents of personList is: 0
*/