/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw1_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_1.cpp". Please DO NOT change
 *     the name of the main procecure "main()"
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw1_1.cpp
 * Abstract: Display the closest distance between two numbers from input.
 * Name: Michael Cervantes
 * Date: 01/08/2024
 */

// Notes         //////////////////////////////////////////////
// use std::abs(5-2) this way get a psotive number
// use a map -> using pairs as an array for value

#include <cstdlib>
#include <iostream>
#include <list>
#include <map>

using namespace std;

int main() {
  map<int, list<pair<int, int>>> distMap;
  int minDist;

  int MAXNUM = 0;
  cin >> MAXNUM;

  int arr[MAXNUM];
  for (int i = 0; i < MAXNUM; i++) {
    cin >> arr[i];
  }

  // implement values
  for (int i = 0; i < MAXNUM; i++) {
    for (int j = i + 1; j < MAXNUM; j++) {
      int diff = abs(arr[i] - arr[j]);
      pair<int, int> p;
      if (arr[i] < arr[j]) {
        p = make_pair(arr[i], arr[j]);
      } else {
        p = make_pair(arr[j], arr[i]);
      }

      distMap[diff].push_back(p);
    }
  }

  if (!distMap.empty()) {
    minDist = distMap.begin()->first;
    distMap.begin()->second.sort();

    cout << "Min Distance:" << minDist << endl;

    for (const auto &pairValue : distMap[minDist]) {
      cout << "Pair:" << pairValue.first << " " << pairValue.second << endl;
    }
  }

  return 0;
}
