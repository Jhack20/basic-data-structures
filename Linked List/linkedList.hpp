//
//  linkedList.hpp
//  Linked List
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef linkedList_h
#define linkedList_h

#include <iostream>
#include "../List/list.h"

namespace cs2100 {
    template <class AnyObject>
    class LinkedList final : List<AnyObject> {
    private:
        typedef struct Node {
            AnyObject value;
            Node * pointer;
        }* NodePtr;

        NodePtr head = nullptr;
        NodePtr tail = nullptr;

    public:
        LinkedList() = default;
        ~LinkedList() = default;

        NodePtr getHead () { return head; }
        NodePtr getTail () { return tail; }

        void push_front (AnyObject value) {
            if (!head) {
                NodePtr newNode = new Node{value, nullptr};
                head = newNode;
                tail = newNode;
            } else {
                NodePtr newNode = new Node{value, head};
                head = newNode;
            }
        }

        void push_back (AnyObject value) {
            if (!head) {
                NodePtr  newNode = new Node{value, nullptr};
                head = newNode;
                tail = newNode;
            } else {
                NodePtr newNode = new Node{value, nullptr};
                tail->pointer = newNode;
                tail = newNode;
            }
        }

        void pop_front() {
            if (head) {
                if (head->pointer == nullptr) {
                    delete head, tail;
                    head = tail =  nullptr;
                } else {
                    NodePtr secondPtr = head->pointer;
                    delete head;
                    head = nullptr;
                    head = secondPtr;
                }
            }
        }

        void pop_back() {
            if(head) {
                if (head->pointer == nullptr){
                    delete head, tail;
                    head = tail = nullptr;
                } else {
                    NodePtr current = head;
                    while (current->pointer != tail) {
                        current = current->pointer;
                    }
                    delete tail;
                    tail = nullptr;
                    current->pointer = nullptr;
                    tail = current;
                }
            }
        }

        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");
            for ( Node * current = head ; current != nullptr ; current = current->pointer ) {
                std::cout << current->value << " ";
            }
            std::cout << "\n";
        }
    };
}

template <class AnyObject>
using LinkedList = cs2100::LinkedList<AnyObject>;

#endif /* linkedList_h */
