#include <iostream>
using namespace std;

int main() {
    long _seconds;
    int days;
    int hours;
    int minutes;
    int seconds;
    int tempSeconds;
    
    cout << "Enter the number of seconds: ";
    cin >> _seconds;
    
    tempSeconds = _seconds;

    days = (_seconds / (60 * 60 * 24));
    _seconds %= (60 * 60 * 24);
    
    hours = (_seconds / (60 * 60));
    _seconds %= (60 * 60);
    
    minutes = (_seconds / 60);
    seconds = _seconds % 60;
    
    cout << tempSeconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";
    
    
    
    return 0;
}