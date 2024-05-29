#include <iostream>
#include <string>
using namespace std;

void timeFormatter(int hour, int min) {
    string amPm;
    
    if (hour > 12) {
        hour -= 12;
        amPm = "PM";
    }
    else {
        amPm = "AM";
    }
    
    cout << "Time: " << hour << ":" << min << amPm << endl; 
}

int main() {
    int hourValue;
    int minuteValue;
    
    cout << " Enter the number of hours: ";
    cin >> hourValue;
    cout << "Enter the number of minutes: ";
    cin >> minuteValue;
    
    timeFormatter(hourValue, minuteValue);
    
    return 0;
}
