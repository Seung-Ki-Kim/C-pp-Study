#include <iostream>
using namespace std;

struct CandyBar {
    string name;
    double weight;
    int calories;
};

int main() {
    CandyBar* snack = new CandyBar {"Mocha Munch", 2.3, 350};

    cout << "Candy bar name: " << snack->name << endl;
    cout << "Candy bar weight: " << snack->weight << endl;
    cout << "Candy bar calories: " << snack->calories << endl;

    delete snack;
    return 0;
}