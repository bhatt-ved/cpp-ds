//--------------------------------------------------------------------
//
//  Laboratory 4                                         listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//
//--------------------------------------------------------------------

#include <assert.h>
#include "listarr.h"

//--------------------------------------------------------------------

template < class LE >
List<LE>:: List ( int maxNumber )

// Creates an empty list. Allocates enough memory for maxNumber
// elements (defaults to defMaxListSize).

{
}

//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List ()

// Frees the memory used by a list.

{
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: insert ( const LE &newElement )

// Inserts newElement after the cursor. If the list is empty, then
// newElement is inserted as the first (and only) element in the list.
// In either case, moves the cursor to newElement.

{
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: remove ()

// Removes the element marked by the cursor from a list. Moves the
// cursor to the next element in the list. Assumes that the first list
// element "follows" the last list element.

{
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: replace ( const LE &newElement )

// Replaces the element marked by the cursor with newElement and
// leaves the cursor at newElement.

{
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: clear ()

// Removes all the elements from a list.

{
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: empty () const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: full () const

// Returns 1 if a list is full. Otherwise, returns 0.

{
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoBeginning ()

// If a list is not empty, then moves the cursor to the beginning of
// the list and returns 1. Otherwise, returns 0.

{
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoEnd ()

// If a list is not empty, then moves the cursor to the end of the
// list and returns 1. Otherwise, returns 0.

{
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoNext ()

// If the list is not empty or the cursor is not at the end of the list,
// increments the cursor and returns 1. 
// Otherwise returns 0.

{
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoPrior ()

// If the cursor is not at the beginning of a list, or the list is not
// empty, then decrements the cursor and returns 1. Otherwise returns 0

{
}

//--------------------------------------------------------------------

template < class LE >
LE List<LE>:: getCursor () const

// Returns the element marked by the cursor.

{
}


//--------------------------------------------------------------------


template < class LE >
void List<LE>:: moveToNth ( int n )

// Removes the element marked by the cursor from a list and
// reinserts it as the nth element in the list -- where the elements
// are numbered from beginning to end, starting with 0. Moves the
// cursor to the new position of the moved element.

{
}


//----------------------------------------------------------------------------

template < class LE >
int List<LE> :: find ( const LE &searchElement )

// Searches a list for searchElement. Begins the search with the
// element marked by the cursor. Moves the cursor through the list
// until either searchElement is found (returns 1) or the end of the
// list is reached (returns 0).

{
}

//-------------------------------------------------------------------

template < class LE >
void List<LE>:: showStructure () const

// Outputs the elements in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
}