#include <iostream>
#include "PrimeNumberRange.cpp"


int main() {
	for (int i : PrimeNumberRange(10, 30)) {
		std::cout << i << " ";
	}
	
	std::cout << "\n";


	return 0;
}
