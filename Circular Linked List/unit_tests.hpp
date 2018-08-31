//
//  unit_tests.hpp
//  Circular Linked List
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#pragma once

#include "../Test/testable.hpp"
#include "circularLinkedList.hpp"

TestCases unit_tests = {
    {
        TestLevel::easy, [] {
            CircularLinkedList<std::string> list;
            list.push_back("a");
            ASSERT(list.getHead()->value == "a");
            list.push_front("b");
            ASSERT(list.getHead()->value == "b");
        }
    },{
        TestLevel::tricky, [] {
            CircularLinkedList<std::string> list;
            list.push_back("a"); list.push_back("b"); list.push_back("c");
            list.push_front("x");
            ASSERT(list.getHead()->value == "x");
            ASSERT(list.getHead()->previous_pointer->value == "c");
        }
    },{
        TestLevel::hard, [] {
            CircularLinkedList<std::string> list;
            list.push_back("a"); list.push_back("b"); list.push_back("c");
            list.pop_back(); list.pop_back(); list.pop_back(); list.pop_back();
            ASSERT(list.getHead() == nullptr);
            list.push_front("z"); list.push_front("y"); list.push_front("x");
            list.pop_front(); list.pop_front(); list.pop_front(); list.pop_front();
            ASSERT(list.getHead() == nullptr);
        }
    }
};
