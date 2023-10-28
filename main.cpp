#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
    string color;

public:
    Circle(double radius, string color) {
        this->radius = radius;
        this->color = color;
    }

    double calArea();
    string colorPrint();
};

double Circle::calArea() {
    return 3.14 * radius * radius;
}

string Circle::colorPrint() {
    return color;
}


int main() {
    Circle circle(5, "Black");

    cout << circle.calArea() << '\n';
    cout << circle.colorPrint() << '\n';

    return 0;
}