//--------------------------------------------------------------------
//
//  Laboratory 7                                           listlnk.cpp
//
//  Class declarations for the linked list implementation of the
//  List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <cassert>
#include "listlnk.h"

using namespace std;
 
//--------------------------------------------------------------------

template < class LE >			 
List<LE> :: List (int ignored)

//Constructor. Creates an empty list. The argument is provided for call
//compatibility with the array implementation and is ignored.
{

    head = nullptr;
    cursor = nullptr; 
    maxSize = 0;
    counter = 0; 
}

//--------------------------------------------------------------------

template < class LE >			
List<LE> :: ~List ()

//Destructor. Frees the memory used to store a list.
{

    clear();

}

//--------------------------------------------------------------------

template < class LE >								
ListNode<LE> :: ListNode ( const LE &elem, ListNode *nextPtr )

//Constructor for list node. Creates a list node with proper elements

{

    element = elem;
    next = nextPtr;
    
}

//--------------------------------------------------------------------

template < class LE >
void List<LE> :: insert(const LE &newElement)

//Inserts newElement into a list. If teh list is not empty, then inserts
//newElement after the cursor. Otherwise, inserts newElement as the first
//element of the list. In either case, moves the cursor to the newElement.

{

    assert(!full());
    counter += 1;
    ListNode<LE> *newNode = new ListNode<LE> (newElement, nullptr); 
    if (empty()) {
        head = newNode;
        cursor = newNode;
    }
    else {
        newNode->next = cursor->next;
        cursor->next = newNode;
        cursor = newNode; 
    }            

}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: remove (void)

//Removes the element marked by the cursor from a list. If the resulting
//list is not empty, then moves the cursor to the element that
//followed the deleted element. If the deleted element was at the end
//of list, then moves the cursor to the beginning of the list.

{
    if(!empty()) {
        counter -= 1;
        ListNode<LE> *temp = cursor;
        ListNode<LE> *prev = head; 
        if (cursor == head) {       //If cursor points to start
            cursor = cursor->next;
            head = cursor;
        }
        else {
            cout << "Reached here" << endl;
            while(prev->next != cursor)
                prev = prev->next;
            
            prev->next = cursor->next;

            if (cursor->next == nullptr)   //If cursor points to end
                cursor = head;

            else                           //If cursor is in between
                cursor = cursor->next;
        }
        delete temp;
    }
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: replace (const LE &newElement)

//Replaces the element marked by the cursor with newElement. The cursor
//remains at newElement.
{
    if(!empty()) {
        ListNode<LE> *temp = cursor;
        ListNode<LE> *newNode = new ListNode<LE>(newElement, cursor->next);
        
        if(counter == 1) {
            head = newNode;
        }
        else {
            ListNode<LE> *prev = head;
            while (prev->next != cursor) {
                prev = prev->next;
            }
            prev->next = newNode;
        }
        cursor = newNode;
        delete temp;
    }
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: clear(void)

//Removes all the elements in a list.

{
    while(counter > 0) {
        cursor = head;
        remove();
    }

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: empty(void) const

//Returns 1 if a list is empty; otherwise, returns 0

{

    if (head == nullptr)
        return 1;
    else
        return 0;

}

//--------------------------------------------------------------------

template <class LE>
int List <LE> :: full(void)

//Returns 1 if list is full; otherwise, returns 0

{

    return 0;
    
}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoBeginning(void)

//If a list is not empty, then moves the cursor to the beginning of 
//the list and returns 1
{

    if(!empty()) {
        cursor = head;
        return 1;
    }
    else
        return 0;

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoEnd(void)

//If a list is not empty, then moves the cursor to the end of the list 
//and returns 1

{
    if(!empty()) { 
        while(cursor->next != nullptr) {
            cursor = cursor->next;
        }
        return 1;
    }
    else
        return 0;
}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoNext(void)

//If the cursor is not at the end of a list, then moves the cursor
//to the next element in the list and returns 1. Otherwise returns 0.

{

    if(!empty()) {
        if(cursor->next != nullptr) {
            cursor = cursor->next; 
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoPrior(void)

//If the cursor is not at the beginning of a list, then moves the cursor
//to the preceeding element in the list and returns 1. Otherwise, returns 0.

{

    if(!empty()) {
        if (cursor == head)
            return 0;
        else{
            ListNode<LE> *prev = head;
            while (prev->next != cursor)
                prev = prev->next;
            cursor = prev;
            return 1;
        } 
    }
    else
        return 0;
}

//--------------------------------------------------------------------

template <class LE>
LE List<LE> :: getCursor(void) const

//Returns a copy of teh element marked by the cursor

{

    return cursor->element;

}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: showStructure(void)

//Outputs the elements in a list. If the list is empty, outputs "empty
//list". This function is for testing/debugging purpose only.

{
	int i=1;
	ListNode<LE> *temp;
	if(empty())
	{
		cout << "List is Empty !\a";
		return;
	}
	temp = cursor;
	cursor = head;
	do
	{
		if(cursor!=temp)
			cout << "Element " << i << " :      " << cursor->element << "\n";
		else 
			cout << "Element " << i << " :     [" << cursor->element << "]\n";
		i++;
		cursor = cursor->next;
	}while(cursor);	
	cursor = temp;
}

//------------------------IN LAB EXERCISE 2---------------------------

template <class LE>
void List<LE> :: moveToBeginning(void)

//Removes the element marked by the cursor from a list and reinserts 
//it at the beginning of the list. Moves the cursor to the beginning.

{
    if (!empty()) {
        ListNode<LE> *newNode = new ListNode<LE>(cursor->element, head);
        if (cursor != head) { 
            remove();
            counter += 1;
            head = newNode;
            cursor = head;
        }
    }
}

//------------------------IN LAB EXERCISE 3---------------------------

template <class LE>
void List<LE> :: insertBefore(const LE &newElement)

//Inserts newElement into  a list. If the list is not empty, then 
//inserts newElement immediately before the cursor. Otherwise, inserts
//it as first element in the list. In either case, moves the cursor to 
//newElement.

{
    if(!full()) {
        if(!empty()) {
            ListNode<LE> *prev = head;
            ListNode<LE> *newNode = new ListNode<LE>(newElement, nullptr);
            if (counter == 1) { 
                newNode->next = head;
                head = newNode;
                cursor = newNode;
                counter += 1;
            }
            else {
                if (gotoPrior()) 
                    insert(newElement);
                else {
                    if (cursor == head){
                        newNode->next = head;
                        head = newNode;
                        cursor = newNode;
                        counter += 1;
                    }
                    else
                        cout << "Should never reach here" << endl;
                }
            }
        }
        else
            insert(newElement);
    }
}
