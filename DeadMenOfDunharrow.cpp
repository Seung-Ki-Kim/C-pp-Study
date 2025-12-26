#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/smart_ptr/scoped_array.hpp>
#include <memory>


struct DeadMenOfDunharrow {
    DeadMenOfDunharrow(const char* m="") : message{ m } {
        oaths_to_fulfill++;
    }

    ~DeadMenOfDunharrow() {
        oaths_to_fulfill--;
    }

    const char* message;
    static int oaths_to_fulfill;
};

int DeadMenOfDunharrow::oaths_to_fulfill{};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

TEST_CASE("ScopedPtr evaluates to") {
    SECTION("True when full") {
        ScopedOathbreakers aragorn { new DeadMenOfDunharrow {} };
        REQUIRE(aragorn);
    }
    SECTION("False when empty") {
        ScopedOathbreakers aragorn;
        REQUIRE_FALSE(aragorn);
    }
}


TEST_CASE("UniquePtr evaluates to") {
    SECTION("True when full") {
        ScopedOathbreakers aragorn { new DeadMenOfDunharrow {} };
        REQUIRE(aragorn);
    }

    SECTION("False when empty") {
        ScopedOathbreakers aragorn;
        REQUIRE_FALSE(aragorn);
    }
}

TEST_CASE("ScopedPtr is an RAII Wrapper.") {
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);

    ScopedOathbreakers aragorn { new DeadMenOfDunharrow {} };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    std::cout << "1" << std::endl;

    {
        ScopedOathbreakers legolas { new DeadMenOfDunharrow {} };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        std::cout << "2" << std::endl;
    }

    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    std::cout << "1" << std::endl;
}

TEST_CASE("ScopedPtr supports pointer semantics, like") {
    auto message = "The way is shut";
    ScopedOathbreakers aragorn { new DeadMenOfDunharrow { message } };

    SECTION("operator*") {
        REQUIRE((*aragorn).message == message);
    }

    SECTION("operator->") {
        REQUIRE(aragorn->message == message);
    }

    SECTION("get(), which returns a raw pointer") {
        REQUIRE(aragorn.get() != nullptr);
    }
}

TEST_CASE("ScopedPtr supports comparison with nullptr") {
    SECTION("operator==") {
        ScopedOathbreakers legolas{};
        REQUIRE(legolas == nullptr);
    }

    SECTION("operator!=") {
        ScopedOathbreakers aragorn { new DeadMenOfDunharrow{} };
        REQUIRE(aragorn != nullptr);
    }
}

TEST_CASE("ScopedPtr supports swap") {
    auto message1 = "The way is shut.";
    auto message2 = "Until the time comes.";

    ScopedOathbreakers aragorn {
        new DeadMenOfDunharrow { message1 }
    };

    ScopedOathbreakers legolas {
        new DeadMenOfDunharrow { message2 }
    };

    aragorn.swap(legolas);
    REQUIRE(legolas->message == message1);
    REQUIRE(aragorn->message == message2);
}

TEST_CASE("ScopedPtr reset") {
    ScopedOathbreakers aragorn{ new DeadMenOfDunharrow {} };

    SECTION("destructs owned object.") {
        aragorn.reset();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
    }

    SECTION("can replace an owned object.") {
        auto message = "It was made by those who are Dead.";
        auto new_dead_man = new DeadMenOfDunharrow { message };

        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        aragorn.reset(new_dead_man);

        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
        REQUIRE(aragorn->message == new_dead_man->message);
        REQUIRE(aragorn.get() == new_dead_man);
    }
}

void by_ref(const ScopedOathbreakers&) { }
void by_val(ScopedOathbreakers) { }

TEST_CASE("ScopedPtr can") {
    ScopedOathbreakers aragorn { new DeadMenOfDunharrow };

    SECTION("be passed by reference") {
        by_ref(aragorn);
    }

    // SECTION("not be copied") {
    //     by_val(aragorn);
    //     auto son_of_arathorn = aragorn;
    // }

    // SECTION("not be moved") {
    //     by_val(std::move(aragorn));
    //     auto son_of_arathorn = std::move(aragorn);
    // }
}

TEST_CASE("ScopedArray supports operator[]") {
    boost::scoped_array<int> squares { new int[5] { 0, 4, 9, 16, 25 } };

    squares[0] = 1;
    
    REQUIRE(squares[0] == 1);
    REQUIRE(squares[1] == 4);
    REQUIRE(squares[2] == 9);
}

using SharedOathbreakers = std::shared_ptr<DeadMenOfDunharrow>;

TEST_CASE("SharedPtr can be used in copy") {
    auto aragorn = std::make_shared<DeadMenOfDunharrow>();

    SECTION("construction") {
        auto son_of_arathorn { aragorn };   // Copy
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }

    SECTION("assignment") {
        SharedOathbreakers son_of_arathorn;
        son_of_arathorn = aragorn;
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }

    SECTION("assignment, and original gets discarded") {
        auto son_of_arathorn = std::make_shared<DeadMenOfDunharrow>();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        son_of_arathorn = aragorn;
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }

    SECTION("Shared Array") {
        std::shared_ptr<int[]> shr_arr(new int[5]{1, 2, 3, 4, 5});
    }
}

using UniqueOathbreakers = std::unique_ptr<DeadMenOfDunharrow>;

TEST_CASE("UniquePtr can be used in move") {
    auto aragorn = std::make_unique<DeadMenOfDunharrow>();

    SECTION("construction") {
        auto son_of_arathorn { std::move(aragorn) };   // Move
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }

    SECTION("assignment") {
        auto son_of_arathorn = std::make_unique<DeadMenOfDunharrow>();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        son_of_arathorn = std::move(aragorn);
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
}

TEST_CASE("UniquePtr to array supports operator[]") {
    std::unique_ptr<int[]> squares { new int[5] { 1, 4, 9, 16, 25 } };

    squares[0] = 1;

    REQUIRE(squares[0] == 1);
    REQUIRE(squares[1] == 4);
    REQUIRE(squares[2] == 9);
}

auto my_deleter = [](int* x) {
    printf("Deleting an int at %p.", x);
    delete x;
};

TEST_CASE("Custom deleter test") {
    std::unique_ptr<int, decltype(my_deleter)> my_up { new int, my_deleter };
    *my_up = 1;
}