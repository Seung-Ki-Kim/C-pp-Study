#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int INCHES_PER_FEET = 12;
    int userHeightInches;
    int convertedUserHeightFeet;
    int convertedUserHeightInches;
    
    cout << "Enter Height(Inches):"; 
    cin >> userHeightInches;

    convertedUserHeightFeet = (userHeightInches / INCHES_PER_FEET);
    convertedUserHeightInches = (userHeightInches % INCHES_PER_FEET); 
    
    cout << "Converted Height(Feet & Inches): " << setw(2) << setfill('_') << convertedUserHeightFeet << " Feet " << setw(2) << setfill('_') << convertedUserHeightInches << " Inches" << endl;
    
    
    return 0;
}