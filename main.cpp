#include <iostream>
using namespace std;

template <class T>
class Div {
public:
    Div(T x, T y) {
        cout << (x / y) << endl;
    }
};

// your code goes here
template <>
class Div<string> {
public:
    Div(string x, string y) {
        cout << (x.length() / y.length()) << endl;
    }
};


int main () {
    int x, y;
    string a, b;

    cin >> a >> b;
    cin >> x >> y;

    Div <int> d1(x, y);
    Div <string> d2(a, b);
}