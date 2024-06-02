#include <iostream>
#include <string>
using namespace std;

struct PizzaInfo {
    string name;
    float diameter;
    float weight;
};

int main() {
    PizzaInfo pizzaInfo;

    cout << "Pizza's name: ";
    getline(cin, pizzaInfo.name);

    cout << "Pizza's diameter: ";
    cin >> pizzaInfo.diameter;

    cout << "Pizza's weight: ";
    cin >> pizzaInfo.weight;

    cout << pizzaInfo.name << ": " << pizzaInfo.diameter << "cm, " << pizzaInfo.weight << "kg" << endl;


    return 0;
}