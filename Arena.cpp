#include <iostream>
#include <cstddef>

struct Arena {
    char* buffer;
    size_t capacity;
    size_t offset;

    // Init
    Arena(size_t size) {
        buffer = new char[size];
        capacity = size;
        offset = 0;
    }

    // Allocation
    void* allocate(size_t size) {
        if (offset + size > capacity) {
            return nullptr;
        }

        void* ptr = (buffer + offset);
        offset += size;

        return ptr;
    }

    // Deallocation
    void reset() {
        offset = 0;
    }

    // Destroyer
    ~Arena() {
        delete[] buffer;
    }
};

struct Enemy {
    int hp;
    int x, y;
    Enemy() : hp(100), x(0), y(0) {}
};

int main() {
    Arena game_arena(1024);
    void* mem = game_arena.allocate(sizeof(Enemy));

    if (mem) {
        Enemy* monster = new (mem) Enemy();
        monster->hp = 100;
        std::cout << "Monster spawned at: " << mem << " with HP: " << monster->hp << std::endl;
    }

    game_arena.reset();

    return 0;
}