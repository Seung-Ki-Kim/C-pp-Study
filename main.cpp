#include <iostream>
using namespace std;

struct inflatable {
    char name[20];
    float volume;
    double price;
};

struct perks {
    int key_number;
    char car[12];
} mr_smith = {
        7,
        "Packard"
};

union one4all {
    int int_val;
    long long_val;
    double double_val;
};

int main () {
    inflatable guests[2] = {
            {"Bambi", 0.5, 21.99},
            {"Godzilla", 2000, 565.99}
    };
    
    cout << guests[0].name << endl; 
    cout << guests[1].name << endl;
    
    one4all pail;
    
    pail.int_val = 15;
    cout << pail.int_val << endl;
    
    pail.double_val = 1.38;
    cout << pail.double_val << endl;
    
    cout << pail.int_val << endl;


    enum bits{one = 1, two = 2, four = 4, eight = 8};
    bits myflag;
    
    myflag = bits(9);
    cout << myflag << endl;
    
    return 0;
}