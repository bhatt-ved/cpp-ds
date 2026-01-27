//--------------------------------------------------------------------
//
//  Laboratory 9                                           listord.cpp
//
//  Member function definition for the array implementation of the  
//  Ordered List ADT 
//
//--------------------------------------------------------------------

#include "listord.h"
#include <cassert>

//--------------------------------------------------------------------

template < class LE, class KF >
OrdList<LE,KF> :: OrdList (int maxNumber)

//Constructor  

: List<LE> (maxNumber)
{

    

}

//--------------------------------------------------------------------

template < class LE, class KF >
void OrdList<LE,KF> ::  insert (const LE &newElement)  

//Inserts a newelement in its appropreate position within a list.
//If an element with the same key as newElement already exists in the list, 
//then updates that element's nonkey fields with newElements's nonkey
//fields. Moves the cursor to newElement.

{

    assert(!empty());

    if (binarySearch(newElement.key(), index)) {
        element[index] = newElement;
    } else {
        if (!full()) {
            for (int i = size, i > index, i--) {
                element[i] = element[i-1];
            }
            element[index] = newElement;
            size += 1;
        }


}
	
//--------------------------------------------------------------------

template < class LE, class KF >
void OrdList<LE,KF>::  replace (const LE &newElement) 

//Replaces the elemnt marked by the cursor with newElement. Note that this 
//entails removing the element and inserting newElement. Moves the cursor
//to newElement.

{

    cursor->elem = newElement;

}

//--------------------------------------------------------------------

template < class LE, class KF >
int OrdList<LE,KF>::  retrieve (KF searchKey, LE &searchElement)

//Searches a lsit for the element with key searchKey. If the element is
//found, then moves the cursor to the element, copies the element to 
//searchElement, and returns 1. Otherwise, returns 0 without moving the 
//cursor and with searchElement undefined.

{

    assert(!empty());

    if (binarySearch(newElement.key(), index)) {
        while (cursor->elem != element[index]) {
            cursor += 1;
        }
        searchElement = element[index];
        return 1;
    } else
        return 0;

}

//--------------------------------------------------------------------

template < class LE, class KF >
int OrdList<LE,KF>::  binarySearch (KF searchKey, int &index)

// Locates an element (or where it should be) based on its key
// Returns 1 if element is found, otherwise returns 0.
// If element is not found, then returns the position of next element 
// to be inserted in the field 'inded'

{

    assert(!empty());

    int bottom = 0;
    int top = size - 1;
    int mid;
    
    while(bottom <= top) {
        mid = (bottom+top) / 2; 
        
        if (searchKey == element[mid].key()){
            index = mid;
            return 1;
        }
        else {
            if (searchKey > element[mid].key())
                bottom = mid + 1; 
            else
                top = mid - 1;
        }
    }
    return 0;
}
 
//--------------------------------------------------------------------

template < class LE, class KF >
void OrdList<LE,KF>:: showStructure () const

// Outputs the keys of the elements in the list. If the list is empty,
// outputs "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    int j;   // Loop counter

    if ( size == 0 )
       cout << "Empty list" << endl;
    else
    {
       cout << "size = " << size
            <<  "   cursor = " << cursor << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << element[j].key() << "\t";
       cout << endl;
    }
}

//--------------------------------------------------------------------
template < class LE, class KF >
void OrdList<LE,KF>:: merge (OrdList &a)

//Merges this array and sorted array a and puts result in this array.

{
}
