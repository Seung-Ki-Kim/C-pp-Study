#include <iostream>
#include "PrimeNumberRange.cpp"


int main() {
	for (int i : PrimeNumberRange(0, 5000)) {
		std::cout << i << " ";
	}
	
	std::cout << "\n";


	return 0;
}
