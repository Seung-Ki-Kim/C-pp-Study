#include <iostream>
using namespace std;

namespace My_Code {
    class complex {

    };
    complex sqrt(complex);
    int main();
}

int My_Code::main() {
    complex z {1, 2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
}


int main() {

    return My_Code::main();
}