#include <iostream>
#include <string>
using namespace std;

struct Profile {
    string firstName;
    string lastName;
    char grade;
    int age;
};

int main() {
    Profile* profile = new Profile();
    char grade;

    cout << "What is your first name? ";
    getline(cin, profile->firstName);

    cout << "What is your last name? ";
    getline(cin, profile->lastName);

    cout << "What letter grade do you deserve? ";
    cin >> grade;

    profile->grade = (char)(grade + 1);

    cout << "What is your age? ";
    cin >> profile->age;

    // RESULT //
    cout << "Name: " << profile->lastName << ", " << profile->firstName << endl;
    cout << "Grade: " << profile->grade << endl;
    cout << "Age: " << profile->age << endl;

    delete profile;
    return 0;
}