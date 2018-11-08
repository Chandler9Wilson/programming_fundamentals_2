// Author:                      Chandler Wilson
// Assignment Number:           Lab 9
// Course/Section:              COSC 1337 Fall 2018
// Due Date:                    11/13/18
// Instructor:                  Thayer

/*
Lab Ch09
(You may delete the large comment block below if you wish.)

For the Chapter 9 lab, you add to a working program. Much of the work is reading and
understanding the code that is provided. It contains one working sort algorithm and one
working search algorithm. Your job is to add two new sort algorithms and one new search
algorithm. When complete, the program implements and tests three different sort algorithms
and two different search algorithms. (26 points max if you add one sort and one search.
30 points max if you add two new sorts and one new search.)

The choice of new algorithms is yours. The textbook provides algorithms and explanations
for linear search and binary search; and source code and explanations for bubble sort and
selection sort. These are commonly used algorithms for searching and sorting.

Note: The starting program is provided on the assignment link. Selection sort and linear search
are already coded and tested. You have to add two more sorts and one more search algorithm. In
the code you provide, use variable names (often very cryptic in textbooks) in your own terms, so
the algorithm is easier to understand. Also provide good comments.

When you implement these algorithms, use your own variable names and comments, which reflect
your  own personal understanding of how these algorithms work. You can use the textbook code
at first, but modify the names, and add comments, to show your understanding of what it is
doing. Test your code to verify it works by sorting a small array properly.

Next, measure the performance of your algorithms and find out which is best. Performance
measuring code is provided. To measure the performance, the program gets the time before and
after your algorithm runs and subtracts the stop time from the start time to get the duration,
in milliseconds, of your algorithm. Example:
  typedef unsigned int uint
  uint startTime, stopTime, duration;
  startTime = clock();
  algorithm(parameter1, parameter2, parameter3, etc);  // search or sort algorithm
  stopTime = clock();
  duration = stopTime - startTime;
  cout << "algorithm took: " << duration << "milliseconds."

For small data sizes, the time will be 0 milliseconds. To get a useful duration, it works better
if it runs for at least 1/4 second (250 milliseconds). Two ways to get an algorithm to run longer:
 1) increase the data size; 2) place a loop around the algorithm, so it runs many times.
For example, perform a search 1000 times in a loop, and divide the duration by 1000.0 to get
the milliseconds for one iteration.

Performance testing code is provided. It will try five different array sizes. Try to keep the
maximum execution time to at most 10 seconds. Arrays of size: 5000, 10000, 20000, ..., 50000,
up to 100000 may work. Include the performance results of your experimentation here.
Example (for each entry, there is some number, in milliseconds):

    Algorithm    1000  10000  20000  30000  40000   50000  (Array size)
    ----------  -----  -----  -----  -----  -----  ------
    sort1           x     xx    xxx   xxxx  xxxxx  xxxxxx
    sort2           y     yy    yyy   yyyy  yyyyy  yyyyyy
    sort3           z     zz    zzz   zzzz  zzzzz  yyyyyy
    search1         m     mm    mmm   mmmm  mmmmm  mmmmmm
    search2         n     nn    nnn   nnnn  nnnnn  nnnnnn
Observe: As the size of the array increases, how does the duration increase?

Note: Code for automating the performance testing of the algorithms is included. Read the code to
understand how to performance test your own search and sort algorithms. Very short run-times
(fast algorithms, small data) may register as 0 time, which is under 1 millisecond (1/1000th of a second).
*/

#include <iostream>
#include <iomanip>
#include <random> // needed for Orwell devcpp

using namespace std;

const int TARGET = 123456789;
// This target value will never be found, because it
// is larger than any random number generated by rand().
// Do not find the target to test for worst-case performance.

// helper functions
void showArray(int[], int);
bool verifySorted(int[], int);

// Each selection sort below does the same algorithm. The
// difference is in how well it documents its operation.
void selectionSort(int[], int);
void selectionSortDescribed(int[], int);
void selectionSortDescribedShowProgress(int[], int);
void selectionSortConcise(int[], int);

bool linearSearchArray(int[], int, int, int &);

const int testSizes[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 0};

// This code helps to automate multiple test runs.

