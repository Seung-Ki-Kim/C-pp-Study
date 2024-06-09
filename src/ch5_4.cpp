#include <iostream>
using namespace std;

int main() {
    const double daphneInvestment = 100.0;
    const double cleoInvestment = 100.0;
    const double daphneInterestRate = 0.10;
    const double cleoInterestRate = 0.05;
    
    double daphneBalance = daphneInvestment;
    double cleoBalance = cleoInvestment;
    int years = 0;
    
    while (cleoBalance <= daphneBalance) {
        daphneBalance += daphneInvestment * daphneInterestRate;
        cleoBalance *= (1 + cleoInterestRate);
        years++;
    }
    
    cout << "Years: " << years << endl;
    cout << "Daphne's Balance: " << daphneBalance << endl;
    cout << "Cleo's Balance: " << cleoBalance << endl;
    
    return 0;
}