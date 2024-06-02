#include <iostream>
using namespace std;

int main() {
	double milePerGallon;
	double litersPer100km;

	cout << "Enter the automobile gasoline consumption figure in liters per 100 kilometers: ";
	cin >> litersPer100km;

	milePerGallon = (100.0 / litersPer100km) * (62.14 / 3.875);
	
	cout << "The gasoline consumption in miles per gallon is: " << milePerGallon << " mpg." << endl;


	return 0;
}
