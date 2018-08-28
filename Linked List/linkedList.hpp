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
            if(head== nullptr){
                Node *newnode= new Node{value, nullptr};
                head=newnode;
                tail=newnode;
            }else{
            Node *newnode= new Node{value, head};
            head=newnode;
        }}
        
        void push_back (AnyObject value) {
            Node *newnode= new Node{value, nullptr};
            tail->pointer=newnode;
            tail=newnode;
        }
        
        void pop_front() {

            if(head!= nullptr and tail!= nullptr){if(head!=tail){
              //  std::cout<<" "<< head->value<<" ";
               // std::cout<<'\n';
                Node *puntero=head;

                head=head->pointer;

                delete (puntero);}
                else{Node *punt=head;
                    head= nullptr;
                    tail=nullptr;
                    delete punt;

                }


            }
        }
        
        void pop_back() {
            if(head!= nullptr and tail!= nullptr){if(head!=tail){Node *puntero=head;
            Node *punteroantes=new Node;
            while(puntero->pointer!= nullptr){
                punteroantes=puntero;
                puntero=puntero->pointer;
            }
            tail=punteroantes;
            punteroantes->pointer= nullptr;
            delete puntero;
        }else{
                Node *punt=head;
                head= nullptr;
                tail=nullptr;
                delete punt;
            }}}

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
