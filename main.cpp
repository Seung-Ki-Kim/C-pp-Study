#include <iostream>
using namespace std;

int main() {
    int nights = 1001;
    int* pn = &nights;

    int* pt = new int;
    *pt = 1001;

    cout << "pn : " << *pn << endl;
    cout << "pt : " << *pt << endl;


    return 0;
}