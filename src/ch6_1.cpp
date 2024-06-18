#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string str;

	cout << "Input (@ to exit): ";
	cin >> str;
	
	while (str != "@") {
	    for (int i = 0; i < str.size(); i++) {
			if (islower(str[i])) {
				str[i] = toupper(str[i]);
			}
			else if (isupper(str[i])) {
				str[i] = tolower(str[i]);
			}
		}

		cout << str << endl;

		cout << "Input (@ to exit): ";
		cin >> str;
	}

	return 0;
}
