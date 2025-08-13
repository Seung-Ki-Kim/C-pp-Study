#include <cstdio>


template <typename In>
struct GreaterThan100 {
    bool operator()(In x) const {
        return x > 100;
    };
};

template <typename Fn, typename In, typename Out>
constexpr bool all(Fn function, In* input, Out length) {
    for (int i = 0; i < length; i++) {
        if (!function(input[i])) {
            return false;
        }
    }

    return true;
}
int main() {
    int data[]{100, 200, 300, 400, 500};
    size_t data_len = 5;
    auto all_gt100 = all(GreaterThan100<int>{}, data, data_len);

    if (all_gt100) {
        printf("All elements greater than 100.\n");
    }
    else {
        printf("Not all elements greater than 100.\n");
    }

    return 0;
}