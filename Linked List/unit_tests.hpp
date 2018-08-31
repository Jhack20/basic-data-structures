//
//  unit_tests.hpp
//  Linked List
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef unit_tests_h
#define unit_tests_h

#include "../Test/testable.hpp"
#include "linkedList.hpp"

TestCases unit_tests = {
    {
        TestLevel::easy, [] {
            LinkedList<std::string> list;
            list.push_front("a");
            list.push_front("b");
            list.push_front("c");
            ASSERT(list.getHead()->value == "c");
            ASSERT(list.getTail()->value == "a");
            
            list.push_back("z");
            ASSERT(list.getHead()->value == "c");
            ASSERT(list.getTail()->value == "z");
        }
    },{
        TestLevel::tricky, [] {
            LinkedList<std::string> list;
            list.push_front("c"); list.push_front("b"); list.push_front("a");
            list.push_back("x"); list.push_back("y"); list.push_back("z");
            ASSERT(list.getHead()->value == "a");
            ASSERT(list.getTail()->value == "z");
            
            list.pop_front(); list.pop_front(); list.pop_front();
            ASSERT(list.getHead()->value == "x");
            ASSERT(list.getTail()->value == "z");
        }
    },{
        TestLevel::hard, [] {
            LinkedList<std::string> list;
            
            list.pop_front(); list.pop_front(); list.pop_back(); list.pop_back();
            ASSERT(list.getHead() == nullptr);
            ASSERT(list.getTail() == nullptr);
            
            list.push_front("b");
            ASSERT(list.getHead()->value == "b");
            ASSERT(list.getTail()->value == "b");
            
            list.pop_front(); list.pop_back();
            ASSERT(list.getHead() == nullptr);
            ASSERT(list.getTail() == nullptr);
        }
    }
};


#endif /* unit_tests_h */
