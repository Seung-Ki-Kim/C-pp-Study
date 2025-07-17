#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <sys/time.h>
#include <unistd.h>

struct TimerClass {
    int in_time{};
    int out_time{};
    int age{};
    char* name{};
    timeval timestamp{};
    bool is_moved = false;

    TimerClass(const char* name) {
        this->name = new char[strlen(name)+1];
        std::strcpy(this->name, name);
        gettimeofday(&timestamp, nullptr);
        in_time = timestamp.tv_sec;
    }

    TimerClass(const TimerClass& other) {
        timestamp = other.timestamp;
    }

    TimerClass(TimerClass&& other)  noexcept {
        timestamp = other.timestamp;
        other.timestamp = {};

        other.is_moved = true;
    }

    ~TimerClass() {
        if (is_moved) {
            return;
        }

        gettimeofday(&timestamp, nullptr);
        out_time = timestamp.tv_sec;
        age = out_time - in_time;

        printf("in_time: %d\n", in_time);
        printf("out_time: %d\n", out_time);
        printf("%s: %d", this->name, age);

        delete[] name;
    }

    TimerClass& operator = (const TimerClass& other) {
        if (this == &other) { return *this; }

        timestamp = other.timestamp;

        return *this;
    }

    TimerClass& operator = (TimerClass&& other) noexcept {
        if (this == &other) { return *this; }

        timestamp = other.timestamp;
        other.timestamp = {};
        other.is_moved = true;

        return *this;
    }
};


int main() {
    TimerClass timer("t1");
    sleep(1);

    return 0;
}