#include <iostream>
using namespace std;

int main() {
	double arr[10];
	double avg = 0;
	double overNum = 0;
	bool isBroken = false;

	for (int i = 0; i < sizeof(arr) / sizeof(double); i++) {
		cout << i << ": ";
		cin >> arr[i];
	
		if (cin.fail()) {
			cin.clear();
            isBroken = true;

			break;
		}
		else {
			avg += arr[i];
		}
	}
	
	if (!isBroken) {
		avg /= sizeof(arr) / sizeof(double);
	
		for (int i = 0; i < sizeof(arr) / sizeof(double); i++) {
			if (arr[i] > avg) {
				overNum += 1;
			}
		}

		cout << avg << endl;
		cout << overNum << endl;
	}

	return 0;
}
