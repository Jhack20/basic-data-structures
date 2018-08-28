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
        typedef struct Node {
            AnyObject value;
            Node * next_pointer;
            Node * previous_pointer;
        }* NodePtr;

        NodePtr head = nullptr;
        NodePtr tail = nullptr;

    public:
        DoubleLinkedList() = default;
        ~DoubleLinkedList() = default;

        NodePtr getHead () { return head; }
        NodePtr getTail () { return tail; }

        void push_front (AnyObject value) {
            //  Si el puntero head es nulo
            if (head == nullptr) {
                //  Se crea el primer puntero de la lista donde los punteros laterales son nulos
                NodePtr first = new Node{value, nullptr, nullptr};
                //  El puntero sera el primer y último puntero
                head = first;
                tail = first;
            }
                // Si el puntero head ya tiene una dirección inicial
            else {
                //  Se crea un nuevo puntero que sera el nuevo puntero inicial
                //  El puntero anterior es nulo porque no hay un puntero previo al inicial
                NodePtr n = new Node{value, head, nullptr};
                //  El puntero previo al inicial sera el nuevo puntero n
                head->previous_pointer = n;
                //  El puntero n es el nuevo head de la lista
                head = n;
            }
        }

        void push_back (AnyObject value) {
            //  Si no existe un puntero en la lista
            if (head == nullptr && tail == nullptr) {
                NodePtr first = new Node{value, nullptr, nullptr};
                head = first;
                tail = first;
            } else {
                NodePtr n = new Node{value, nullptr, tail};
                tail->next_pointer = n;
                tail = n;
            }
        }

        void pop_front() {
            //  Si existe al menos un puntero
            if (head != nullptr) {
                if (head->next_pointer == nullptr) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                } else {
                    NodePtr newHead = head->next_pointer;
                    delete head;
                    head = nullptr;
                    head = newHead;
                }
            }
        }

        void pop_back() {
            //  Si hay al menos un puntero
            if (head != nullptr) {
                //  Si solo hay un puntero en la lista
                if (head->next_pointer == nullptr) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                } else {
                    NodePtr previous = tail->previous_pointer;
                    delete tail;
                    tail = nullptr;
                    tail = previous;
                    tail->next_pointer = nullptr;
                }
            }
        }

        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");
            for (Node* current = head; current != nullptr ; current = current->next_pointer) {
                std::cout << current->value << " ";
            }
            std::cout << std::endl;
        }
    };
}

template <class AnyObject>
using DoubleLinkedList = cs2100::DoubleLinkedList<AnyObject>;

#endif /* doubleLinkedList_h */
