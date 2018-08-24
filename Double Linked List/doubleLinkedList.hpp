//
//  doubleLinkedList.h
//  Double Linked List
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef doubleLinkedList_h
#define doubleLinkedList_h

#include <iostream>
#include "../List/list.h"

namespace cs2100 {
    template <class AnyObject>
    class DoubleLinkedList final : List<AnyObject> {
    private:
        struct Node {
            AnyObject value;
            Node * next_pointer;
            Node * previous_pointer;
        };
        
        Node * head = nullptr;
        Node * tail = nullptr;
        
    public:
        DoubleLinkedList() = default;
        ~DoubleLinkedList() = default;
        
        Node * getHead () { return head; }
        Node * getTail () { return tail; }
        
        void push_front (AnyObject value) {
            Node * new_node = new Node{value, head, nullptr};
            if (head != nullptr) {
                head->previous_pointer = new_node;
            } else {
                tail = new_node;
            }
            head = new_node;
        }
        
        void push_back (AnyObject value) {
            Node * new_node = new Node{value, nullptr, tail};
            if (tail != nullptr) {
                tail->next_pointer = new_node;
            } else {
                head = new_node;
            }
            tail = new_node;
        }
        
        void pop_front() {
            if (head != nullptr) {
                if (head->next_pointer != nullptr) {
                    head->next_pointer->previous_pointer = nullptr; 
                } else {
                    tail = nullptr;
                }
                Node * new_head = head->next_pointer;
                delete head;
                head = new_head;
            }
        }
        
        void pop_back() {
            if (tail != nullptr) {
                if (tail->previous_pointer != nullptr) {
                    tail->previous_pointer->next_pointer = nullptr; 
                } else {
                    head = nullptr;
                }
                Node * new_tail = tail->previous_pointer;
                delete tail;
                tail = new_tail;
            }
        }
        
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty) ": " ");
            Node * current = head;
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->next_pointer;
            }
        }
    };
}

template <class AnyObject>
using DoubleLinkedList = cs2100::DoubleLinkedList<AnyObject>;

#endif /* doubleLinkedList_h */
