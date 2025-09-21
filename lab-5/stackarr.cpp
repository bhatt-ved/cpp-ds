//--------------------------------------------------------------------
//
//  Laboratory 5                                      stackarr.cpp
//
//  Member function definitions for the array implementation of the
//  Stack ADT
//
//--------------------------------------------------------------------

#include "stackarr.h"
#include <stdlib.h>			//for exit() function
#include <iostream>
#include <assert.h>

using namespace std;

//--------------------------------------------------------------------

template <class SE>
Stack<SE> :: Stack(int maxNumber)

// Constructor. Creates an empty stack. Allocates enough memory
//for a stack containing maxNumber elements.


{

    maxSize = maxNumber;
    top = -1;
    element = new SE[maxSize]; 

}
//--------------------------------------------------------------------

template <class SE>
Stack<SE> :: ~Stack()

//Destructor. Deallocates the memory used to store a stack

{
    delete element;
}
//--------------------------------------------------------------------

template <class SE>
int Stack<SE> :: push(const SE &newElement)

//Inserts newElement onto the top of a stack. Returns 0
//if stack is full, 1 if it was a success.

{

    if (full() == 1) {
        cout << "Stack is full. Cannot push.";
        return 0;
    }
    else {
        top += 1;
        element[top] = newElement;
        return 1;
    }
}
//--------------------------------------------------------------------

template <class SE>
SE Stack<SE> :: pop()

//Removes the most recently added element (top) from a stack and returns it.

{
    if (empty() == 1) {
        cout << "Stack is empty. Cannot pop.";
        exit(1);
    }
    else { 
        top -= 1;
        return element[top+1];
    }
}
//--------------------------------------------------------------------


template <class SE>
void Stack<SE> :: clear()

//Removes all the elements from the stack

{

    if (empty() == 0)
        top = -1;

}
//--------------------------------------------------------------------

template <class SE>
int Stack<SE> :: empty() const

//Returns 1 if a stack is empty; otherwise returns 0

{
    return ((top == -1) ? 1 : 0);
}

//--------------------------------------------------------------------

template <class SE>
int Stack<SE> :: full() const

//Returns 1 if stack is full; otherwise returns 1

{
    return ((top == (maxSize-1)) ? 1 : 0);
}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>:: showStructure () const

//Outputs the elements in a stack. If the stack is empty, outputs
//"Empty stack". This function supports C++'s built-in data types 

{
    int j;   // Loop counter

    if ( top == -1 )
       cout << "Empty stack" << endl;
    else
    {
       cout << "top = " << top << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j <= top  ; j++ )
           cout << element[j] << "\t";
       cout << endl;
    }
}
