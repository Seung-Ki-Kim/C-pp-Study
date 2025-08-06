#include <cstdio>
#include <vector>

struct UnsignedBigInteger {
private:
    std::vector<uint8_t> byte_arr; // [5, 4, 3, 2, 1]

public:
    UnsignedBigInteger();
    explicit UnsignedBigInteger(unsigned int val);

    UnsignedBigInteger operator+(const UnsignedBigInteger& other) const;
    UnsignedBigInteger operator-(const UnsignedBigInteger& other) const;

    UnsignedBigInteger operator+(const int& other) const;
    UnsignedBigInteger operator-(const int& other) const;


    explicit operator int() const;
};

UnsignedBigInteger::UnsignedBigInteger() = default;

UnsignedBigInteger::UnsignedBigInteger(unsigned int val) {   // 12345
    if (val == 0) {
        byte_arr.push_back(0);
        return;
    }

    while (val > 0) {
        byte_arr.push_back(val % 10);
        val /= 10;
    }
}

UnsignedBigInteger UnsignedBigInteger::operator+(const UnsignedBigInteger &other) const {
    UnsignedBigInteger result;
    auto max_len = std::max(byte_arr.size(), other.byte_arr.size());
    uint8_t carry = 0;  // 자릿수

    for (size_t i = 0; i < max_len; i++) {
        uint8_t this_val = (i < byte_arr.size()) ? byte_arr[i] : 0;
        uint8_t other_val = (i < other.byte_arr.size()) ? other.byte_arr[i] : 0;

        uint8_t sum_val = this_val + other_val + carry;

        result.byte_arr.push_back(sum_val % 10);    // 뒷자리
        carry = (sum_val / 10);  // 앞자리
    }

    return result;
}

UnsignedBigInteger UnsignedBigInteger::operator-(const UnsignedBigInteger &other) const {
    UnsignedBigInteger result(0);
    auto max_len = byte_arr.size();
    uint8_t borrow = 0; // 빌린 수

    for (size_t i = 0; i < max_len; i++) {
        uint8_t this_val = byte_arr[i];
        uint8_t other_val = (i < other.byte_arr.size()) ? other.byte_arr[i] : 0;

        uint8_t diff_val = this_val - other_val - borrow;

        if (diff_val < 0) {
            diff_val += 10;
            borrow = 1;
        }

        result.byte_arr.push_back(diff_val);
    }

    return result;
}

UnsignedBigInteger UnsignedBigInteger::operator+(const int &other) const {
    UnsignedBigInteger other_cast(other);
    return *this + other_cast;
}

UnsignedBigInteger UnsignedBigInteger::operator-(const int &other) const {
    UnsignedBigInteger other_cast(other);
    return *this - other_cast;
}

UnsignedBigInteger::operator int() const {
    int result = 0;
    int multiplier = 1;

    for (uint8_t i : byte_arr) {
        if (i != 0 && multiplier > INT_MAX / i) {
            throw std::overflow_error("Multi overflow");
        }

        int val = i * multiplier;

        if (result > INT_MAX - val) {
            throw std::overflow_error("Sum overflow");
        }

        result += val;
        multiplier *= 10;
    }

    return result;
}


int main() {
    UnsignedBigInteger a(123);
    int b = 123;
    auto c = a + b;

    printf("%d\n", (int)c);


    return 0;
}