/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw1_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_2.cpp". Please DO NOT change
 *     the name of the main procecure "main()"
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw1_2.cpp
 * Abstract: Make a palindrome program with alphanumeric input string.
 * Name: Michael Cervantes
 * Date: 01/08/2024
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
  
  // Odd Numbers
  if (s.length() % 2 == 1) {

    for(int i = 0; i < (s.length() -1) / 2; i++) {
      
      if(tolower(s[i]) != tolower(s[s.length() - (i + 1)])){
        return false;
      }
    }

    return true;
  }else {
    // even numbers
    for(int i = 0; i < s.length() / 2; i++){
      if(tolower(s[i]) != tolower(s[s.length() - (i + 1)])){
        return false;
      }
    }
    return true;
  }

  return false;
}

int main() {
  string input = "";
  string output = "";
  cin >> input;

  for (char c : input) {
    if (isalnum(c)) {
      output += c;
    }
  }

  // check if output is palindrome
  if (isPalindrome(output)) {
    cout << "TRUE\n";
  } else {
    cout << "FALSE\n";
  }

  return 0;
}
