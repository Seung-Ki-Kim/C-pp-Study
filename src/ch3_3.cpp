#include <iostream>
using namespace std;

int main() {
    double degrees;
    double min;
    double sec;
    
    double latitude;
    double minArc;
    double secArc;
    
    // User Input
    cout << "Enter a latitude in degrees, minutes, ad seconds: " << endl;
    
    cout << "First, enter the degrees: ";
    cin >> degrees;
    
    cout << "Next, enter the minutes of arc: ";
    cin >> min;
    
    cout << "Finally, enter the seconds of arc: ";
    cin >> sec;
    
    // Convert; (60sec -> 1min) & (60min -> 1deg)
    minArc = (min / 60);
    secArc = (sec / (60 * 60));
    
    // latitude Cal
    latitude = degrees + minArc + secArc;

    // Output
    cout << "Latitude in decimal format: " << latitude << endl;    
    
    return 0;
}