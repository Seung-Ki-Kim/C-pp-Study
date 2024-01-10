#include <iostream>
using namespace std;

class Vector {
private:
    double* elem;
    int sz;
public:
    Vector();
    Vector(int s);

    Vector(const Vector& a);    // 복사 생성자
    Vector& operator=(const Vector& a); // 복사 대입

    Vector(Vector&& a); // 이동 생성자
    Vector& operator=(Vector&& a);  // 이동 대입

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;

    ~Vector() { delete[] elem; }
};

Vector::Vector(const Vector &a) : elem{new double[a.sz]}, sz{a.sz} {
    for (int i = 0; i != sz; ++i) {
        elem[i] = a.elem[i];
    }
}

Vector::Vector(Vector &&a) : elem{a.elem}, sz{a.sz} {
    a.elem = nullptr;
    a.sz = 0;
}

Vector& Vector::operator=(const Vector &a) {
    double* p = new double[a.sz];

    for (int i = 0; i != a.sz; ++i) {
        p[i] = a.elem[i];
    }

    delete[] Vector::elem;

    Vector::elem = p;
    Vector::sz = a.sz;

    return *this;
}

Vector operator+(const Vector& a, const Vector& b) {
    if (a.size() != b.size()) {
        throw;
    }

    Vector res(a.size());

    for (int i = 0; i != a.size(); i++) {
        res[i] = a[i] + b[i];
    }

    return res;
}

void f(const Vector& x, const Vector& y, const Vector& z) {
    Vector r;

    r = x + y + z;
}

Vector f() {
    Vector x(1000);
    Vector y(2000);
    Vector z(3000);

    z = x;
    y = std::move(x);

    return z;
}



int main() {
    return 0;
}