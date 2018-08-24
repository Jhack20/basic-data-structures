//
//  main.cpp
//  Problem1
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include <iostream>
#include "doubleLinkedList.h"
#include <string>
#include <vector>

/*

 Description: Use the proper data structure to accomplish the following problem
 
 Input: A string consisting of '(', '[', ')' and ']' characters
 
 Output: Return whether or not (bool) the string's parentheses and square brackets are balanced
 
 Example:
 
    "([])[]()"  true
    "([]]()"    false
    "]["        false
 
 */


int main(int argc, const char * argv[]) {
    DoubleLinkedList<char> list;

    std::cout << "Balanced brackets!!\n";

    std::string str;
    std::cin >> str;

    std::vector<char> chars;

    for (char c:str) {
        chars.push_back(c);
    }

    for (char c: chars) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    for (char c: chars) {
        list.push_back(c);
    }
    list.describe();


    
    return 0;
}
