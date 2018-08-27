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
            Node * next_pointer;
            Node * previous_pointer;
        };
        
        Node * head = nullptr;
        
    public:
        CircularLinkedList() = default;
        ~CircularLinkedList() = default;
        
        Node * getHead () { return head; }
        
        void push_front (AnyObject value) {
            /* Complete this function */
            // Pointer points to last Node
            struct Node *last = (head)->previous_pointer;

            struct Node *temp = new Node;
            temp->value = value;   // Inserting the data

            // setting up previous and next of new node
            temp->next_pointer = head;
            temp->previous_pointer = last;

            // Update next and previous pointers of start
            // and last.
            last->next_pointer = (head)->previous_pointer = temp;

            // Update start pointer
            head = temp;
        }
        
        void push_back (AnyObject value) {
            /* Complete this function */
            // If the list is empty, create a single node
            // circular and doubly list
            if (head == nullptr)
            {
                struct Node *temp = new Node;
                temp->value = value;
                temp->next_pointer = temp->previous_pointer = temp;
                head = temp;
                return;
            }
            else {
                // If list is not empty

                /* Find last node */
                Node *last = (head)->previous_pointer;

                // Create Node dynamically
                struct Node *temp = new Node;
                temp->value = value;

                // Start is going to be next of new_node
                temp->next_pointer = head;

                // Make new node previous of start
                (head)->previous_pointer = temp;

                // Make last preivous of new node
                temp->previous_pointer = last;

                // Make new node next of old last
                last->next_pointer = temp;
            }


        }
        
        void pop_front() {
            /* Complete this function */
        }
        
        void pop_back() {
            /* Complete this function */
        }
        
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");
            for ( Node * current = head ; current->next_pointer != head ; current = current->next_pointer ) {
                std::cout << current->value << " ";
            }
            std::cout << "\n";
        }
    };
}

template <class AnyObject>
using CircularLinkedList = cs2100::CircularLinkedList<AnyObject>;

#endif /* circularLinkedList_h */
