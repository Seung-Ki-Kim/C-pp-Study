#include <iostream>
#include "MyClass.h"
using namespace std;


MyClass::MyClass(int a, int b) : regVar(a), constVar(b) {
    cout << "Constructor" << endl;
}

void MyClass::myPrint() {
    cout << "Hello, world!" << endl;
    
    cout << "a: " << regVar << endl;
    cout << "b: " << constVar << endl;
}

MyClass::~MyClass() {
    cout << "Destructor" << endl;
}