
//
//  unit_tests.hpp
//  Double Linked List
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef unit_tests_h
#define unit_tests_h

#include "../Test/testable.hpp"

TestCases unit_tests = {
        {
                TestLevel::easy, [] {
            DoubleLinkedList<std::string> list;
            list.push_back("a");
            ASSERT(list.getHead()->value == "a");
            ASSERT(list.getTail()->value == "a");
            list.push_front("b");
            ASSERT(list.getHead()->value == "b");
            ASSERT(list.getTail()->value == "a");
        }
        },{
                TestLevel::tricky, [] {
                    DoubleLinkedList<std::string> list;
                    list.push_back("a"); list.push_back("b"); list.push_back("c");
                    ASSERT(list.getHead()->value == "a");
                    ASSERT(list.getTail()->previous_pointer->value == "b");
                    list.push_front("x");
                    ASSERT(list.getHead()->value == "x");
                    ASSERT(list.getHead()->next_pointer->value == "a");
                }
        },{
                TestLevel::hard, [] {
                    DoubleLinkedList<std::string> list;
                    list.push_back("a"); list.push_back("b"); list.push_back("c");
                    list.pop_back(); list.pop_back(); list.pop_back(); list.pop_back();
                    ASSERT(list.getHead() == nullptr);
                    ASSERT(list.getTail() == nullptr);
                    list.push_front("z"); list.push_front("y"); list.push_front("x");
                    list.pop_front(); list.pop_front();
                    ASSERT(list.getHead()->value == "z");
                    ASSERT(list.getTail()->value == "z");
                    list.pop_front(); list.pop_back(); list.pop_back();
                    ASSERT(list.getHead() == nullptr);
                    ASSERT(list.getTail() == nullptr);
                }
        }
};


#endif /* unit_tests_h */
