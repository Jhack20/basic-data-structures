//
//  main.cpp
//  Linked List
//
//  Created by Bryan Gonzales Vega on 8/22/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include "list_iterator.hpp"
#include "unit_tests.hpp"

int main(int argc, const char * argv[]) {
    
    LinkedList<std::string> list;
    
    list.push_front("c");   list.push_front("b");   list.push_front("a");
    list.push_back("x");    list.push_back("y");    list.push_back("z");

    //    Testable::run(unit_tests, TestLevel::easy);
    //    Testable::run(unit_tests, TestLevel::tricky);
    //    Testable::run(unit_tests, TestLevel::hard);
  
    
    
    /* Implement the proper functions to iterate through elements STL style */
    
//    LinkedList<std::string>::ForwardIterator it;
//    for (it = list.begin() ; it != list.end() ; it++ ) {
//        std::cout << (*it) << " ";
//    }

//    LinkedList<std::string>::ReverseIterator rit;
//    for (rit = list.rbegin() ; rit != list.rend() ; rit++ ) {
//        std::cout << (*rit) << " ";
//    }
    
    return 0;
}
