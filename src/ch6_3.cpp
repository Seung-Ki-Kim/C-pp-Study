#include <iostream>
using namespace std;

int main() {
    char menu[] = {'c', 'p', 't', 'g'} ;
    char userInput;
    bool repeatFlag = true;
    
    cout << "Please enter one of the following choices:\n"
            "c) carnivore p) pianist\n"
            "t) tree g) game\n";
    cin >> userInput;
    
    while (repeatFlag) {
        for (int i = 0; i < sizeof(menu) / sizeof(char); ++i) {
            if (menu[i] == userInput) {
                switch (userInput) {
                    case 'c' :
                        cout << "We are carnivore...OR NOT.\n";
                        break;

                    case 'p' :
                        cout << "Pianist is playing piano...OR NOT.\n";
                        break;

                    case 't' :
                        cout << "A maple is a tree...OR NOT.\n";
                        break;

                    case 'g':
                        cout << "Gamers are playing game...OR NOT.\n";
                        break;
                }

                repeatFlag = false;
            }
        }

        if (repeatFlag) {
            cout << "Please enter a c, p, t, or g:";
            cin >> userInput;
        }
    }
    
    
    return 0;
}