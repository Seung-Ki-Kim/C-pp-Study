/*
The Kingdom of Neutronia, where the unit of currency is the tvarp, has the following income tax code:
    First 5,000 tvarps: 0% tax
    Next 10,000 tvarps: 10% tax
    Next 20,000 tvarps: 15% tax
    Tvarps after 35,000: 20% tax
For example, someone earning 38,000 tvarps would owe (5,000 × 0.00) + (10,000 × 0.10) + (20,000 × 0.15) + (3,000 × 0.20), or 4,600 tvarps.
Write a program that uses a loop to solicit incomes and to report tax owed.
The loop should terminate when the user enters a negative number or non-numeric input.
*/

#include <iostream>
using namespace std;

int main() {
    float tyarps;
    float result = 0;

    float values[3] = {5000, 10000, 20000};
    float percents[3] = {0.00, 0.10, 0.15};

    cout << "Input tyarps: ";
    cin >> tyarps;


    if (tyarps >= 35000) {
        for (int i = 0; i < sizeof(values) / sizeof(float); ++i) {
            result += values[i] * percents[i];
        }

        result += (tyarps - 35000) * 0.20;
    }
    else {
        int i = 0;

        while (tyarps > 0) {
            tyarps -= values[i];
            result += values[i] * percents[i];
            i += 1;
        }
    }

    cout << result << endl;

    return 0;
}