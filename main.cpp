#include <iostream>
#include <mmcobj.h>

using namespace std;

enum Type {
    ptr,
    num
};

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}
    double& operator[](int i) { return elem[i]; }
    int size() { return sz; }
private:
    double* elem;
    int sz;
};


double read_and_sum(int s) {
    Vector v(s);
    double sum = 0;

    for (int i = 0; i != v.size(); ++i) {
        cin >> v[i];
        sum += v[i];
    }

    return sum;
}

union Value {
    Node *p;
    int i;
};

struct Entry {
    string name;
    Type t;
    Value v;
};

void f(Entry* pe) {
    if (pe -> t == num) {
        cout << pe -> v.i;
    }
}



int main() {
    cout << "Hello, world!" << "\n";

    return 0;
}