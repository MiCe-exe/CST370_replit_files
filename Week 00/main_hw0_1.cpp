/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw0_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw0_1.cpp". Please DO NOT change
 *     the name of the main procecure "main()"
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: hw0_1 (C++)
 * Abstract: BAsic logic check of adding and subtracting integers. 
 * Name: Michael Cervantes
 * Date: 12/24/2023
 */

#include <iostream>
using namespace std;

int main()
{
  int x;
  int y;
  cin >> x;
  cin >> y;
  
  if(x >= y)
  {
    cout << "SUM:" + std::to_string((x) + (y)) << endl;
    cout << "DIFF:" + std::to_string((x) - (y)) << endl;
  }else{
    cout << "SUM:" + std::to_string((x) + (y)) << endl;
    cout << "DIFF:" + std::to_string((y) - (x)) << endl;
  }

    return 0;
}