//
//  main.cpp
//  Linked List
//
//  Created by Bryan Gonzales Vega on 8/22/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include "linkedList.hpp"
#include "unit_tests.hpp"

int main(int argc, const char * argv[]) {
    
    LinkedList<std::string> list;
    
    list.push_front("c");
    list.push_front("b");
    list.push_front("a");
    list.describe();
    
    list.push_back("x");
    list.push_back("y");
    list.push_back("z");
    list.describe();
    
    /* Test */
    Testable::run(unit_tests, TestLevel::easy);
    Testable::run(unit_tests, TestLevel::tricky);
    Testable::run(unit_tests, TestLevel::hard);

    return 0;
}
