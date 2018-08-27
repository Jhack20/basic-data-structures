cmake_minimum_required(VERSION 3.10)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Stack
        main.cpp
        stack.hpp
        unit_tests.hpp)
