#include <cstdio>

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
    if (length == 0) {
        return initial;
    }

    return fold(function, input + 1, length - 1, function(initial, *input));
}

int main() {
    int data[] = { 100, 200, 300, 400, 500 };
    size_t data_len = 5;

    auto sum =
            fold([](auto x, auto y) { return x + y; }, data, data_len, 0);

    printf("Sum: %d\n", sum);


    return 0;
}