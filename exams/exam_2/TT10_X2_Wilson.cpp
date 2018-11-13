/*
  Name:
  COSC 1337 Fall 2018 TT10
  Exam 2, Programming portion
  When complete: Change course designator in filename from DDHH to TT10
                 Change "Lastname" to your lastname.
  Upload file: TT10_X2_Lastname.cpp to BlackBoard Assignment link.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/* INSTRUCTIONS: (OK to remove this big comment block, but keep smaller // comments.)

  PLEASE PLACE NEW CODE NEAR COMMENT LABELS, PROVIDED FOR EACH STEP.

  Step 1. (5 points)
    In class CoinPurse, write two CoinPurse constructors:
       default: set all coin counts to zero; do not allow the coin counts to be uninitialed.
       2nd:     set all coin counts to non-negative initial values; use parameters for:
                  quarter, dime, nickel, penny. To save time, you can use parameters: q, d, n, p.
                IMPORTANT: prohibit negative values - if negative coin value given, use 0 instead.
    Tip: you can combine both of these into one constructor using default parameters

  Step 2. (5 points)
    In main, in one statement, declare a new CoinPurse object called purse and initialize
    purse with: 4 quarters, 3 dimes, 2 nickels, 1 penny

  Step 3. (5 points)
    In class CoinPurse, write the definition for a new public member function: total_value.
    total_value returns the total value of all quarters, dimes, nickels and pennies
    in a CoinPurse object. For example: a purse with 4 quarters, 3 dimes,
    2 nickels and 1 penny has a total value of (4*25)+(3*10)+(2*5)+(1*1)=141 (cents)
    This is a getter / accessor, and should be marked const.

  Step 4. (5 points)
    In main, write code to call the total_value method on the purse object.
    Display the returned value, which is the total value of the coins in purse.
    Format the output so it displays in dollars and cents. Example: $1.41
    Hint: setprecision, fixed

  Step 5. (5 points)
    In class CoinPurse, implement a mutator/setter called set() which sets the
    coin counts of all coins. Pre-validate any new coin counts; do not allow any
    coin count to be less than zero. If the ANY of the coin counts are invalid
    (negative), do not modify ANY coin counts. If the set() succeeds, return true;
    if the set() fails, return false.

  Step 6. (5 points)
    To avoid redundant code and insure proper validation, modify constructor(s)
    as needed to call set() instead of having redundant checking code.

  Step 7. (5 points)
    In class CoinPurse, write a show() method that outputs the number of each
    .coin in the purse in one string, like this: "(q=4 d=3 n=2 p=1)" (no endl or "\n")
    Another option is to return a string. The caller can cout the string. This way,
    class CoinPurse is no longer dependent upon iostream.

  Step 8. (5 points)
    In main, call set to change the values in purse to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
    In main, call show to display the contents of purse (number of each coin).

  Step 9. (5 points)
    In class CoinPurse, write a modify() method that modifies coin counts
    using a positive (increment), negative (decrement) or zero (keep the same)
    value. For example:
      purse.modify(0, 0, 2, -3) This will: keep quarters, dimes the same;
      increase nickels by 2, and decrease pennies by 3.
    IMPORTANT! Do not allow coin counts to become less than zero! If ANY coin will
    become negative, don't make any changes.
    If modify() succeeds, return true; if modify() fails, return false

  Step 10 (10 points)
    In main, write a menu driven loop that allows the user the add or remove coins from purse.
    In a loop, display the total value, coins and options. Use s to stop (q is for quarter). For example:
      $3.05 (q=8 d=7 n=6 p=5) Modify p)enny n)ickel d)ime q)uarter s)top: p -3
      $3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: n 0
      $3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: d 2
      $3.12 (q=8 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: q -4
      $2.12 (q=4 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: s
    Use the provided get_value function to get the option letter and the count.
    Your user interface should look similar to example above.

    Important: Use if (cin >> x) checking so invalid numeric input does not cause crash or infinite loop.
         You can use get_input code developed earlier to provide one function for getting input. Required!

  Step 11 (5 points)
    Test your code as described above in Step 10 and paste the output at the bottom.

  Step 12 (5 points, EXTRA CREDIT)
    Add a new option c)ents that allows the user to add a specific amount of cents
    That is, instead of the user specifying a specific coin and count, the computer
    determines the coin counts, based on the cents to add. For example:
      $1.41 (q=4 d=3 n=2 p=1) Modify c)ents p)enny n)ickel d)ime q)uarter s)top: c 125
      $2.66 (q=9 d=3 n=2 p=1) Modify c)ents p)enny n)ickel d)ime q)uarter s)top: c 24
      $2.90 (q=9 d=5 n=2 p=5) Modify c)ents p)enny n)ickel d)ime q)uarter s)top: s

  When adding cents, add the fewest number of coins possible. That is, first add
  as many quarters as possible, then as many dimes as possible, then nickels and pennies.
  As a result, adding cents never adds more than 2 dimes, 1 nickel, or 4 pennies.
  If doing Step 12, do Step 11 (test and paste output at the bottom) LAST.
*/

