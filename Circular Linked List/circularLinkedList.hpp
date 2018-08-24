//
//  circularLinkedList.h
//  Circular Linked List
//
//  Created by Bryan Gonzales Vega on 8/23/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef circularLinkedList_h
#define circularLinkedList_h

#include <iostream>
#include "../List/list.h"

namespace cs2100 {
    template <class AnyObject>
    class CircularLinkedList final : List<AnyObject> {
    private:
        struct Node {
            AnyObject value;
            Node * next_pointer = nullptr;
            Node * previous_pointer = nullptr;
        };
        
        Node * head = nullptr;
        
    public:
        CircularLinkedList() = default;
        ~CircularLinkedList() = default;
        
        Node * getHead () { return head; }
        
        void push_front (AnyObject value) {
            Node * new_node = new Node{value, head, nullptr};
            if (head != nullptr) {
                new_node->previous_pointer = head->previous_pointer;
                head->previous_pointer->next_pointer = new_node;
                head->previous_pointer = new_node;
            } else {
                new_node->previous_pointer = new_node;
                new_node->next_pointer = new_node;
            }
            head = new_node;
        }
        
        void push_back (AnyObject value) {
            Node * new_node = new Node{value, head, nullptr};
            if (head != nullptr) {
                new_node->previous_pointer = head->previous_pointer;
                head->previous_pointer->next_pointer = new_node;
                head->previous_pointer = new_node;
            } else {
                new_node->previous_pointer = new_node;
                new_node->next_pointer = new_node;
                head = new_node;
            }
        }
        
        void pop_front() {
            if (head != nullptr) {
                if (head->next_pointer != head) {
                    head->next_pointer->previous_pointer = head->previous_pointer;
                    head->previous_pointer->next_pointer = head->next_pointer; 
                    Node * new_head = head->next_pointer;
                    delete head;
                    head = new_head;    
                } else {
                    delete head;
                    head = nullptr;
                }
            }
        }
        
        void pop_back() {
            if (head != nullptr) {
                if (head->next_pointer != head) {
                    Node * new_tail = head->previous_pointer->previous_pointer;
                    delete head->previous_pointer;
                    head->previous_pointer = new_tail; 
                    new_tail->next_pointer = head;    
                } else {
                    delete head;
                    head = nullptr;
                }
            }
        }
        
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty) ": " ");
            Node * current = head;
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->next_pointer;    
                if (current == head) break;
            }
        }
    };
}

template <class AnyObject>
using CircularLinkedList = cs2100::CircularLinkedList<AnyObject>;

#endif /* circularLinkedList_h */
