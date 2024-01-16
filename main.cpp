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

void f(const Vector<string>& vectorStr) {
    for (int i = 0; i != vectorStr.size(); i++) {
        cout << vectorStr[i] << endl;
    }
}



int main() {
    Vector<char> vectorChar(200);
    Vector<int> vectorInt(300);
    Vector<list<int>> vectorListInt(400);

    return 0;
}