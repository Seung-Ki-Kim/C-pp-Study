#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>
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

// TEST_CASE("ScopedPtr can") {
//     ScopedOathbreakers aragorn { new DeadMenOfDunharrow };
//
//     SECTION("be passed by reference") {
//         by_ref(aragorn);
//     }
//
//     SECTION("can be moved") {   // unique_ptr
//         by_val(std::move(aragorn));
//         auto son_of_arathorn = std::move(aragorn);
//     }
// }

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