#include <iostream>
using namespace std;

const int strsize = 100;
struct bop {
    char fullname[strsize];     // real name
    char title[strsize];        // job title
    char bopname[strsize];      // secret BOP name
    int preference;             // 0 = fullname, 1 = title, 2 = bopname
};

int main() {
    bop members[5] = {
            {"Wimp Macho", "CEO", "WIMPY", 0},
            {"Raki Rhodes", "Junior Programmer", "RADIATOR", 1},
            {"Celia Laiter", "Senior Programmer", "MIPS", 2},
            {"Hoppy Hipman", "Analyst Trainee", "HIPSTER", 1},
            {"Pat Hand", "Manager", "LOOPY", 2}
    };
    char userInput;
    
    cout << "Benevolent Order of Programmers Report\n"
         << "a. display by name\n"
         << "b. display by title\n"
         << "c. display by bopname\n"
         << "d. display by preference\n"
         << "q. quit\n";
    cout << "Enter your choice:";

    do {
        cin >> userInput;
        cin.ignore();

        switch (userInput) {
            case 'a':
                for (int i = 0; i < sizeof(members) / sizeof(bop); ++i) {
                    cout << members[i].fullname << endl;
                }
                break;
            case 'b':
                for (int i = 0; i < sizeof(members) / sizeof(bop); ++i) {
                    cout << members[i].title << endl;
                }
                break;
            case 'c':
                for (int i = 0; i < sizeof(members) / sizeof(bop); ++i) {
                    cout << members[i].bopname << endl;
                }
                break;
            case 'd':
                for (int i = 0; i < sizeof(members) / sizeof(bop); ++i) {
                    switch (members[i].preference) {
                        case 0:
                            cout << members[i].fullname << endl;
                            break;
                        case 1:
                            cout << members[i].title << endl;
                            break;
                        case 2:
                            cout << members[i].bopname << endl;
                            break;
                    }
                }
                break;
            case 'q':
                cout << "Bye!" << endl;
                break;
        }

        cout << "Next choice:";
    }
    while (userInput != 'q');
    
    
    
    

    return 0;
}