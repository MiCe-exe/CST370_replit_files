/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw2_1.cpp
 * Abstract: The find the difference between two time events in military time. Also consider if it is the next day.
 * Name: Michael Cervantes
 * Date: 1/16/2024
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct TimeEvent {
  int hour;
  int minute;
  int second;
};

void CalTimeDifference(TimeEvent start, TimeEvent end) {
  
  //convert into seoncds and create struct to hold the new difference values
  TimeEvent timeDiff;
  int timeInSeconds = ((end.hour * 3600) + (end.minute * 60) + end.second) 
                    - ((start.hour * 3600) + (start.minute * 60) + start.second);

  //check if the time event isnt the next day.
  if (timeInSeconds < 0) {
    timeInSeconds += 24 * 3600;
  }

  timeDiff.hour = timeInSeconds / 3600;
  timeDiff.minute = (timeInSeconds % 3600) / 60;
  timeDiff.second = (timeInSeconds % 3600) % 60;

  //output results
  cout << (timeDiff.hour < 10 ? "0" : "") << timeDiff.hour << ":"
    << (timeDiff.minute < 10 ? "0" : "") << timeDiff.minute << ":"
    << (timeDiff.second < 10 ? "0" : "") << timeDiff.second << endl;
};

int main() { 
  TimeEvent startEvent, endEvent;

  scanf("%d:%d:%d", &startEvent.hour, &startEvent.minute, &startEvent.second);
  scanf("%d:%d:%d", &endEvent.hour, &endEvent.minute, &endEvent.second);

  CalTimeDifference(startEvent, endEvent);
}