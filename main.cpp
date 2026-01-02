#include <iostream>

int main() {
    std::shared_ptr<int> sh_ptr {
        new int { 10 },
        [](int* x) { delete x; },
        std::allocator<int>{}
    };

    auto sp = std::make_shared<int>(808);
    std::weak_ptr<int> wp{ sp };
}