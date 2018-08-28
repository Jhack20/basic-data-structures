//
//  main.cpp
//  Problem1
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#include <iostream>
#include <map>

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
    std::string x;
    std::map<char,int>contador;
    contador['(']=0;
    contador[')']=0;
    contador['[']=0;
    contador[']']=0;
    std::cout<<"ingrese string: ";
    std::cin>>x;
    for(auto &i:x){
        contador[i]+=1;
        switch(i){
            case ')':if(contador[')']>contador['(']){
std::cout<<"false";exit(0);
                }break;
            case ']':if(contador[']']>contador['[']){
                    std::cout<<"false";exit(0);
                }break;
        }
    }
    if(contador['(']==contador[')'] and contador['[']==contador[']'] ){
        std::cout<<"true";
    }
    else{
        std::cout<<"false";
    }
    return 0;
}
