#include <iostream>
using namespace std;

struct CandyBar {
    string name;
    double weight;
    int calories;
};

int main() {
    CandyBar snacks[5];

    snacks[0].name = "KitKat";
    snacks[0].weight = 3.5;
    snacks[0].calories = 560;

    snacks[1].name = "Oreo";
    snacks[1].weight = 6.7;
    snacks[1].calories = 608;

    snacks[2].name = "Kid-O";
    snacks[2].weight = 2.3;
    snacks[2].calories = 567;

    snacks[3].name = "Choco Pi";
    snacks[3].weight = 3;
    snacks[3].calories = 807;

    snacks[4].name = "Langue de chat";
    snacks[4].weight = 5.0;
    snacks[4].calories = 677;

    for (int i = 0; i < 5; ++i) {
        cout << snacks[i].name << ": " << snacks[i].weight << "kg, " << snacks[i].calories << "kCal" << endl;
    }


    return 0;
}