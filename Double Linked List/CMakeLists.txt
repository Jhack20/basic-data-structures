cmake_minimum_required(VERSION 3.10)
project(Double_Linked_List)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Double_Linked_List
        doubleLinkedList.hpp
        main.cpp
        unit_tests.hpp)
