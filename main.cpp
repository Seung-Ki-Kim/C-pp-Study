#include <iostream>
using namespace std;

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


int main() {

    return 0;
}