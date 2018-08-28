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
            if(head!= nullptr ){
                Node *newnode= new Node{value, head,head->previous_pointer};
                head->previous_pointer->next_pointer=newnode;
                head->previous_pointer=newnode;
                head=newnode;
            }
            else{
                Node *newnode= new Node{value, newnode, newnode};
                head=newnode;

            }
        }

        void push_back (AnyObject value) {
            if(head!= nullptr ){
                Node *newnode= new Node{value, head,head->previous_pointer->previous_pointer};
                head->previous_pointer->next_pointer=newnode;
                head->previous_pointer=newnode;

            }
            else{
                Node *newnode= new Node{value, newnode, newnode};
                head=newnode;

            }
        }

        void pop_front() {
            if(head!= nullptr ){


                    Node *puntero=head;
                    puntero->next_pointer->previous_pointer= head->previous_pointer;
                puntero->previous_pointer->next_pointer=head->next_pointer;
                head=head->next_pointer;
                    delete (puntero);



            }
        }



        void pop_back() {
            if(head!= nullptr ){


                    Node *puntero=head->previous_pointer;
                    puntero->previous_pointer->next_pointer= head;
                    head->previous_pointer=puntero;

                    delete (puntero);


            }
        }
        inline void describe () {
            std::cout << "List:" << ((!head) ? " (empty)": " ");

            for ( Node * current = head ; current != head->previous_pointer ; current = current->next_pointer ) {

                std::cout << current->value << " ";
            }
            std::cout << "\n";
        }
    };
}

template <class AnyObject>
using CircularLinkedList = cs2100::CircularLinkedList<AnyObject>;

#endif /* circularLinkedList_h */
