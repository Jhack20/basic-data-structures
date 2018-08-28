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
        typedef struct Node {
            AnyObject value;
            Node * next_pointer;
            Node * previous_pointer;
        }* NodePtr;
        
        NodePtr head = nullptr;
        
    public:
        CircularLinkedList() = default;
        ~CircularLinkedList() = default;
        
        NodePtr getHead () { return head; }
        
        void push_front (AnyObject value) {
            if (head == nullptr){
                NodePtr newNode = new Node{value, nullptr, nullptr};
                newNode->next_pointer = newNode;
                newNode->previous_pointer = newNode;
                head = newNode;
            } else {
                NodePtr newNode = new Node{value, head, head->previous_pointer};
                head->previous_pointer->next_pointer = newNode;
                head->previous_pointer = newNode;
                head = newNode;
            }
        }
        
        void push_back (AnyObject value) {
            /* Complete this function */
        }
        
        void pop_front() {
            /* Complete this function */
        }
        
        void pop_back() {
            /* Complete this function */
        }
        
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");
            if (head != nullptr){
                NodePtr p = head;
                do{
                    std::cout << p->value << " ";
                    p = p->next_pointer;
                } while (p != head);
            }
            std::cout << std::endl;
        }
    };
}

template <class AnyObject>
using CircularLinkedList = cs2100::CircularLinkedList<AnyObject>;

#endif /* circularLinkedList_h */
