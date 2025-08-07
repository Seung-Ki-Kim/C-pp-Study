#include <iostream>
#include "FibonacciRange.cpp"

int main() {
    for (int n : FibonacciRange(10)) {
        std::cout << n << std::endl;
    }
}
