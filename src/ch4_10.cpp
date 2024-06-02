#include <iostream>
#include <array>
using namespace std;

int main() {
    array<double, 3> timeRecords;

    cout << "Enter your first time record for the 40-meter dash: ";
    cin >> timeRecords[0];

    cout << "Enter your second time record for the 40-meter dash: ";
    cin >> timeRecords[1];

    cout << "Enter your last time record for the 40-meter dash: ";
    cin >> timeRecords[2];

    cout << "Time (No.1): " << timeRecords[0] << " seconds" << endl;
    cout << "Time (No.2): " << timeRecords[1] << " seconds" << endl;
    cout << "Time (No.3): " << timeRecords[2] << " seconds" << endl;
    cout << "The Average Time: " << (timeRecords[0] + timeRecords[1] + timeRecords[2]) / 3 << " seconds" << endl;


    return 0;
}