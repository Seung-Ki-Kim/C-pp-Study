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


int main () {
    inflatable guest = {
            "Glorious Gloria",
            1.88,
            29.99
    };
    
    inflatable pal = guest;
    
    struct {
        int x;
        int y;
    } position;
    
    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    
    return 0;
}