/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw5_1.cpp
 * Abstract: Displays the performance of two different sorting algorithms,
 * Quicksort, and Mergesort. Using GeeksforGeeks as a reference.
 * https://www.geeksforgeeks.org/quick-sort/ and
 * https://www.geeksforgeeks.org/merge-sort/
 * Name: Michael Cervantes 
 * Date: 2/13/2024
 */

#include <iostream>
#include <random>
#include <vector>
//#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

// Merge sort source GeeksforGeeks
void merge(vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp
  vector<int> L(n1), R(n2);

  // Copy data to temp vector
  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  // Merge the temp
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  // Copy the remaining elements Left and Right
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void mergeSort(vector<int> &arr, int l, int r) {
  if (l < r) {
    // Same as (l + r) / 2, avoids overflow for large numbers
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

// Quick sort GeeksforGeeks
int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[high]; // Choose last element as pivot
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than or equal to pivot
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    // partitioning index
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void Display(double q, double m) {
  cout << "===================== Execution Time ====================" << endl;
  cout << "Merge sort: \t" << right << m << " milliseconds" << endl;
  cout << "Quick sort: \t" << right << q << " milliseconds" << endl;
  cout << "=========================================================" << endl;
}

int main() {
  int maxSize = 0;

  // ctime
  double mTime = 0;
  double qTime = 0;
  time_t t1;

  // Random Numbers
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, 1000000);

  cout << "Enter input size: ";

  cin >> maxSize;

  vector<int> dataQsort(maxSize);

  for (int i = 0; i < maxSize; i++) {
    dataQsort[i] = dis(gen);
  }

  vector<int> dataMsort(dataQsort);

  t1 = clock();
  quickSort(dataQsort, 0, maxSize - 1);
  qTime = clock() - t1;

  t1 = clock();
  mergeSort(dataMsort, 0, maxSize - 1);
  mTime = clock() - t1;

  Display(qTime, mTime);
}
