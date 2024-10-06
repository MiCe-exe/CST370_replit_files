// /*
//  * INSTRUCTION:
//  *     This is a C++ starting code for hw2_2.
//  *     When you finish the development, download this file.
//  *     Note that the current filename is "main.cpp".
//  *     But rename it to "main_hw2_2.cpp".
//  *     After that, upload the renamed file on Canvas.
//  */

// // Finish the head comment with Abstract, Name, and Date.
// /*
//  * Title: main_hw2_2.cpp
//  * Abstract: Get two input one is the size and data input. Display data in pairs and index with hits binary value.
//  * Name: Michael Cervantes 
//  * Date: 1/16/2024
//  */

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
//#include <bitset>

using namespace std;

int globalIndex = 0;

string DecToBinary(int);

void DisplaySubSets(const string arr[], int index, int size, string strBuilder) {
  int deleteMe = 1;	//DELETE

  if (size == 0) {
    cout << "0:0:EMPTY" << endl;
    return;
  }

  // First time running check for 0 value element or defualted if there is value
  if (index == 0) {			
    cout << globalIndex << ':' << DecToBinary(size) << ":EMPTY" << endl;
    globalIndex++;
  }

  //display current string builder
  if (index == size) {
    // check if the arr is empty
    if (!strBuilder.empty()) {

      //Check if the array is holding a char or a string first. If True its a char
      if (strBuilder.length() > 1 && arr[index - 1].length() == 1) {			//&& arr[index].length() == 1
        cout << globalIndex << ':' << DecToBinary(size) << ':';
        for (auto c = strBuilder.begin(); c != strBuilder.end(); ++c) {
          char strChar = *c;

          if (c + 1 != strBuilder.end()) {
            cout << strChar << ' ';
          }
          else {
            cout << strChar;
          }
        }
        cout << endl;
      }
      else {
        cout << globalIndex << ':' << DecToBinary(size)<< ':' << strBuilder << endl;
      }
      globalIndex++;
    }
    return;
  }

  DisplaySubSets(arr, index + 1, size, strBuilder);

  if (arr[index].length() != 1 && !strBuilder.empty()) {

    DisplaySubSets(arr, index + 1, size, strBuilder + ' ' + arr[index]);
  }
  else {
    DisplaySubSets(arr, index + 1, size, strBuilder + arr[index]);
  }

}

string DecToBinary(int bitSize) {
  string binaryNum = "";

  for (int i = (bitSize - 1); i >= 0; i--) {
    int k = globalIndex >> i;
    if (k & 1)
      binaryNum += "1";
    else
      binaryNum += "0";
  }

  return binaryNum;
}

int main() {
  string input;
  int maxSize = 0;

  //get size and create an array
  cin >> maxSize;
  string arrList[10];

  //clear buffer
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // if statement to check if its 0 size

  //get input and assign values to the array
  getline(cin, input);
  istringstream iss(input);

  int index = 0;
  while (iss >> arrList[index] && index < maxSize) {
    index++;
  }

  // DELETE: Check word list is corrrectly done //////////////////////////
   //std::cout << "Words separated and added to the array:\n";
  //   for (int i = 0; i < index; i++) {
  //       std::cout << "Word " << i + 1 << ": " << arrList[i] << std::endl;
  //   }

  // recursion to display values in order
  DisplaySubSets(arrList, 0, maxSize, "");
}