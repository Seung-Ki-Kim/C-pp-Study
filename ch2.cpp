#include <cstdio>

enum Operaton {
	Add,
	Subtract,
	Multiply,
	Divide,
};

struct Calculator {
	Operaton op;

	Calculator(Operaton op) {  
		this->op = op;
	}

	int Calculate(int a, int b) { 
		switch (this->op) {
			case Operaton::Add :
				return (a + b);
			case Operaton::Subtract :
				return (a - b);
			case Operaton::Multiply :
				return (a * b);
			case Operaton::Divide :
				return b != 0 ? (a / b) : 0;
		}

		return 0;
	}
};

int main() {
	Calculator cal1(Add);
	printf("%d\n", cal1.Calculate(3, 5));


	return 0;
}
