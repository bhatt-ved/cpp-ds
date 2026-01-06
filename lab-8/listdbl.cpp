//--------------------------------------------------------------------
//
//  Laboratory 8                                           listdbl.cpp
//
//  Member function definition for doubly linked list
//  implementation of the List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <cassert>
//#include <stdlib.h>
#include "listdbl.h"


using namespace std;

//--------------------------------------------------------------------

template <class LE>
ListNode<LE> :: ListNode ( const LE &elem,ListNode *priorPtr, ListNode *nextPtr )

//Constructor for listnode

{

    element = elem;
    next = nextPtr;
    prev = priorPtr;    

}

//--------------------------------------------------------------------

template <class LE>
List<LE> :: List (int ignored)

//Constructor for the list. Ignores the maximum size of the list.

{

    head = nullptr;
    cursor = nullptr;

}

//--------------------------------------------------------------------

template <class LE>
List<LE> :: ~List ()

//Destructor. Frees the memory alocated to the list

{

    clear();

}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: insert (const LE &newElement)

//Inserts newElement into a list. If the list is not empty, then iserts
//newElement after the cursor. Otherwise, inserts newElement as the 
//fiest element in the list. In either case, moves the cursor 
//to newElement.

{

    assert(!full());
    ListNode<LE> *newNode = new ListNode<LE> (newElement, nullptr, nullptr); 
    if (empty()) {
        head = newNode;
        cursor = newNode;
    }
    else {
        newNode->next = cursor->next;
        newNode->prev = cursor;
        cursor->next = newNode;
        cursor = newNode; 
    }
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: remove ()

//Removes the element marked by the cursor from a list. If the resulting
//list is not empty, then moves cursor to the element followed by the 
//deleted element. If the deleted element was the last element, then 
//moves cursor to the beginning of the list.

{

    if (empty()) return;
    
    ListNode<LE> *temp = cursor;

    if (cursor->prev)
        (cursor->prev)->next = cursor->next;
    if (cursor->next)
        (cursor->next)->prev = cursor->prev;

    if (cursor->next == nullptr) {
        if (cursor->prev == nullptr)
            head = cursor = nullptr;
        else
            cursor = head;
    } else {
        if (cursor->prev == nullptr)
            head = cursor = cursor->next;
        else
            cursor = cursor->next;
    }
    delete temp; 
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: replace (const LE &newElement)

//Replaces the element marked by the cursor with newElement.
//The Cursor remains at the newElement.

{
    if (!empty())
        cursor->element = newElement;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: clear ()

//Removes all the elements in a list.

{
    while(!empty()) 
        remove();
}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: empty () const

//Returns 1 if list is empty. Otherwise, returns 0

{

    if(head == nullptr)
        return 1;
    else
        return 0;

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: full () const

//Returns 1 if list is full. Otherwise, returns 0

{

    return 0;

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoBeginning () 

//If list is not empty, then moves the cursor to the beginning of the
//list and returns 1. Otherwise retuns 0.

{

    if(!empty()) {
        cursor = head;
        return 1;
    } else
        return 0;

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoEnd () 

//If a list is not empty, then moves the cursor to the end of the list
//and returns 1. Otehrwise returns 0.

{

    if(!empty()) {
        while (cursor->next != nullptr)
            cursor = cursor->next;
        return 1;
    }
    else
        return 0;

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoNext () 

//If the cursor is not at the end of a list, then moves the cursor to 
//the next element of the list and returns 1. Otherwise returns 0.

{

    if(!empty()) {
        if (cursor->next == nullptr)
            return 0;
        else
            cursor = cursor->next;
        return 1;
    }
    else {
        return 0;
    }
}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoPrior () 

//If the cursor is not at the beginning of a list, then moves the cursor
//to the prior element of the list and returns 1. Otherwise returns 0

{

    if(!empty()) {
        if(cursor->prev == nullptr)
            return 0;
        else
            cursor = cursor->prev;
            return 1;
    }
    else
        return 0;

}

//--------------------------------------------------------------------

template <class LE>
LE List<LE> :: getCursor () const

//Returns a copy of the element marked by the cursor

{

    if (!empty())
        return (cursor->element);
    else
        return 0;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: showStructure () const

// Outputs the elements in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    ListNode<LE> *p;   // Iterates through the list

    if ( head == 0 )
       cout << "Empty list" << endl;
    else
    {
       p = head;
       do
       {
          if ( p == cursor )
             cout << "[" << p->element << "] ";
          else
             cout << p->element << " ";
          p = p->next;
       }
       while (p);
       cout << endl;
    }
}

//---------------IN LAB EXERCISE - 2----------------------------------

template < class LE >
void List<LE>:: reverse ()

//Reverses the order of the elements in a list.

{

    if(gotoBeginning()) {
        ListNode<LE> *prev_temp = nullptr;
        while (cursor != nullptr) {
            if (cursor->next == nullptr) 
                prev_temp = cursor;
            
            ListNode<LE> *temp = cursor->next;
            cursor->next = cursor->prev;
            cursor->prev = temp;
            cursor = temp;
        }
        head = cursor = prev_temp;
    } 
}

//-----------------------------------------------------------------EOF
