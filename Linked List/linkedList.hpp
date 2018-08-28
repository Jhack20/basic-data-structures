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
    template<class AnyObject>
    class LinkedList final : List<AnyObject> {
    private:
        struct Node {
            AnyObject value;
            Node *pointer;
        };

        Node *head = nullptr;
        Node *tail = nullptr;

    public:
        LinkedList() = default;

        ~LinkedList() = default;

        inline Node *getHead() { return head; }

        inline Node *getTail() { return tail; }

        void push_front(AnyObject value) {
            Node *newNode = new Node{value, nullptr};

            // There are not elements in the list
            // As it will be the first element, head and tail pointers should point to this element
            if (!head) {
                head = newNode;
                tail = newNode;
                return;
            }

            // There are elements in the list
            newNode->pointer = head;
            head = newNode;
        }

        void push_back(AnyObject value) {
            Node *newNode = new Node{value, nullptr};

            // There are not elements in the list
            // As it will be the first element, head and tail pointers should point to this element
            if (!head) {
                head = newNode;
                tail = newNode;
                return;
            }

            if (!tail) {
                tail = newNode;
                return;
            }

            // Swap tail
            tail->pointer = newNode;
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
            Node *temp = head->pointer;
            head = temp;

            // deallocate memory
            delete temp;
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

            Node *temp;
            Node *preTail;
            temp = head;

            // Iterate the list to find the penultimate element
            // TODO: Implement iterator (?)
            while (temp->pointer) {
                temp = temp->pointer;
                preTail = temp;
            }

            preTail->pointer = nullptr;
            tail = preTail;

            // deallocate memory
            delete temp;
        }

        void describe() {
            std::cout << "List:" << ((!head) ? " (empty)" : " ");
            for (Node *current = head; current != nullptr; current = current->pointer) {
                std::cout << current->value << " ";
            }
            std::cout << "\n";
        }
    };
}

template<class AnyObject>
using LinkedList = cs2100::LinkedList<AnyObject>;

#endif /* linkedList_h */
