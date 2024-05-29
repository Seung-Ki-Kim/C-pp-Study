#include <iostream>
using namespace std;

int main() {
    float celsiusValue;
    
    cout << "Please enter a Celsius value: ";
    cin >> celsiusValue;
    cout << celsiusValue << " degrees Celsius is " << (1.8f * celsiusValue + 32.0f) << " degrees Fahrenheit.";
    
    return 0;
}