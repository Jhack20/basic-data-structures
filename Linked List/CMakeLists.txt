cmake_minimum_required(VERSION 3.10)
project(Linked_List)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Linked_List
        linkedList.hpp
        main.cpp
        unit_tests.hpp)
