//
//  main.cpp
//  Circular Linked List
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include "circularLinkedList.hpp"
#include "unit_tests.hpp"

int main(int argc, const char * argv[]) {
    CircularLinkedList<std::string> list;
    
    list.push_front("c");
    list.push_front("b");
    list.push_front("a");
    list.push_back("x");
    list.push_back("y");
    list.push_back("z");

    list.describe();

    list.pop_front();

    list.describe();

    /* Uncomment the lines below when you finish your implementation task */
    Testable::run(unit_tests, TestLevel::easy);
    Testable::run(unit_tests, TestLevel::tricky);
    Testable::run(unit_tests, TestLevel::hard);
    
    return 0;
}
