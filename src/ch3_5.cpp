#include <iostream>
using namespace std;

int main() {
	long long currentWorldPopulation;
	long long currentUSPopulation;

	cout << "Enter the world's population: ";
	cin >> currentWorldPopulation;
	
	cin.clear();

	cout << "Enter the population of the US: ";
    cin >> currentUSPopulation;

	cin.clear();

	double result = (static_cast<double>(currentUSPopulation) / static_cast<double>(currentWorldPopulation)) * 100;

	cout << "The population of the US is " << result << "%" << " of the world population." << endl;

    return 0;
}
