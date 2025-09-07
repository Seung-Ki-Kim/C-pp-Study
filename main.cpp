#include <memory>

using SharedOathbreakers = std::shared_ptr<int>;

int main() {
    SharedOathbreakers sh_ptr { new int { 10 }, [](int* x) { delete x; }, std::allocator<int>{} };
    auto shd_ptr = std::allocate_shared<int>(std::allocator<int>{}, 10);
    auto mk_ptr = std::make_shared<int>(1011);
    
    return 0;
}