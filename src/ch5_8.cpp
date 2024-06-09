#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cout << "Enter words (to stop, type the word done): " << endl;
    char words[100];
    int count = 0;
    
    while (true) {
        cin >> words;
        
        if (strcmp(words, "done") == 0) {
            break;
        }
        
        count += 1;
    }
    
    cout << count;
    
    return 0;
}