#include <iostream>
using namespace std;

struct CandyBar {
    string name;
    double weight;
    int calories;
};

int main() {
    CandyBar* snacks = new CandyBar[5] {
            {"KitKat", 1.5, 560},
            {"Oreo", 6.6, 607},
            {"Kid-O", 2.3, 234},
            {"Choco Pi", 3, 807},
            {"Langue de chat", 1.0, 675},
    };

    for (int i = 0; i < 5; ++i) {
        cout << snacks[i].name << ": " << snacks[i].weight << "kg, " << snacks[i].calories << "kCal" << endl;
    }


    delete[] snacks;
    return 0;
}