#include <iostream>
using namespace std;

int main() {
    double lightYears;
    
    cout << "Enter the number of light years: ";
    cin >> lightYears;
    cout << lightYears << " light years = " << (lightYears * 63240) << " astronomical units";
    
    return 0;
}