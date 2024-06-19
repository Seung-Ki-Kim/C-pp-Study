/*
Put together a program that keeps track of monetary contributions to the Society for the Preservation of Rightful Influence.
It should ask the user to (enter the number of contributors) and then solicit the user to (enter the name and contribution of each contributor).
The information should be stored in a dynamically allocated (array of structures).
Each structure should have two members: a character array or else a string object to store the name and a double member to hold the amount of the contribution.
After reading all the data, the program should display the names and amounts donated for all donors who contributed $10,000 or more.
This list should be headed by the label Grand Patrons.
After that,the program should list the remaining donors.That list should be headed Patrons.
If there are no donors in one of the categories, the program should print the word “none.”
Aside from displaying two categories, the program need do no sorting.
*/


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