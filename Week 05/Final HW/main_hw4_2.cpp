/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw4_2.cpp
 * Abstract: Divide and conquer algorithm to find the max value in an array
 * Name:  Michael Cervantes
 * Date:  2/06/2024
 */

#include <iostream>
using namespace std;

int GetMax(int[], int, int);

int GetMax(int arr[], int low, int high) {
  if (low == high) { // If only one element just return it.
    return arr[low];
  } else {
    int mid = (low + high) / 2;                // Divide
    int leftMax = GetMax(arr, low, mid);       // Find the max in the left
    int rightMax = GetMax(arr, mid + 1, high); // Find the max in the right

    // Using std::max return the max
    return max(leftMax, rightMax);
  }
}

int main() {
  int maxSize;
  cin >> maxSize;

  int arr[maxSize];
  for (int i = 0; i < maxSize; i++) {
    cin >> arr[i];
  }

  int maxValue = GetMax(arr, 0, maxSize - 1);
  cout << maxValue << endl;

  return 0;
}
