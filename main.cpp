#include <iostream>
using namespace std;

class Vector {
public :
    Vector(int s);
    double& operator[](int i);
    int size();
private :
    double* elem;
    int sz;
};

Vector::Vector(int s):elem{new double[s]},sz{s} { // Constructor
    // Vector algorithm
}

double& Vector::operator[](int i) {
    return elem[i];
}

int Vector::size() {
    return sz;
}

double sqrt(double);    // Root function

double sqrt(double d) { // Definition
    // sqrt algorithm
}

int main() {

    return 0;
}