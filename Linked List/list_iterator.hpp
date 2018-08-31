//
//  iterator.hpp
//  Linked List
//
//  Created by Bryan Gonzales Vega on 8/30/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef list_iterator_h
#define list_iterator_h

#include "linkedList.hpp"

namespace cs2100 {
    
    template <class AnyObject>
    class ForwardIterator {
    private:
        typedef typename LinkedList<AnyObject>::Node Node;
        
        Node * current;
        
    public:
        ForwardIterator () = default;
        
        /* Operators Overload */
        
        // ...
    };
}

#endif /* listIterator_h */
