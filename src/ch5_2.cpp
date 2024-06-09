#include <iostream>
using namespace std;

// array obj, long double
const int ArSize = 100;

int main() {
    long double* factorials = new long double[ArSize];
    
    factorials[1] = factorials[0] = 1;

    for (int i = 2; i < ArSize; ++i) {
        factorials[i] = i * factorials[i-1];
    }

    for (int i = 0; i < ArSize; ++i) {
        cout << i << "! = " << factorials[i] << endl;
    }

    delete[] factorials;
    return 0;
}