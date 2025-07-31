#include <cstddef>
#include <cstdio>


template<typename T, size_t length>
T mean(const T (&values)[length]) {    // T, length -> non-type
    T result {0};

    for (size_t i{}; i < length; i++) {
        result += values[i];
    }

    return (result / length);
}

int main() {
    const double nums_d[] { 1.0, 2.0, 3.0, 4.0 };
    const auto result1 = mean(nums_d);
    printf("double: %f\n", result1);

    const float nums_f[] { 1.0f, 2.0f, 3.0f, 4.0f };
    const auto result2 = mean(nums_f);
    printf("float: %f\n", result2);

    return 0;
}