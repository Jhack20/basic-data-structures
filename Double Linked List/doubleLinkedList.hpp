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
    template<class AnyObject>
    class DoubleLinkedList final : List<AnyObject> {
    private:
        struct Node {
            AnyObject value;
            Node *next_pointer;
            Node *previous_pointer;
        };

        Node *head = nullptr;
        Node *tail = nullptr;

    public:
        DoubleLinkedList() = default;

        ~DoubleLinkedList() = default;

        inline Node *getHead() { return head; }

        inline Node *getTail() { return tail; }

        void push_front(AnyObject value) {
            Node *newNode = new Node{value, head, nullptr};

            // There are not elements in the list
            // As it will be the first element, head and tail pointers should point to this element
            if (!head) {
                head = newNode;
                tail = newNode;
                return;
            }

            // There are elements in the list
            head->previous_pointer = newNode;
            head = newNode;
        }

        void push_back(AnyObject value) {
            Node *newNode = new Node{value, nullptr, tail};

            // There are not elements in the list
            // As it will be the first element, head and tail pointers should point to this element
            if (!head) {
                head = newNode;
                tail = newNode;
                return;
            }

            // There are elements in the list
            tail->next_pointer = newNode;
            tail = newNode;
        }

        void pop_front() {
            // There are not elements in the list
            if (!head) {
                return;
            }

            // There are only a single element in the list
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
                return;
            }

            // Swap head
            Node *temp = head->next_pointer;
            temp->previous_pointer = nullptr;
            head = temp;
        }

        void pop_back() {
            // There are not elements in the list
            if (!tail) {
                return;
            }

            // There are only a single element in the list
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
                return;
            }

            // Swap tail
            Node *temp = tail->previous_pointer;
            temp->next_pointer = nullptr;

            tail = temp;
        }

         void describe() {
            std::cout << "List:" << ((!head) ? " (empty)" : " ");

            // TODO: Implement iterator (?)
            for (Node *current = head; current != nullptr; current = current->next_pointer) {
                std::cout << current->value << " ";
            }

            std::cout << std::endl;
        }
    };
}

template<class AnyObject>
using DoubleLinkedList = cs2100::DoubleLinkedList<AnyObject>;

#endif /* doubleLinkedList_h */
