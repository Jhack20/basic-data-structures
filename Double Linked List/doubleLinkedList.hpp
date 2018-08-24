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
            /* Complete this function */
            Node *temp = new Node;

            temp->value = value;

            temp->next_pointer = head;
            temp->previous_pointer = nullptr;

            if (tail == nullptr) {
                tail = temp;
            }

            if (head != nullptr){
                head->previous_pointer = temp;
            }

            head = temp;
        }
        
        void push_back (AnyObject value) {
            /* Complete this function */
            Node *temp = new Node;

            temp->value = value;

            temp->next_pointer = nullptr;
            temp->previous_pointer = tail;

            if (head == nullptr) {
                head = temp;
            }

            if (tail != nullptr) {
                tail->next_pointer = temp;
            }

            tail = temp;

        }
        
        void pop_front() {
            /* Complete this function */
            if (head != nullptr) {
                Node *temp = new Node;
                temp = head;
                head = head->next_pointer;
                delete temp;
            }
        }
        
        void pop_back() {
            /* Complete this function */
            if (tail != nullptr) {
                Node *temp = new Node;
                temp = tail;
                tail = tail->previous_pointer;
                delete temp;
            }
        }
        
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");
            for ( Node *current = head ; current != tail->next_pointer ; current = current->next_pointer ) {
                std::cout << current->value << " ";
            }
            std::cout << "\n";
        }
    };
}

template <class AnyObject>
using DoubleLinkedList = cs2100::DoubleLinkedList<AnyObject>;

#endif /* doubleLinkedList_h */
