//
//  main.cpp
//  Problem1
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include <iostream>
#include <map>
#include "../Stack/stack.hpp"

/*

 Description: Use the proper data structure to accomplish the following problem
 
 Input: A string consisting of '(', '[', ')' and ']' characters
 
 Output: Return whether or not (bool) the string's parentheses and square brackets are balanced
 
 Example:
 
    "([])[]()"  true
    "([]]()"    false
    "]["        false
 
 */

bool is_balanced(std::string str) {
    std::map<const char, char> duo;
    duo['('] = ')';
    duo['['] = ']';

    Stack<char> stack;
    for (char& c : str) {
        if (duo.count(c) != 0) {
            stack.push(c);
        } else {
            if (!stack.isEmpty() && duo[stack.top()->value] == c) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.isEmpty();
}


int main(int argc, const char * argv[]) {
    std::string input;
    std::cin >> input;
    std::cout << is_balanced(input) << std::endl;
    
    return 0;
}
