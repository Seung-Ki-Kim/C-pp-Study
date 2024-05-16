#include <iostream>
using namespace std;

int main() {
    int* ps = new int;
    int* pq = ps;
    
    *ps = 3;
    
    cout << &ps << endl;
    cout << &pq << endl;
    
    delete pq;
    
    cout << &ps << endl;
    cout << &pq << endl;

    return 0;
}