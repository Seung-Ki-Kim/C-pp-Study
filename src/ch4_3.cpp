#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char tempFirstName[20];
    char tempLastName[20];
    char* fullName;

    cout << "Enter your first name: ";
    cin.getline(tempFirstName, 20);

    cout << "Enter your last name: ";
    cin.getline(tempLastName, 20);

    int sizeFirstName = strlen(tempFirstName);
    int sizeLastName = strlen(tempLastName);

    fullName = new char[sizeFirstName + 2 + sizeLastName + 1];

    strcpy(fullName, tempLastName);
    strcat(fullName, ", ");
    strcat(fullName, tempFirstName);

    cout << "Here's the information in a single string: " << fullName << endl;


    return 0;
}