#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct contributors {
    string name;
    float contribution;
};

int main() {
    int number;
    bool flag;

    cout << "How many contributors are there? ";
    cin >> number;

    contributors* arr = new contributors[number];

    for (int i = 0; i < number; ++i) {
        cout << "Name: ";
        cin >> arr[i].name;

        cout << "contribution: ";
        cin >> arr[i].contribution;
    }

    cout << "Grand Contributors" << endl;
    flag = false;

    for (int i = 0; i < number; ++i) {
        if (arr[i].contribution >= 10000) {
            cout << arr[i].name << ": " << arr[i].contribution << endl;
            flag = true;
        }
    }

    if (!flag) {
        cout << "none." << endl;
    }

    cout << "Other Contributors" << endl;
    flag = false;

    for (int i = 0; i < number; ++i) {
        if (arr[i].contribution < 10000) {
            cout << arr[i].name << ": " << arr[i].contribution << endl;
            flag = true;
        }
    }

    if (!flag) {
        cout << "none." << endl;
    }

    delete[] arr;
    return 0;
}