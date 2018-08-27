//
//  list.h
//  Linked List
//
//  Created by Bryan Gonzales Vega on 8/22/18.
//  Copyright © 2018 UTEC. All rights reserved.
//

#ifndef list_h
#define list_h

namespace cs2100 {
    
    template <class AnyObject>
    struct List {
        virtual void push_front (AnyObject value) = 0;
        virtual void push_back  (AnyObject value) = 0;
        
        virtual void pop_front () = 0;
        virtual void pop_back  () = 0;
        
        virtual void describe  () = 0;
    };

    
}

#endif /* list_h */
