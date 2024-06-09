#include <iostream>
using namespace std;

const int MONTHS = 12;

int main() {
    string* months = new string[MONTHS] {
            "1월", "2월", "3월", "4월", "5월", "6월",
            "7월", "8월", "9월", "10월", "11월", "12월"
    };
    int monthlySales[MONTHS];
    int totalSales = 0;

    for (int i = 0; i < MONTHS; ++i) {
        cout << months[i] << ":";
        cin >> monthlySales[i];
        
        totalSales += monthlySales[i];
    }
    
    cout << "Total: " << totalSales << endl;
    
    
    return 0;
}