// Call this code as many times as desired to test your sort algorithms.
float testSortAlgorithm(void sortAlgorithm(int[], int), int array[], int arraySize)
{
  // This is an interesting function. The first parameter is a "function pointer",
  // It accepts any function that returns a void and has parameters of type: (int [], int)
  // So, the first parameter (in the caller) can be the name of the sort function being tested.
  // This reduces redundant code, because the same sequence of tests are performed on each
  // sort function. (Our textbook does not mention function pointers.)

  // fill the array with random, unsorted numbers before sorting it
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();         // initialize array with random values
  int startTime = clock();         // start the test clock
  sortAlgorithm(array, arraySize); // ALGORITHM UNDER TEST
  int stopTime = clock();          // stop the test clock
  float duration = stopTime - startTime;
  if (!verifySorted(array, arraySize))
    cout << "Error! array not sorted!!!\n";
  return duration;
}

// Copy and/or reuse this code as desired to test your search algorithms.
float testLinearSearch(int array[], int arraySize)
{
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 1000; repeat++)                   // repeat test 1000 times to increase duration
    found = linearSearchArray(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  int duration = stopTime - startTime;
  return duration / 1000.0; // divide duration by 1000 to get time for single search
}

void testAlgorithms(int array[], int arraySize)
{
  // This draws a table of results for each algorithm tested.
  const int AlgorithmNameWidth = 16;
  const int DurationWidth = 10;
  cout << setw(AlgorithmNameWidth) << left << "Algorithm";
  for (int testCount = 0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << testSizes[testCount];
  cout << endl
       << string(AlgorithmNameWidth, '=');
  for (int testCount = 0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << " =======";

  // Copy and/or reuse this code as desired to test your algorithms.
  cout << endl
       << setw(AlgorithmNameWidth) << left << "selection sort";
  for (int testCount = 0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(selectionSort, array, testSizes[testCount]);
  // In the line above, I am passing the name of the function selectionSort as a parameter into
  // the function testSortAlgorithm. You can do the same thing for your sort algorithms, as long
  // as your sort algorithms return a void and have parameters: (int array[], int size).

  cout << endl
       << setw(AlgorithmNameWidth) << left << "linear search";
  for (int testCount = 0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testLinearSearch(array, testSizes[testCount]);
  cout << endl;

  // Add a loop to call and test your first sort algorithm here
  // Add a loop to call and test your second sort algorithm here
  // Add a loop to call and test your search algorithm here
}

// Useful test to verify that array is really sorted!
bool verifySorted(int array[], int size)
{
  // returns true if array is in ascending sorted order, else false.
  for (int i = 0; i < (size - 1); ++i)
    if (array[i] > array[i + 1])
      return false;
  return true;
}

int main()
{
  // the random number generator has to be "seeded" only once.
  unsigned int seed = time(0);
  srand(seed);

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, uncomment the lines below.
  const int SMALLSIZE = 6;
  int smallArray[SMALLSIZE] = {5, 7, 2, 8, 9, 1}; // for testing purposes

  cout << "Optional testing of specific algorithms, prior to performance comparison table:\n\n";
  cout << "UNSORTED smallArray is: ";
  showArray(smallArray, SMALLSIZE);
  if (!verifySorted(smallArray, SMALLSIZE))
    cout << "Note: smallArray not sorted.\n";
  selectionSortDescribedShowProgress(smallArray, SMALLSIZE);
  cout << "SORTED   smallArray is: ";
  showArray(smallArray, SMALLSIZE);
  if (verifySorted(smallArray, SMALLSIZE))
    cout << "Note: smallArray is sorted.\n";

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, try it on smallArray below.

  const int BIGSIZE = 50000;
  int bigArray[BIGSIZE];
  float duration = 0.0; // time in milliseconds

  // Do a single test run using the full size of bigArray
  duration = testSortAlgorithm(selectionSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "\nSelection sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;

  duration = testLinearSearch(bigArray, BIGSIZE);
  cout << "Linear search  of bigArray took: "
       << setw(7) << duration << " milliseconds.\n\n";

  // Test the algorithms on ever longer list of numbers. Only one
  // array is needed.  Lengths of 1000, 5000, 10000, 20000, 30000,
  // 40000, 50000 are tested.
  testAlgorithms(bigArray, BIGSIZE);
  cout << endl;

  // system("pause");  // optional, commented out
  return 0;
} // end of main

//////////////////////////////////////////////
// Add your first sort algorithm in here
// Add your second sort algorithm in here
// Add your search algorithm in here
//////////////////////////////////////////////

void showArray(int array[], int size)
{
  for (int count = 0; count < size; count++)
    cout << setw(2) << array[count] << ' ';
  cout << endl;
}

// Your new search algorithm cannot be linear search, because it is provided here.
bool linearSearchArray(int a[], int s, int t, int &p)
{
  // This is very terse, short, cryptic - not recommended!
  for (int i = 0; i < s; i++)
    if (a[i] == t)
    {
      p = i;
      return true;
    }
  p = -1;
  return false;
}

// Your new sort algorithm cannot be selection sort, because it is provided here.
// This is the selection sort from our textbook
void selectionSort(int array[], int size)
{
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size - 1); startScan++)
  {
    minIndex = startScan;
    minValue = array[startScan];
    for (int index = startScan + 1; index < size; index++)
    {
      if (array[index] < minValue)
      {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

// This is selection sort described in more detail
void selectionSortDescribed(int array[], int size)
{
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++)
  {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++)
    {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar)
      {
        // found a smaller value than I had before, save it for now
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is selection sort described in great detail
// It also shows the result of each pass of the outer loop.
void selectionSortDescribedShowProgress(int array[], int size)
{
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++)
  {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++)
    {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar)
      {
        // found a smaller value than I had before, save it for now
        cout << "  previous min value: " << minValueSoFar << " at offset: " << minIndexSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        cout << "; found smaller value: " << minValueSoFar << " at offset: " << minIndexSoFar << endl;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    cout << "  swapped the previous minimum value: " << array[minIndexSoFar]
         << " with with new minimum value: " << array[unsortedIndex] << endl;
    cout << "After pass " << unsortedIndex << " the array looks like this: ";
    showArray(array, size);
    cout << endl;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is a selection sort from a concise algorithm encyclopedia.
// As is, it is VERY CRYPTIC!
void selectionSortConcise(int array[], int size)
{
  int i, idx, val;
  for (i = 0; i < (size - 1); i++)
  {
    idx = i;
    val = array[i];
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < val)
      {
        val = array[j];
        idx = j;
      }
    }
    array[idx] = array[i];
    array[i] = val;
  }
}

/*
Optional testing of specific algorithms, prior to performance comparison table:

UNSORTED smallArray is:  5  7  2  8  9  1
Note: smallArray not sorted.
  previous min value: 5 at offset: 0; found smaller value: 2 at offset: 2
  previous min value: 2 at offset: 2; found smaller value: 1 at offset: 5
  swapped the previous minimum value: 5 with with new minimum value: 1
After pass 0 the array looks like this:  1  7  2  8  9  5

  previous min value: 7 at offset: 1; found smaller value: 2 at offset: 2
  swapped the previous minimum value: 7 with with new minimum value: 2
After pass 1 the array looks like this:  1  2  7  8  9  5

  previous min value: 7 at offset: 2; found smaller value: 5 at offset: 5
  swapped the previous minimum value: 7 with with new minimum value: 5
After pass 2 the array looks like this:  1  2  5  8  9  7

  previous min value: 8 at offset: 3; found smaller value: 7 at offset: 5
  swapped the previous minimum value: 8 with with new minimum value: 7
After pass 3 the array looks like this:  1  2  5  7  9  8

  previous min value: 9 at offset: 4; found smaller value: 8 at offset: 5
  swapped the previous minimum value: 9 with with new minimum value: 8
After pass 4 the array looks like this:  1  2  5  7  8  9

SORTED   smallArray is:  1  2  5  7  8  9
Note: smallArray is sorted.

Selection sort on bigArray took: 3264.00 milliseconds.
Linear search  of bigArray took:    0.13 milliseconds.

Algorithm             1000      5000     10000     20000     30000     40000     50000
================   =======   =======   =======   =======   =======   =======   =======
selection sort        2.00     33.00    131.00    523.00   1174.00   2088.00   3257.00
linear search         0.00      0.01      0.03      0.05      0.08      0.10      0.13
*/
