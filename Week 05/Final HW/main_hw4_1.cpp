/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw4_1.cpp
 * Abstract: Swap out elements in an array. Having all negative numbers to the
 * left and postive to the right. Name: Michael Cervantes Date: 2/4/2024
 */

#include <iostream>
using namespace std;

void printArr(int a[], int size) {
  for (int i = 0; i < size; i++) {
    if (i < size - 1) {
      cout << a[i] << " ";
    } else {
      cout << a[i];
    }
  }
}

void swapArr(int arr[], int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int main() {
  int numValues;
  int maxSize = 0;
  int maxSize2 = 0;

  cin >> maxSize;
  maxSize2 = maxSize;

  int arr[maxSize];
  int arr2[maxSize2];

  for (int i = 0; i < maxSize; i++) {
    cin >> arr[i];
    arr2[i] = arr[i];
  }

  int i = 0, j = maxSize - 1;

  // Sort array using approach 1
  while (i < j) {
    // Move positive numbers 'j' to the right side
    while (arr[j] >= 0 && j > i) {
      j--;
    }

    // Move negative numbers 'i' to the left side
    while (arr[i] < 0 && i < j) {
      i++;
    }

    // Swap if necessary
    if (i < j) {
      swapArr(arr, i, j);
    }
  }

  // Sort array2 with approach 2
  // int maxSize2 = sizeof(arr2) / sizeof(arr2[0]);
  i = 0;
  j = 0; // Both start from the first element

  while (j < maxSize2) {

    // swap if 'j' isa negative and if 'i' isa postive and walk 'i'
    if (arr2[j] < 0 && arr2[i] > 0) {
      swapArr(arr2, i, j);
      i++;
    }

    if (arr2[j] >= 0 && arr2[i] < 0) {
      i++; // making sure 'i' doesn't get left behind.
    } else {
      j++; // always move 'j' towards the right
    }

    // j++; // Always move j towards the right
  }

  printArr(arr, maxSize);
  cout << endl;
  printArr(arr2, maxSize2);
  cout << endl;
}
