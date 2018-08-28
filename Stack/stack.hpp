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
    template<class AnyObject>
    class Stack {
    private:
        struct Node {
            AnyObject value;
            Node *pointer;
        };

        Node *root = nullptr;

    public:
        Stack() = default;

        ~Stack() {
            for (Node *current = root; current != nullptr; current = current->pointer) {
                this->pop();
            }
        };

        Node *top() { return root; }

        bool isEmpty() { return !root; }

        void push(AnyObject value) {
            Node *newNode = new Node{value, nullptr};

            // first element
            if (isEmpty()) {
                root = newNode;
                return;
            }

            // other case
            newNode->pointer = root;
            root = newNode;
        }

        void pop() {
            // There are not elements
            if (isEmpty()) {
                return;
            }

            Node *toDeleteElement = root;
            root = root->pointer;

            delete toDeleteElement;
        }

        void describe() {
            std::cout << "\nStack:" << ((!root) ? " (empty)" : " ");
            for (Node *current = root; current != nullptr; current = current->pointer) {
                std::cout << "\n" << current->value;
            }
            std::cout << "\n";
        }
    };
}

template<class AnyObject>
using Stack = cs2100::Stack<AnyObject>;

#endif /* stack_h */
