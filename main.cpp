#include <iostream>
using namespace std;

class Mother {
public:
    Mother();
    ~Mother();
};

Mother::Mother() {
    cout << "Mother's Constructor" << endl;
}

Mother::~Mother() {
    cout << "Mother's Destructor" << endl;
}


class Daughter : public Mother {
public:
    Daughter();
    ~Daughter();
};

Daughter::Daughter() {
    cout << "Daughter's Constructor" << endl;
}

Daughter::~Daughter() {
    cout << "Daughter's Destructor" << endl;
}


int main() {
    Mother m;
    Daughter d;
    return 0;
}