#include <iostream>
using namespace std;

int main() {
    int start;
    int end;
    int result;
    
    result = 0;
    
    cout << "Start num: ";
    cin >> start;
    
    cout << "End num: ";
    cin >> end;

    for (int i = start; i <= end; ++i) {
        result += i;
    }
    
    cout << "Result: " << result << endl;
    
    return 0;
}