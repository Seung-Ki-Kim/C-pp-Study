#include <iostream>
using namespace std;

void blind_mice(int count) {
	for (int i = 0; i < count; i++) {
		cout << "Three blind mice " << endl;		
	}
}

void they_run(int count) {
	for (int i = 0; i < count; i++) {
		cout << "See how they run" << endl;
	}
}

int main() {
	blind_mice(2);
	they_run(2);

	return 0;
}