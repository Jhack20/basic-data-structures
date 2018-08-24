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
        struct Node {
            AnyObject value;
            Node * pointer;
        };
        
        Node * head = nullptr;
        Node * tail = nullptr;
        
    public:
        LinkedList() = default;
        ~LinkedList() = default;
        
        Node * getHead () { return head; }
        Node * getTail () { return tail; }
        
        void push_front (AnyObject value) {
            Node * new_node = new Node{value, head};
            if (head == nullptr) {
                tail = new_node;
            }
            head = new_node;
        }
        
        void push_back (AnyObject value) {
            Node * new_node = new Node{value, nullptr};
            if (tail != nullptr) {
                tail->pointer = new_node;
            } else {
                head = new_node;
            }
            tail = new_node;
        }
        
        void pop_front() {
            if (head != nullptr) {
                if (head->pointer == nullptr) {
                    tail = nullptr;
                }
                Node * new_head = head->pointer;
                delete head;
                head = new_head;
            }
        }
        
        void pop_back() {
            if (tail != nullptr) {
                Node * current = head;
                while (current != nullptr) {
                    if (current->pointer == tail) break;
                    current = current->pointer;
                }
                
                if (head->pointer == nullptr) {
                    head = nullptr;
                }
                Node * new_tail = current;
                new_tail->pointer = nullptr;
                delete tail;
                tail = new_tail;
            }
        }
        
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");
            Node * current = head;
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->pointer;
            }
        }
    };
}

template <class AnyObject>
using LinkedList = cs2100::LinkedList<AnyObject>;

#endif /* linkedList_h */
