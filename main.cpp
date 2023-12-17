#include <iostream>

using namespace std;


double square(double x) {
    return (x * x);
}

void print_square(double x) {
    cout << "The square of " << "x is " << square(x) << "\n";
}

int main() {
    cout << "Hello, world!" << "\n";
    print_square(3);

    return 0;
}