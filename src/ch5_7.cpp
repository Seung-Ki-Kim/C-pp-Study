#include <iostream>
using namespace std;

struct Car {
    string make;
    int year;
};

int main() {
    int catalogs;

    cout << "How many cars do you wish to catalog?";
    cin >> catalogs;
    cin.ignore();

    Car* cars = new Car[catalogs];

    for (int i = 1; i <= catalogs; ++i) {
        cout << "Car #" << i << ":" << endl;

        cout << "Please enter the make:";
        getline(cin, cars[i-1].make);

        cout << "Please enter the year made:";
        cin >> cars[i-1].year;
        cin.ignore();
    }

    cout << "Here is your collection:" << endl;

    for (int i = 0; i < catalogs; ++i) {
        cout << cars[i].year << " " << cars[i].make << endl;
    }

    delete[] cars;
    return 0;
}