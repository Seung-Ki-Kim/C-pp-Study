#include <iostream>
using namespace std;

enum class Color {
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
};

enum class Traffic_light {
    TRAFFIC_RED,
    TRAFFIC_GREEN,
    TRAFFIC_YELLOW
};

Traffic_light& operator++(Traffic_light& t) {
    switch(t) {
        case Traffic_light::TRAFFIC_GREEN :
            return t = Traffic_light::TRAFFIC_YELLOW;
        case Traffic_light::TRAFFIC_RED :
            return t = Traffic_light::TRAFFIC_GREEN;
        case Traffic_light::TRAFFIC_YELLOW :
            return t = Traffic_light::TRAFFIC_RED;
    }
}

class Circle {
private:
    double radius;
    Color color;

public:
    Circle(double radius, Color color) {
        this->radius = radius;
        this->color = color;
    }

    double calArea();
    Color getColor();
};

double Circle::calArea() {
    return 3.14 * radius * radius;
}

Color Circle::getColor() {
    return color;
}


int main() {
    Circle circle(5, Color::COLOR_BLACK);
    Traffic_light next;



    cout << circle.calArea() << '\n';
    cout << static_cast<int>(circle.getColor()) << '\n';
    cout << static_cast<int>(++next) << '\n';

    return 0;
}