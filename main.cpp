#include <iostream>
using namespace std;

enum Type
{
    ptr,
    num
};

struct Entry {
    string name;
    Type t;
    Node* p;
    int i;
};

void f (Entry* pe) {
    if (pe -> t == num) {
        cout << pe -> i;
    }
}

int main() {

    return 0;
}