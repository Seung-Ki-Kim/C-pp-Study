#include<cstdio>
#include <cstring>
#include <stdexcept>


int& get(int (&arr)[10], size_t index) {
    if (index >= 10) {
        throw std::out_of_range{ "Out of bounds" };
    }

    return arr[index];
}

template <typename T, size_t length>
T& get(T (&arr)[length], size_t index) {
    if (index >= length) {
        throw std::out_of_range{ "Out of bounds" };
    }

    return arr[index];
}

template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
    static_assert(Index < Length, "Out-of-bounds access");  // (False -> error msg)

    return arr[Index];
}

template <typename T>
struct SimpleUniquePointer {};

template <typename T, typename... Arguments>
SimpleUniquePointer<T> make_simple_unique(Arguments... arguments) {
    return SimpleUniquePointer<T>{ new T{ arguments... } };
}


int main() {
    printf("Hello, world!\n");
    printf("\n");

    int fib[] {1, 1, 2, 0};
    printf("%d %d %d ", get<0>(fib), get<1>(fib), get<2>(fib));
    get<3>(fib) = get<1>(fib) + get<2>(fib);

    get<int>(fib, 1);

    printf("%d", get<3>(fib));
//    printf("%d", get<4>(fib));



    return 0;
}
