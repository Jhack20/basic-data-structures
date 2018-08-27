cmake_minimum_required(VERSION 3.10)
project(Circular_Linked_List)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Circular_Linked_List
        circularLinkedList.hpp
        main.cpp
        unit_tests.hpp)
