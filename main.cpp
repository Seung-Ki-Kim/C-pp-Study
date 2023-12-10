#include <iostream>
#include "Dog.h"
#include "Cat.h"

using namespace std;

<<<<<<< Updated upstream
class complex {
    double re, im;

public:
    complex(double r, double i) : re{r}, im{i} {
        // Constructor
    }

    complex(double r) : re{r}, im{0} {
        // Constructor
    }

    complex() : re{0}, im{0} {
        // Constructor
    }

    double real() const {
        return re;
    }

    void real(double d) {
        re = d;
    }

    double image() const {
        return im;
    }

    void imag(double d) {
        im = d;
    }

    complex& operator+=(complex z) {
        re += z.re;
        im += z.im;

        return *this;
    }

    complex& operator-=(complex z) {
        re -= z.re;
        im -= z.im;

        return *this;
    }

    complex& operator*=(complex);
    complex& operator/=(complex);
};
=======

template <typename T>
void Swap(T& a, T& b) {
    T temp;

    temp = a;

    a = b;
    b = temp;
}

template <> void Swap<double>(double& a, double& b) {
    // Pass
}
>>>>>>> Stashed changes


int main() {
    int x = 2;
    int y = 3;

<<<<<<< Updated upstream
=======
    cout << "- Before" << endl;
    cout << "x: " << x << ", y: " << y << endl;

    Swap(x, y);

    cout << "- After" << endl;
    cout << "x: " << x << ", y: " << y << endl;

    char i = 'i';
    char j = 'j';

    cout << "- Before" << endl;
    cout << "i: " << i << ", j: " << j << endl;

    Swap(i, j);

    cout << "- After" << endl;
    cout << "i: " << i << ", j: " << j << endl;

    double l = 2.5;
    double m = 3.5;

    cout << "- Before" << endl;
    cout << "l: " << l << ", m: " << m << endl;

    Swap(l, m);

    cout << "- After" << endl;
    cout << "l: " << l << ", m: " << m << endl;

>>>>>>> Stashed changes
    return 0;
}