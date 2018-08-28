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
            if(head!= nullptr and tail!= nullptr){
                Node *newnode= new Node{value, head, nullptr};
                head->previous_pointer=newnode;
                head=newnode;
            }
            else{
                Node *newnode= new Node{value, nullptr, nullptr};
                head=newnode;
                tail=newnode;
            }
        }
        
        void push_back (AnyObject value) {
            if(head!= nullptr and tail!= nullptr){
                Node *newnode= new Node{value, nullptr, tail};
                tail->next_pointer=newnode;
                tail=newnode;
            }
            else{
                Node *newnode= new Node{value, nullptr, nullptr};
                head=newnode;
                tail=newnode;
            }
        }
        
        void pop_front() {
            if(head!= nullptr and tail!= nullptr){if(head!=tail){


                    Node *puntero=head;
                    puntero->next_pointer->previous_pointer= nullptr;
                    head=head->next_pointer;
                    delete (puntero);}
                else{Node *punt=head;
                    head= nullptr;
                    tail=nullptr;
                    delete punt;

                }


            }
        }


        
        void pop_back() {
            if(head!= nullptr and tail!= nullptr){if(head!=tail){


                    Node *puntero=tail;
                    puntero->previous_pointer->next_pointer= nullptr;
                    tail=tail->previous_pointer;
                    delete (puntero);}
                else{Node *punt=head;
                    head= nullptr;
                    tail=nullptr;
                    delete punt;

                }


            }
        }
        
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");
            
            /* Complete this function */
        }
    };
}

template <class AnyObject>
using DoubleLinkedList = cs2100::DoubleLinkedList<AnyObject>;

#endif /* doubleLinkedList_h */