class CoinPurse
{
private:
  int quarters, dimes, nickels, pennies;

public:
  //  Step 1) Write two CoinPurse constructors:
  //    default: set all coin counts to zero
  //    2nd:     set all coin counts to initial values; use parameters for: penny, nickel, dime, quarter
  //    please combine both of these into one constructor

  // Step 6) avoid redundant code, call set() in constructor(s)

  CoinPurse()
  {
    quarters, dimes, nickels, pennies = 0;
  }

  CoinPurse(int, int, int, int)
  {
  }

  // Step 3) Write total_value to return total value of coins in CoinPurse object
  int total_value() const; // return total cents as int // getters should be marked as const

  // Step 5) Implement set() which modifies the coin counts
  bool set(int, int, int, int);

  // Step 7) write show() method that outputs the number of each coin in the purse
  //  in one string, like this: "q=4 d=3 n=2 p=1" (don't << endl;)
  void show() const;

  // Step 9) write modify() method to modify coin counts using a positive (increment),
  // negative (decrement) or zero (keep the same) value.
  bool modify(int, int, int, int);
};

template <typename T> // This is provided. Use it to get values from the user.
T get_value(const string &prompt = "enter value: ",
            const string &errmsg = "  invalid, try again\n",
            T value_min = -numeric_limits<T>::max(), T value_max = numeric_limits<T>::max());
// Hint: char option = get_value<char>("Modify p)enny n)ickel d)ime q)uarter s)top: ");

int main()
{
  cout << "COSC 1337 Exam 2 CoinPurse" << endl;

  // Step 2) declare CoinPurse object called purse;
  // initialize with: 4 quarters, 3 dimes, 2 nickels, 1 penny

  // Step 4) Call the total_value method on purse; display the result formatted as: $x.xx

  // Step 8) Call set to change values in purse to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
  //         Call show to display the contents of purse

  // Step 10) write menu driven loop that allows the user the add or remove coins from purse.

  // Step 12 EXTRA CREDIT) add c)ents option that allows the user to add a specific amount of cents

  cout << endl
       << "Goodbye!" << endl; // this should appear as the last line of your output
  return EXIT_SUCCESS;        // Use return 0 if EXIT_SUCCESS is undefined
}

template <typename T>
T get_value(const string &prompt = "enter value: ",
            const string &errmsg = "  invalid, try again\n",
            T value_min = -numeric_limits<T>::max(), T value_max = numeric_limits<T>::max())
{
  T value{};
  while (true)
  {
    if (prompt != "")
      cout << prompt;
    if (cin >> value and value >= value_min and value <= value_max)
      return value;
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      if (errmsg != "")
        cout << errmsg;
    }
  }
}

/*  Step 11) Paste test output here (do this after step 12 if doing extra credit)

*/