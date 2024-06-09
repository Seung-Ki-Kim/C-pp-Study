#include <iostream>
using namespace std;

int main() {
    int number;
    
    cout << "Enter number of rows:";
    cin >> number;  
    
    for (int i = 1; i <= 5; ++i) {
        int l = 1;
        
        for (int j = number; j > i; --j) {
            cout << ".";
            l++;
        }

        for (int k = 0; k <= number - l; ++k) {
            cout << "*";
        }
        
        cout << endl;
    }
    
    
    return 0;
}