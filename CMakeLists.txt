cmake_minimum_required(VERSION 4.0)
project(C-pp-Study)

set(CMAKE_CXX_STANDARD 17)

find_package(Catch2 REQUIRED)

add_executable(C-pp-Study
        DeadMenOfDunharrow.cpp
        SayHello.cpp
        Arena.cpp)

target_link_libraries(C-pp-Study PRIVATE Catch2::Catch2WithMain)
