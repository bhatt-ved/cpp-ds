//--------------------------------------------------------------------
//
//  Laboratory 4                                         listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <assert.h>
#include "listarr2.h"

using namespace std;

//--------------------------------------------------------------------

template < class LE >
List<LE>:: List ( int maxNumber )

// Creates an empty list. Allocates enough memory for maxNumber
// elements (defaults to defMaxListSize).

  : maxSize(maxNumber),
    size(0),
    cursor(-1)
{
    element = new LE [ maxSize ];
    assert ( element != 0 );
}

//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List ()

// Frees the memory used by a list.

{
    delete [] element;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: insert ( const LE &newElement )

// Inserts newElement after the cursor. If the list is empty, then
// newElement is inserted as the first (and only) element in the list.
// In either case, moves the cursor to newElement.

{
    int j;   // Loop counter

    if ( size == maxSize )     // Requires that list is not full
    {
        cout << "\n\aCan not handle more elements\n";
        return;
    }

    for ( j = size ; j > cursor+1 ; j-- )
        element[j] = element[j-1];
    size++;
    element[++cursor] = newElement;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: remove ()

// Removes the element marked by the cursor from a list. Moves the
// cursor to the next element in the list. Assumes that the first list
// element "follows" the last list element.

{
    int j;   // Loop counter

    assert ( size != 0 );     // Requires that the list is not empty

    for ( j = cursor ; j < size-1 ; j++ )
        element[j] = element[j+1];
    size--;
    if ( size == 0 )
       cursor = -1;
    else if ( size == cursor )
       cursor = 0;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: replace ( const LE &newElement )

// Replaces the element marked by the cursor with newElement and
// leaves the cursor at newElement.

{
    assert ( size != 0 );      // Requires that the list is not empty
    element[cursor] = newElement;
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: clear ()

// Removes all the elements from a list.

{
    size = 0;
    cursor = -1;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: empty () const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
    return ( size == 0 );
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: full () const

// Returns 1 if a list is full. Otherwise, returns 0.

{
    return ( size == maxSize );
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoBeginning ()

// If a list is not empty, then moves the cursor to the beginning of
// the list and returns 1. Otherwise, returns 0.

{
   if ( size != 0 )
   {
      cursor = 0;
      return 1;
   }
   else
      return 0;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoEnd ()

// If a list is not empty, then moves the cursor to the end of the
// list and returns 1. Otherwise, returns 0.

{
   if ( size != 0 )
   {
      cursor = size - 1;
      return 1;
   }
   else
      return 0;
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoNext ()

// If the cursor is not at the end of a list, then moves the
// cursor to the next element in the list and returns 1. Otherwise,
// returns 0.

{
   if(empty() || cursor == size-1) 
   	   return 0;
   
   else
   {
	   cursor++;
       return 1;
   }
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: gotoPrior ()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding element in the list and returns 1. If
// cursor is at the beginning of the list, then moves it to the end
// of list and returns 1.
// Otherwise, returns 0.

{
   if (!empty())
   {

		if ( cursor != 0 )
			cursor--;
		else if( cursor == 0)
			cursor = size - 1;

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
    assert ( size != 0 );      // Requires that the list is not empty
    return element[cursor];
}


//--------------------------------------------------------------------
//
//                        In-lab operations
//
//--------------------------------------------------------------------

template < class LE >
void List<LE>:: moveToNth ( int n )

// Removes the element marked by the cursor from a list and
// reinserts it as the nth element in the list -- where the elements
// are numbered from beginning to end, starting with 0. Moves the
// cursor to the new position of the moved element.

{
    int j;     // Loop counter
    LE temp;   // Stores element to be moved

    assert ( size != 0  &&  n < size );
                       // Requires that the list is not empty and that
                       // there are at least n+1 elements in the list

    temp = element[cursor];
    if ( n < cursor )
       for ( j = cursor-1 ; j >= n ; j-- )
           element[j+1] = element[j];
    else
       for ( j = cursor ; j < n ; j++ )
           element[j] = element[j+1];
    element[n] = temp;
    cursor = n;
}


//----------------------------------------------------------------------------

template < class LE >
int List<LE> :: find ( const LE &searchElement )

// Searches a list for searchElement. Begins the search with the
// element marked by the cursor. Moves the cursor through the list
// until either searchElement is found (returns 1) or the end of the
// list is reached (returns 0).

{
    int result;   // Result returned

    assert ( size != 0 );      // Requires that the list is not empty

    while ( cursor < size  &&  element[cursor] != searchElement )
        cursor++;

    if ( cursor < size )
       result = 1;
    else
    {
       cursor--;
       result = 0;
    }

    return result;
}

//-----------------------------------------------------------------------
