#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter words (to stop, type the word done): " << endl;
    
    string words;
    int count = 0;

    while (true) {
        cin >> words;

        if (words == "done") {
            break;
        }

        count += 1;
    }

    cout << count;

    return 0;
}