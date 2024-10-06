/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw3_1.cpp
 * Abstract: Have user enter a number for the container size and have them enter
 * number of random numbers to fill in that size. Sort the numbers and print out
 * the sorted nmbers. Also if there is a number range repace from x-y instead of
 * listing every number in the range. 
 Name: Michael Cervantes 
 Date: 01/23/2024
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string strBuilder = "";
  int maxSize = 0;
  cin >> maxSize;
  int arr[maxSize];

  for (int i = 0; i < maxSize; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + maxSize);

  for (int i = 0; i < maxSize; i++) {
    int rangeBeg = arr[i];
    int rangeEnd = rangeBeg;

    while ((i + 1) < maxSize && arr[i + 1] == rangeEnd + 1) {
      ++i;
      ++rangeEnd;
    }

    if (rangeBeg == rangeEnd) {
      cout << rangeBeg;
    } else {
      cout << rangeBeg << "-" << rangeEnd;
    }

    if (i < maxSize - 1) {
      cout << " ";
    }
  }

  cout << endl;

  return 0;
}
