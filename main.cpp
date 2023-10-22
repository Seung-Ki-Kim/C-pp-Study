#include <iostream>
using namespace std;

void copy_fct() {
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10];

    for (auto i = 0; i < 10; i++) {
        v2[i] = v1[i];
    }
}

void refer_fct() {
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto& v2 : v1) {
        cout << v2 << ' ';
        v2++;
    }

    cout << ' ' << '\n';

    for (auto i : v1) {
        cout << i << ' ';
    }

    cout << ' ' << '\n';
}

struct Vector {
    int sz;
    double* elem;
};

void f(Vector v, Vector& rv, Vector* pv) {
    int i1 = v.sz;
    int i2 = rv.sz;
    int i4 = pv -> sz;
}

void vector_init(Vector& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s) {
    Vector v;
    double sum = 0;

    vector_init(v, s);

    for (int i = 0; i != s; ++i) {
        cin >> v.elem[i];
    }

    for (int j = 0; j != s; ++j) {
        sum += v.elem[j];
    }

    return sum;
}

int fuc(int* a) {
    *a *= 2;
    return *a;
}

int main() {
    refer_fct();

    int n = 3;
    cout << fuc(&n) << '\n';
    cout << n << '\n';

    return 0;
}