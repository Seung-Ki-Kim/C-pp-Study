#include <iostream>
using namespace std;

int main() {
    double wages[3] = {1.0, 2.0, 3.0};
    short stacks[3] = {3, 2, 1};
    
    double* pWages = wages;
    short* pStacks = stacks;
    
    cout << "pWages: " << *pWages << endl;
    cout << "pStacks: " << *pStacks << endl;

    pWages += 1;
    pStacks += 1;
    
    cout << "pWages: " << *pWages << endl;
    cout << "pStacks: " << *pStacks << endl;

    return 0;
}