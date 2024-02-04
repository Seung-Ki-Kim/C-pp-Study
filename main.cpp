#include <iostream>
<<<<<<< Updated upstream
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

=======
#include "MyClass.h"
using namespace std;


int main() {
    MyClass obj(3, 5);
    obj.myPrint();
    
>>>>>>> Stashed changes
    return 0;
}