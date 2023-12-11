#include <iostream>
#include "Data.h"
using namespace std;


int main() {
    Data<String_t> str_data("Hello, world!");
    Data<Double_t> double_data(3.14);

    cout << str_data.GetData() << endl;
    cout << double_data.GetData() << endl;

    return 0;
}