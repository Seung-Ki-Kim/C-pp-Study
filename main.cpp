#include <iostream>
using namespace std;

class Vector {
public:
    Vector();
    Vector(std::initializer_list<double>);
    void push_back(double);

    double *elem;
    int sz;
};

Vector read(istream& is) {
    Vector v = {1, 2};

    for (double d; is >> d;) {
        v.push_back(d);
    }

    return v;
}

Vector::Vector(std::initializer_list<double> lst) : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    copy(lst.begin(), lst.end(), elem);
}


class Container {
public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

void use(Container& c) {
    const int sz = c.size();

    for (int i = 0; i != sz; ++i) {
        cout << c[i] << '\n';
    }
}


int main() {
    return 0;
}