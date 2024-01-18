#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Vector {
private:
    T* elem;
    int sz;
public:
    explicit Vector(int s);
    T& operator[](int i);
    const T& operator[](int i) const;

    int size() const {
        return sz;
    }

    ~Vector() {
        delete[] elem;
    }
};

template<typename T>
Vector<T>::Vector(int s) {
    if (s < 0){
        throw;
    }

    elem = new T[s];
    sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const {
    if (i < 0 || size() <= i) {
        throw out_of_range("Vector::operator[]");
    }

    return elem[i];
}

template<typename T>
T* begin(Vector<T>& x) {
    return x.size() ? &x[0] : nullptr;
}

template<typename T>
T* end(Vector<T>& x) {
    return x.size() ? &x[0] + x.size() : nullptr;
}

void f1(const Vector<string>& vectorStr) {
    for (int i = 0; i != vectorStr.size(); i++) {
        cout << vectorStr[i] << endl;
    }
}

void f2(Vector<string>& vs) {
    for (auto& s : vs) {
        cout << s << '\n';
    }
}

template<typename T, int N>
struct Buffer {
    using value_type = T;
    constexpr int size() {
        return N;
    }
};

Buffer<char, 1024> glob;

void fct() {
    Buffer<int, 10> buf;
    cout << buf.size() << '\n';
}



int main() {
    Vector<char> vectorChar(200);
    Vector<int> vectorInt(300);
    Vector<list<int>> vectorListInt(400);

    pair<int, double> p = { 1, 5.2 };

    return 0;
}