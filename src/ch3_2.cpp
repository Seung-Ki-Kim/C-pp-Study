#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int INCHES_PER_FEET = 12;
    const double INCHES_TO_METERS = 0.0254;
    const double POUNDS_TO_KILOGRAMS = 2.2;
    
    // User Input
    double heightFeet;
    double heightInches;
    double weightPounds;
    
    // converted
    double convertedHeightInches;
    double convertedHeightMeters;
    double convertedWeightKilo;
    
    double bmi;
    
    // Input; Height(feet), Height(inches), weight(pounds)
    cout << "Height(Feet): ";
    cin >> heightFeet;
    
    cout << "Height(Inches): ";
    cin >> heightInches;
    
    cout << "Weight(Pounds): ";
    cin >> weightPounds;
    
    // convert; Height(feet & inches) -> Height(inches)
    convertedHeightInches = (heightFeet * INCHES_PER_FEET) + heightInches;
    
    // convert; Height(inches) -> Height(meters)
    convertedHeightMeters = (convertedHeightInches * INCHES_TO_METERS);
    
    // convert; Weight(pounds) -> Weight(kilo)
    convertedWeightKilo = (weightPounds / POUNDS_TO_KILOGRAMS);
    
    // calculate BMI
    bmi = convertedWeightKilo / pow(convertedHeightMeters, 2);
    
    cout << "BMI: " << bmi;
    
    
    return 0;
}
