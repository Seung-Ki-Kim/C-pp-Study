#include <cstdio>
#include <cstddef>
#include <new>
#include <vector>

struct LargeBucket {
    static constexpr size_t SIZE = 1024 * 1024;
    std::byte data[SIZE]{};
    bool used = false;

    void* allocate(size_t size) {
        if (used || size > SIZE) {
            return nullptr;
        }

        used = true;

        return data;
    }
};

struct SmallBucket {
    static constexpr size_t SIZE = 4096;
    std::byte data[SIZE]{};
    bool used = false;

    void* allocate(size_t size) {
        if (used || size > SIZE) {
            return nullptr;
        }

        used = true;

        return data;
    }
};

struct Heap {
private:
    std::vector<SmallBucket> smallBuckets;
    std::vector<LargeBucket> largeBuckets;
public:
    Heap() {
        addSmallBucket();
        addLargeBucket();
    }

    void addSmallBucket() {
        smallBuckets.emplace_back();
    }

    void addLargeBucket() {
        largeBuckets.emplace_back();
    }

    void* allocate(size_t size) {
        if (size > SmallBucket::SIZE) {
            for (LargeBucket& bucket : largeBuckets) {
                void* ptr = bucket.allocate(size);

                if (ptr) {
                    printf("Large\n");
                    return ptr;
                }
            }
        } else {
            for (SmallBucket& bucket : smallBuckets) {
                void* ptr = bucket.allocate(size);

                if (ptr) {
                    printf("Small\n");
                    return ptr;
                }
            }
        }

        throw std::bad_alloc{};
    }
};


int main() {
    Heap heap;
    auto ptr = heap.allocate(50000);

    printf("%p/n", ptr);


    return 0;
}
