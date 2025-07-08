#include <stdexcept>
#include <cstdio>
#include <cstring>

struct SimpleString {
private:
    size_t max_size;
    char* buffer;
    size_t length;

public:
    SimpleString(size_t max_size):
    max_size { max_size }, length {} {
        if (max_size == 0) {
            throw std::runtime_error { "Max size must be at lease 1." };
        }

        buffer = new char[max_size];
        buffer[0] = 0;
    }

    SimpleString(SimpleString&& other) noexcept:
    max_size { other.max_size }, buffer(other.buffer), length(other.length) {
        other.max_size = 0;
        other.buffer = nullptr;
        other.length = 0;
    }

    SimpleString& operator = (const SimpleString& other) {
        if (this == &other) { return *this; }

        const auto new_buffer = new char[other.max_size];
        delete[] buffer;

        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;

        std::strncpy(buffer, other.buffer,max_size);
        buffer[max_size - 1] = '\0';

        return *this;
    }

    SimpleString& operator = (SimpleString&& other) noexcept {
        if (this == &other) { return *this; }

        delete[] buffer;

        buffer = other.buffer;
        length = other.length;
        max_size = other.max_size;

        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;

        return *this;
    }

    ~SimpleString() {
        delete[] buffer;
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    bool append_line(const char* x) {
        const auto x_len = strlen(x);   // len of x

        if (x_len + length + 2 > max_size) {
            return false;
        }

        std::strncpy(buffer + length, x, max_size - length);

        length += x_len;
        buffer[length++] = '\n';    // new line
        buffer[length] = '\0';  // null byte

        return true;
    }
};

struct SimpleStringOwner {
private:
    SimpleString string;

public:
    SimpleStringOwner(SimpleString&& x) :
    string {std::move(x)} {
    }
};


int main() {
    SimpleString a { 50 };
    a.append_line("We apologize for the");

    SimpleString b { 50 };
    b.append_line("Last message");

    a.print("a");
    b.print("b");

    b = std::move(a);
    b.print("b");

	return 0;
}
