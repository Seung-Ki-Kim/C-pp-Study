#include <iostream>
#include <thread>
#include <vector>

using namespace std;
std::vector<thread> my_threads;

class Vector {
private:
    double* elem;
    int sz;
public:
    Vector();
    Vector(int sz);

    Vector(const Vector& copyVector);
    Vector& operator=(const Vector& copyVector);

    Vector(Vector&& moveVector);
    Vector& operator=(Vector&& moveVector);

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;

    ~Vector() {
        delete[] elem;
    };
};

Vector::Vector(const Vector& copyVector) {  // 복사 생성자
    elem = new double[copyVector.sz];
    sz = copyVector.sz;

    for (int i = 0; i != sz; i++) {
        elem[i] = copyVector[i];
    }
}

Vector& Vector::operator=(const Vector& copyVector) {   // 복사 대입 연산자
    double* p = new double[copyVector.sz];

    for (int i = 0; i != copyVector.sz; i++) {
        p[i] = copyVector.elem[i];
    }

    delete[] elem;

    elem = p;
    sz = copyVector.sz;

    return *this;
}

Vector init(int n) {
    thread t = heartbeat;
    my_threads.push_back(std::move(t));

    Vector vec(n);

    for (int i = 0; i != vec.size(); i++) {
        vec[i] = 777;
    }

    return vec;
}

int main() {
    auto v = init(1000000);

    return 0;
}