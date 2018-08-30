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
            if (head == nullptr){
                NodePtr newNode = new Node{value, nullptr, nullptr};
                newNode->next_pointer = newNode;
                newNode->previous_pointer = newNode;
                head = newNode;
            } else{
                NodePtr newNode = new Node{value, head, head->previous_pointer};
                head->previous_pointer->next_pointer = newNode;
                head->previous_pointer = newNode;
                head->previous_pointer = newNode;
            }
        }
        
        void pop_front() {
            if (head) {
                if (head == head->next_pointer){
                    delete head;
                    head = nullptr;
                } else {
                    NodePtr lastNode = head->previous_pointer;
                    NodePtr secondNode = head->next_pointer;
                    delete head;
                    head = nullptr;
                    head = secondNode;
                    lastNode->next_pointer = head;
                    head->previous_pointer = lastNode;
                }
            }
        }
        
        void pop_back() {
            if (head) {
                if(head == head->next_pointer) {
                    delete head;
                    head = nullptr;
                    std::cout << "1" << std::endl;
                } else {
                    NodePtr lastNode = head->previous_pointer->previous_pointer;
                    delete head->previous_pointer;
                    head->previous_pointer = nullptr;
                    head->previous_pointer = lastNode;
                    lastNode->next_pointer = head;
                }
            }
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
