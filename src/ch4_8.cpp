#include <iostream>
#include <string>
using namespace std;

struct PizzaInfo {
    string name;
    float diameter;
    float weight;
};

int main() {
    PizzaInfo* pizzaInfo = new PizzaInfo();

    cout << "Pizza's diameter: ";
    cin >> pizzaInfo->diameter;

    cin.ignore();

    cout << "Pizza's name: ";
    getline(cin, pizzaInfo->name);

    cout << "Pizza's weight: ";
    cin >> pizzaInfo->weight;

    cout << pizzaInfo-> name << ": " << pizzaInfo->diameter << "cm, " << pizzaInfo->weight << "kg" << endl;

    delete pizzaInfo;
    return 0;
}