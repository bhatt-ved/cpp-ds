//--------------------------------------------------------------------
//
//  Laboratory 5                                          stacklnk.cpp
//
//  Member-Function definitions for the linked list implementation of the
//  Stack ADT
//
//--------------------------------------------------------------------


#include <stdlib.h>
#include <cassert>
#include "stacklnk.h"

using namespace std;

//-------------------------------------------------------------------

template <class SE>
Stack<SE> :: Stack(int ignored)

//Constructor. Creates an empty stack

{

    root = nullptr;
    top = nullptr;

}

//-------------------------------------------------------------------

template <class SE>
Stack<SE> :: ~Stack()

//Destructor. Deallocates all the memory assigned to the stack nodes.

{

    clear();

}

//------------------------------------------------------------------

template <class SE>
void Stack<SE> :: push(const SE &newElement)

//Pushes new element on the top of the stack if stack is not full

{
    
    if (full() == 0){
        StackNode<SE> *newNode = new StackNode<SE>(newElement, nullptr);
        
        if (empty() == 1) {
            cout << "Reached empty" << endl;
            root = newNode;
            top = newNode;
        }
        else {
            top->next = newNode;
            top = newNode;
        }
    }

}

//------------------------------------------------------------------

template <class SE>
SE Stack<SE> :: pop()

//Pops the top element of the stack, returns it and distroys it if stack is not empty

{
    //pop() must not be called on an empty list
    assert(empty() == 0);
    SE returnVal = top->element;
    if (root == top) {
        delete top; 
        root = nullptr;
        top = nullptr;
    }
    else {
        StackNode<SE> *cur = root;
        while (cur->next != top) 
            cur = cur->next;
        delete top;
        top = cur;
        top->next = nullptr;
    }                    
    return returnVal;
}

//------------------------------------------------------------------

template <class SE>
void Stack<SE> :: clear()

//Clears the stack.

{

    while (empty() == 0)
        pop();


}

//------------------------------------------------------------------


template <class SE>
int Stack<SE> :: empty() const

//Returns 1 if stack is empty. Otherwise returns 0

{

    if (root == nullptr)
        return 1;
    else
        return 0;

}

//------------------------------------------------------------------

template <class SE>
int Stack<SE> :: full() const

//Returns 1 if stack is full. Otherwise returns 0

{

    return 0;    

}

//------------------------------------------------------------------

template < class SE >
void Stack<SE>:: showStructure () const

// Linked list implementation. Outputs the elements in a stack. If
// the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    StackNode<SE> *p;   // Iterates through the stack

    if ( top == 0 )
       cout << "Empty stack" << endl;
    else
    {
       cout << "top ";
       for ( p = root ; p != 0 ; p = p->next )
           cout << p->element << " ";
       cout << "bottom" << endl;
    }
}

//------------------------------------------------------------------

template < class SE >
StackNode<SE> :: StackNode ( const SE &elem, StackNode *nextPtr )

//Constructor for stacknode class.

{

    element = elem;
    next = nextPtr;

}

//------    ------------------------------------------------------------
