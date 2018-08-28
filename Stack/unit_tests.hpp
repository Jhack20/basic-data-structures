//
//  unit_tests.hpp
//  Stack
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#pragma once

#include "../Test/testable.hpp"

TestCases unit_tests = {
    {
        TestLevel::easy, [] {
            Stack<int> stack;
            ASSERT(stack.top() == nullptr);
            stack.push(1);
            stack.pop();
            ASSERT(stack.top() == nullptr);
        }
    },{
        TestLevel::tricky, [] {
            Stack<int> stack;
            ASSERT(stack.top() == nullptr);
            stack.push(1); stack.push(2); stack.push(3);
            ASSERT(stack.top()->value == 3);
            stack.pop(); stack.pop();
            ASSERT(stack.top()->value == 1);
        }
    },{
        TestLevel::hard, [] {
            Stack<int> stack;
            ASSERT(stack.top() == nullptr);
            stack.push(1); stack.push(2); stack.push(3);
            ASSERT(stack.top()->value == 3);
            stack.pop(); stack.pop();
            ASSERT(stack.top()->value == 1);
            stack.pop();
            ASSERT(stack.top() == nullptr);
        }
    }
};
