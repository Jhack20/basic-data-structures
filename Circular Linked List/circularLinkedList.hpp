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
    template<class AnyObject>
    class CircularLinkedList final : List<AnyObject> {
    private:
        struct Node {
            AnyObject value;
            Node *next_pointer;
            Node *previous_pointer;
        };

        Node *head = nullptr;

    public:
        CircularLinkedList() = default;

        ~CircularLinkedList() = default;

        Node *getHead() { return head; }

        void push_front(AnyObject value) {
            Node *newNode = new Node{value, head, nullptr};

            // There are not elements in the list
            // As it will be the first element, head pointer should point to this element
            if (!head) {
                newNode->next_pointer = newNode;
                newNode->previous_pointer = newNode;
                head = newNode;
                return;
            }

            // There are elements in the list
            newNode->previous_pointer = head->previous_pointer;
            head->previous_pointer->next_pointer = newNode;
            head->previous_pointer = newNode;
            head = newNode;
        }

        void push_back(AnyObject value) {
            Node *newNode = new Node{value, head, nullptr};

            // There are not elements in the list
            // As it will be the first element, head pointer should point to this element
            if (!head) {
                newNode->next_pointer = newNode;
                newNode->previous_pointer = newNode;
                head = newNode;
                return;
            }

            // There are elements in the list
            newNode->previous_pointer = head->previous_pointer;
            head->previous_pointer->next_pointer = newNode;
            head->previous_pointer = newNode;
        }

        void pop_front() {
            // There are not elements in the list
            if (!head) {
                return;
            }

            // Prepare to delete this pointer
            Node *temp = head;

            if (head == head->previous_pointer) {
                head = nullptr;
                return;
            }

            // Swap head
            head->previous_pointer = head->next_pointer;
            head->next_pointer->previous_pointer = head->previous_pointer;
            head = temp->next_pointer;
        }

        void pop_back() {
            // There are not elements in the list
            if (!head) {
                return;
            }

            // Prepare to delete this pointer
            Node *temp = head->previous_pointer;

            if (head == temp) {
                head = nullptr;
                return;
            }

            // Swap last element
            head->previous_pointer->previous_pointer->next_pointer = head;
            head->previous_pointer = head->previous_pointer->previous_pointer;
        }

        void describe() {
            std::cout << "List:" << ((!head) ? " (empty)" : " ");

            Node *current = head;

            do {
                std::cout << current->value << " ";
                current = current->next_pointer;
            } while (current != head);

            std::cout << std::endl;
        }
    };
}

template<class AnyObject>
using CircularLinkedList = cs2100::CircularLinkedList<AnyObject>;

#endif /* circularLinkedList_h */
