#include <iostream>
using namespace std;


int toSeconds(int days) {
   int hours = days * 24;
   int minutes = hours * 60;
   int seconds = minutes * 60;

   return seconds;
}

int main() {
    int days;

    cin >> days;
    cout << toSeconds(days) << endl;

    return 0;
}