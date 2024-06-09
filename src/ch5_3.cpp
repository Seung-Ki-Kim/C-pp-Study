#include <iostream>
using namespace std;

int main() {
    int num;
    int sum;
    
    num = 0;
    sum = 0;
    
    while (true) {
        cout << "Input num:";
        cin >> num;
        
        if (num == 0) {
            break;
        }
        
        sum += num;
        
        cout << "Sum: " << sum << '\n';
    }
    
    return 0;
}