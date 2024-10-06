#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;


struct Timestamp {
    int hour, minute, second;
};

void getTimeDifference(Timestamp first, Timestamp second) {
    int timeDifferenceInSeconds = (second.hour - first.hour) * 3600 + (second.minute - first.minute) * 60 + (second.second - first.second);

    int hours = timeDifferenceInSeconds / 3600;
    int minutes = (timeDifferenceInSeconds % 3600) / 60;
    int seconds = timeDifferenceInSeconds % 60;

    cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << endl;
}
void test();

int main() {
    Timestamp firstEvent, secondEvent;

    // Read first timestamp
    cout << "Enter the first timestamp (hh:mm:ss): ";
    scanf("%d:%d:%d", &firstEvent.hour, &firstEvent.minute, &firstEvent.second);

    // Read second timestamp


    cout << "Enter the second timestamp (hh:mm:ss): ";
    scanf("%d:%d:%d", &secondEvent.hour, &secondEvent.minute, &secondEvent.second);

    // Display time difference
    cout << "Time Difference: ";
    getTimeDifference(firstEvent, secondEvent);

    test();

    return 0;
}

void test() {
    cout << endl << "test" << endl;
}