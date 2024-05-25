#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    double a1[4] = {1.1, 2.2, 3.3, 4.4};

    vector<double> a2(4);
    a2[0] = 1.0;
    a2[1] = 2.0;
    a2[2] = 3.0;
    a2[3] = 4.0;

    array<double, 4> a3 = {1.1, 2.1, 3.1, 4.1};

    array<double, 4> a4;
    a4 = a3;

    cout << a1[0] << endl;
    cout << a2[1] << endl;
    cout << a3[2] << endl;
    cout << a4[3] << endl;


    return 0;
}
