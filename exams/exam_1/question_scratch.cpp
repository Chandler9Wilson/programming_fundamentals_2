#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  cout << 6 - 6 / 3 + 3 << endl;
  cout << 7 / 2 << endl;

  int num = 5;
  cout << num++ << " ";
  cout << num-- << " ";
  cout << --num << endl;

  cout << 7 % 2 << endl;

  int number = 3.75;
  cout << number << endl;

  cout << !(6 > 7 || 3 == 4) << endl;

  /* string firstName;      // Define a string object
  char lastName[7];      // Define a C-string
  firstName = "Abraham"; // Assign a value to the string object
  lastName = "Lincoln";  // Assign a value to the C-string */

  string s1 = "lion";
  string s2 = "lioness";

  cout << (s1 == s2) << endl;
}