//
//  main.cpp
//  Stack
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include "stack.hpp"
#include "unit_tests.hpp"

int main(int argc, const char * argv[]) {

    Stack<std::string> books;
    books.push("Introduction to Algorithms");
    books.push("C++17 STL Cookbook");
    books.push("The Art of Computer Programming");

    books.describe();
    
    /* Uncomment the lines below when you finish your implementation task */
    Testable::run(unit_tests, TestLevel::easy);
    Testable::run(unit_tests, TestLevel::tricky);
    Testable::run(unit_tests, TestLevel::hard);

    return 0;
}
