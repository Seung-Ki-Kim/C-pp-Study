#include <iostream>
using namespace std;

int main() {
	double distance;
	double liter;
	double kiloPerLiter;
	
	cout << "Enter Distance: ";
	cin >> distance;

	cout << "Enter Liter: ";
	cin >> liter;

	kiloPerLiter = (distance / liter) * 100;

	cout << "Kilo Per Liter: " << kiloPerLiter << endl;


	return 0;
}
