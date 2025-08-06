// Create a LargeBucket class that can store up to 1MB of data.
// Extend the Heap class so it gives out a LargeBucket for allocations greater than 4096 bytes.
// Make sure that you still throw std::bad_alloc whenever the Heap is unable to allocate an appropriately sized bucket.


#include <cstddef>
#include <iostream>

struct LargeBucket {
private:
    static constexpr size_t SIZE = 1024 * 1024;
    std::byte data[SIZE];
public:

};

int main() {


    return 0;
}
