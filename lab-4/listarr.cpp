//--------------------------------------------------------------------
//
//  Laboratory 4                                         listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//
//--------------------------------------------------------------------

#include <iostream>

#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

template < class LE >
List<LE>:: List ( int maxNumber )

// Creates an empty list. Allocates enough memory for maxNumber
// elements (defaults to defMaxListSize).

{
    maxSize = maxNumber;
    size = 0;
    cursor = -1;
    
    element = new LE[maxSize];
}

//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List ()

// Frees the memory used by a list.

{
    delete element;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: insert ( const LE &newElement )

// Inserts newElement after the cursor. If the list is empty, then
// newElement is inserted as the first (and only) element in the list.
// In either case, moves the cursor to newElement.

{
      
    if (full() == 1) 
        cout << "List is full. Could not add.\n";
    else {
        if (empty() == 1)
            cursor = 0;

        element[size] = newElement;
        size += 1;
    } 
        
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: remove ()

// Removes the element marked by the cursor from a list. Moves the
// cursor to the next element in the list. Assumes that the first list
// element "follows" the last list element.

{

    if (empty() == 0) { 
        while (cursor < (size - 1)) {
            element[cursor] = element[cursor + 1];
            cursor += 1;
        }
    }

}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: replace ( const LE &newElement )

// Replaces the element marked by the cursor with newElement and
// leaves the cursor at newElement.

{
    if (empty() == 0)
        element[cursor] = newElement;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: clear ()

// Removes all the elements from a list.

{
    if (empty() == 0) {  // If not empty
        cursor = -1;
        size = 0;
    }
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: empty () const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
    return (size == 0) ? 1 : 0;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: full () const

// Returns 1 if a list is full. Otherwise, returns 0.

{
    return (size == maxSize) ? 1 : 0;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoBeginning ()

// If a list is not empty, then moves the cursor to the beginning of
// the list and returns 1. Otherwise, returns 0.

{
    if (empty() == 1)
        return 0;
    else {
        cursor = 0;
        return 1;
    }
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoEnd ()

// If a list is not empty, then moves the cursor to the end of the
// list and returns 1. Otherwise, returns 0.

{
    if (empty() == 1)
        return 0;
    else {
        cursor = size - 1;
        return 1;
    }
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoNext ()

// If the list is not empty or the cursor is not at the end of the list,
// increments the cursor and returns 1. 
// Otherwise returns 0.

{
    if ((empty() == 0) && (cursor != (size - 1))) { 
        cursor += 1;
        return 1;
    }
    else
        return 0;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoPrior ()

// If the cursor is not at the beginning of a list, or the list is not
// empty, then decrements the cursor and returns 1. Otherwise returns 0

{

    if ((empty() == 0) && (cursor != 0)) {
        cursor -= 1;
        return 1;
    }
    else
        return 0;

}

//--------------------------------------------------------------------

template < class LE >
LE List<LE>:: getCursor () const

// Returns the element marked by the cursor.

{
    return element[cursor];
}


//--------------------------------------------------------------------


template < class LE >
void List<LE>:: moveToNth ( int n )

// Removes the element marked by the cursor from a list and
// reinserts it as the nth element in the list -- where the elements
// are numbered from beginning to end, starting with 0. Moves the
// cursor to the new position of the moved element.

{

    if (empty() == 1)
        cout << "Error! List is empty. \n";
    else if (n >= size)
        cout << "Index out of list range. \n";
    else {
        LE temp = element[n];
        element[n] = element[cursor];
        element[cursor] = temp;
    }
}


//----------------------------------------------------------------------------

template < class LE >
int List<LE> :: find ( const LE &searchElement ) const

// Searches a list for searchElement. Starts from beggining of list
// until either searchElement is found (returns first occurence of
// searchElement in the list) or the end of the list is reached 
// (returns -1).

{

    if (empty() == 1)
        return -1;
    else {
        for (int i = 0; i < size; i++) {
            if (element[i] == searchElement)
                return i;
        } 
        return -1;
    }
}

//-------------------------------------------------------------------

template < class LE >
void List<LE>:: showStructure () const

// Outputs the elements in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
    if (empty() == 1)
        cout << "List is empty\n";
    else {
        cout << "| ";
        for (int i = 0; i < size; i++)
            cout << element[i] << " | ";
        cout << "\n  ";
        for (int i = 0; i < cursor; i++)
            cout << "    ";
        cout << "^" << endl;
    }
    cout << "Size: " << size << ", Cursor: " << cursor << endl;
}
