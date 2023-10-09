#include <iostream>
using namespace std;



int main() {
    int i = 0;
    char v[6];

    while (i < 3) {
        i += 1;
        cout << i;
    }

    for (int j = 0; j < 3; j++) {
        cout << j;
    }

    for (int k : {0, 1, 2}) {
        cout << k;
    }


    return 0;
}