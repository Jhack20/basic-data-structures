//
//  stack.h
//  Stack
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <iostream>

namespace cs2100 {
    template <class AnyObject>
    class Stack {
    private:
        struct Node {
            AnyObject value;
            Node * pointer;
        };
        
        Node * root = nullptr;
        
    public:
        Stack()  = default;
        
        ~Stack() {
            for ( Node *current = root ; current != nullptr ; current = current->pointer ){
                this->pop();
            }
        };
        
        Node * top ()   {
            for (Node *current = root; current != nullptr; current = current->pointer) {
                return current;
            }
        }
        bool isEmpty () { return !root; }
        
        void push(AnyObject value) {
            /* Complete this function */
            if (root == nullptr) {
                Node *temp = new Node;

                temp->value = value;
                temp->pointer = nullptr;

                Node *last = new Node;
                last = top();

                root = temp;
                last = temp;

            } else {
                Node *temp = new Node;
                temp->value = value;
                temp->pointer = root;
                root = temp;
            }
        }
        
        void pop() {
            /* Complete this function */
            Node *last = new Node;
            last = top();

            if(root == last) {
                delete root;
                root = nullptr;
                last = nullptr;
            }
            else {
                Node *temp = new Node;
                temp = root;
                root = root->pointer;
                delete temp;
            }
        }
        
        inline void describe () {
            std::cout << "\nStack:" << ((!root) ? " (empty)": " ");
            for( Node * current = root ; current != nullptr ; current = current->pointer ){
                std::cout << "\n" << current->value;
            }
            std::cout << "\n";
        }
    };
};

template <class AnyObject>
using Stack = cs2100::Stack<AnyObject>;

#endif /* stack_h */
