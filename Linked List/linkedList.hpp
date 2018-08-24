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
            /* Complete this function */
            Node *temp = new Node;

            temp->value = value;
            temp->pointer = head;

            head = temp;
        }
        
        void push_back (AnyObject value) {
            /* Complete this function */
            Node *temp=new Node;
            temp->value=value;
            temp->pointer=nullptr;
            if (!head) {
                head = temp;
            }
            else {
                Node *current=head;
                for ( ; current->pointer != nullptr ; current=current->pointer);
                current->pointer=temp;
            }
        }
        
        void pop_front() {
            /* Complete this function */
            if (head != nullptr) {
                Node *temp = new Node;
                temp = head;
                head = head->pointer;
                delete temp;
            }

        }
        
        void pop_back() {
            /* Complete this function */
            Node *current=new Node;
            Node *previous=new Node;
            current=head;
            while(current->pointer != nullptr)
            {
                previous=current;
                current=current->pointer;
            }
            tail=previous;
            previous->pointer=nullptr;
            delete current;
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
