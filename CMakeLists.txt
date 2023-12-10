cmake_minimum_required(VERSION 3.26)
project(C_pp_Study)

set(CMAKE_CXX_STANDARD 11)

add_executable(C_pp_Study main.cpp
        Dog.cpp
        Dog.h
        Cat.cpp
        Cat.h
        Animal.h
)
