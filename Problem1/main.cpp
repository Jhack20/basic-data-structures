//
//  main.cpp
//  Problem1
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include <iostream>
#include <stack.hpp>

/*

 Description: Use the proper data structure to accomplish the following problem
 
 Input: A string consisting of '(', '[', ')' and ']' characters
 
 Output: Return whether or not (bool) the string's parentheses and square brackets are balanced
 
 Example:
 
    "([])[]()"  true
    "([]]()"    false
    "]["        false
 
 */

int in[94];
char op[94];

/**
 *
 * @param char s
 * @return bool
 */
bool balanced(char s[]) {
    // Create a stack
    Stack<char> p;

    // Iterate
    for (int i = 0; s[i]; i++) {
        if (in[s[i]]) {
            p.push(s[i]);
        } else if (p.isEmpty() || p.top()->value != op[s[i]]) {
            return false;
        } else {
            p.pop();
        }
    }

    return p.isEmpty();
}

int main(int argc, const char *argv[]) {
    in['('] = in['['] = 1;
    in[')'] = in[']'] = 0;
    op[']'] = '[';
    op[')'] = '(';

    // test case
    char s[256] = "([])[]()";

    std::string result = balanced(s) ? "Balanced brackets!!" : "NO balanced brackets!!";
    std::cout << result << std::endl;

    return 0;
}
