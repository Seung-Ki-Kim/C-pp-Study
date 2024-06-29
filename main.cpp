#include <iostream>
using namespace std;

const int MINS_PER_HOUR = 60;

struct travel_time {
    int hours;
    int mins;
};

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main() {
    travel_time day1 = {5, 45};
    travel_time day2 = {4, 55};

    travel_time trip = sum(day1, day2);

    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 = {4, 22};
    cout << "Three-day total: ";
    show_time(sum(trip, day3));


    return 0;
}

travel_time sum(travel_time t1, travel_time t2) {
    travel_time total;

    total.mins = (t1.mins + t2.mins) % MINS_PER_HOUR;
    total.hours = (t1.hours + t1.hours) + (t1.mins + t2.mins) / MINS_PER_HOUR;


    return total;
}

void show_time(travel_time t) {
    cout << t.hours << " : " << t.mins << endl;
}