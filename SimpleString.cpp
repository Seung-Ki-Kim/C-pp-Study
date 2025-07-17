#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
    size_t max_size;
    int length;
    char* buffer;

    // Default Constructor
    SimpleString(size_t max_size)
    : max_size{ max_size }, length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." };
        }

        this->buffer = new char[max_size];
        this->buffer[0] = 0;
    }

    // Copy Constructor
    SimpleString(const SimpleString& other)
    : max_size{ other.max_size }, length{}, buffer{ new char[other.max_size] } {
        strncpy(this->buffer, other.buffer, max_size);
    }

    // Move Constructor
    SimpleString(SimpleString&& other) noexcept
    : max_size{ other.max_size }, buffer{ other.buffer }, length{ other.length } {
        other.max_size = 0;
        other.buffer = nullptr;
        other.length = 0;
    }

    // Copy Operator
    SimpleString& operator = (const SimpleString& other) {
        if (this == &other) { return *this; }

        delete[] buffer;    // memory leak prevent
        this->buffer = new char[other.max_size];
        this->max_size = other.max_size;
        this->length = other.length;

        strncpy(buffer, other.buffer, other.max_size);

        return *this;
    }

    // Move Operator
    SimpleString& operator = (SimpleString&& other) noexcept {
        if (this == &other) { return *this; }

        delete[] buffer;
        this->buffer = other.buffer;
        this->max_size = other.max_size;
        this->length = other.length;

        other.buffer = nullptr;
        other.max_size = 0;
        other.length = 0;

        return *this;
    }
};


int main() {
    return 0;
}