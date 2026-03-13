//--------------------------------------------------------------------
//
//  Laboratory 10                                         listrec.cpp
//
//  Linked list implementation of the List ADT with
//  additional recursive linked list functions
//
//--------------------------------------------------------------------

#include <iostream>
#include <cassert>
#include "stacklnk.cpp"
#include "listrec.h"


template < class LE >			 
List<LE> :: List (int ignored)

//Constructor. Creates an empty list. The argument is provided for call
//compatibility with the array implementation and is ignored.
{
	head = 0;
	cursor = 0;
	maxsize = ignored;
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
	if(full())       //Returns if the list is full
	{
		cout << "Can't handle more elements";
		return;
	}

	if(empty())
	{
		ListNode<LE> *temp;
		temp = new ListNode<LE>(newElement, 0);
		if(temp)
		{
			head = temp;
			cursor = head;
		}
	}

	else
	{
		ListNode<LE> *temp;
		temp = new ListNode<LE>(newElement, cursor->next);
		if(temp)
		{
			cursor->next = temp;
			cursor = cursor->next;
		}
	}
	counter++;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: replace (const LE &newElement)

//Replaces the element marked by the cursor with newElement. The cursor
//remains at newElement.
{
	if(empty())
		return;

	cursor->element = newElement;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: clear(void)

//Removes all the elements in a list.

{
	if(empty())
		return;
	else
		clearSub (head);

    this->counter = 0;
	head = 0;
	cursor = 0;
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template <class LE>
void List<LE> :: clearSub (ListNode<LE> *&p)

//Recursive partner of clear function.

{

if (p != 0)
    {
        clearSub(p->next);
        delete p;
        p = 0;
    }

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: empty(void) const

//Returns 1 if a list is empty; otherwise, returns 0

{
	return (head == 0);
}

//--------------------------------------------------------------------

template <class LE>
int List <LE> :: full(void) const 

//Returns 1 if list is full; otherwise, returns 0

{
	if(!maxsize)				//If there is not any upper limit defined
		return 0;				// for the list, returns 0; list can't be full
	return (counter == maxsize);
}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoBeginning(void)

//If a list is not empty, then moves the cursor to the beginning of 
//the list and returns 1
{
	if(empty())
		return 0;
	else
	{
		cursor = head;
		return 1;
	}
}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoEnd(void)

//If a list is not empty, then moves the cursor to the end of the list 
//and returns 1

{
	if(empty())
		return 0;
	else 
	{
		cursor = head;
		gotoEndSub (cursor);
		return 1;
	}
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template <class LE>
void List<LE> :: gotoEndSub(ListNode<LE> *&p)

//Recursive partner of gotoEnd() function

{

    if (p != 0) {
        p = p->next;
        gotoEndSub(p->next);
    }

}

//--------------------------------------------------------------------

template <class LE>
int List<LE> :: gotoNext(void)

//If the cursor is not at the end of a list, then moves the cursor
//to the next element in the list and returns 1. Otherwise returns 0.

{
	if(empty() || !(cursor->next))
		return 0;
	
	cursor = cursor->next;
	return 1;
}

//--------------------------------------------------------------------

template <class LE>
LE List<LE> :: getCursor(void) const

//Returns a copy of teh element marked by the cursor
{
	assert (!empty());
	return cursor->element;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE> :: showStructure(void) const

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
	temp = head;

	do
	{
		if(cursor!=temp)
			cout << "Element " << i << " :      " << temp->element << "\n";
		else 
			cout << "Element " << i << " :     [" << temp->element << "]\n";
		i++;
		temp = temp->next;
	}while(temp);	
}


//--------------------------------------------------------------------
//
// Recursively implemented linked list functions used in the Prelab
// Exercise
//
//--------------------------------------------------------------------

template < class LE >
void List<LE>:: write () const

// Outputs the elements in a list from beginning to end. Assumes that
// objects of type LE can be output to the cout stream.

{
    cout << "List : ";
    writeSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>:: writeSub ( ListNode<LE> *p ) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{

    if (p != 0) {
        cout << p->element;
        writeSub(p->next);
    }

}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: insertEnd ( const LE &newElement )

// Inserts newElement at the end of a list. Moves the cursor to
// newElement.

{
    insertEndSub(head,newElement);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>:: insertEndSub ( ListNode<LE> *&p,
                               const LE &newElement )

// Recursive partner of the insertEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    assert(!empty()); 
    if (p->next != 0) {
        insertEndSub(p->next, newElement);
    } else {
        List<LE>::insert(newElement);
    }
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: writeMirror () const

// Outputs the elements in a list from beginning to end and back
// again. Assumes that objects of type LE can be output to the cout
// stream.

{
    cout << "Mirror : ";
    writeMirrorSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>:: writeMirrorSub ( ListNode<LE> *p ) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{

    assert(!empty());
    if (p != 0) {
        cout << p->element;
        writeMirrorSub(p->next);
        cout << p->element;
    }
}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: reverse ()

// Reverses the order of the elements in a list.

{
    reverseSub(0,head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>:: reverseSub ( ListNode<LE> *p, ListNode<LE> *nextP )

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{

    if (nextP->next != 0) {
        reverseSub(nextP, nextP->next);
        nextP->next = p;
    } else {
        head = nextP;
        head->next = p;
    }

}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: deleteEnd ()

// Deletes the element at the end of a list. Moves the cursor to the
// beginning of the list.

{
    deleteEndSub(head);
    cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>:: deleteEndSub ( ListNode<LE> *&p )

// Recursive partner of the deleteEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    assert(!empty());
    if (p->next != 0) {
        deleteEndSub(p->next); 
    } else {
        delete p;
        p = 0;
        counter -= 1;
    }
}

//--------------------------------------------------------------------

template < class LE >
int List<LE>:: length () const

// Returns the number of elements in a list.

{
    return lengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
int List<LE>:: lengthSub ( ListNode<LE> *p ) const

// Recursive partner of the length() function. Processes the sublist
// that begins with the node pointed to by p.

{
    if (p == 0) 
        return 0;
    else 
        return (1 + lengthSub(p->next));
}

//--------------------------------------------------------------------
//
// "Unknown" operations used in the Bridge Exercise
//
//--------------------------------------------------------------------

template < class LE >
void List<LE>:: unknown1 () const

// Unknown function 1.

{
    unknown1Sub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>:: unknown1Sub ( ListNode<LE> *p ) const

// Recursive partner of the unknown1() function.

{

    if(p!= 0) {
        unknown1Sub(p->next);
        cout << p->element;
    }

}

//--------------------------------------------------------------------

template < class LE >
void List<LE>:: unknown2 ()

// Unknown function 2.

{
    unknown2Sub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void List<LE>:: unknown2Sub ( ListNode<LE> *&p )

// Recursive partner of the unknown2() function.

{

    if (p == 0 || p->next == 0)
        return;
    
    ListNode<LE> *cur_del = p->next;
    p->next = cur_del->next;
    delete cur_del;
    counter -= 1;
    unknown2Sub(p->next);

}

//-------------------IN LAB EXERCISE : 1A----------------------------
 
template < class LE >
void List<LE>:: iterReverse ( void )

//Iterative version of the reverse() function

{
	if(empty() || (head->next == 0))
		return;

	ListNode<LE> *h,*temp;
	h = head;
	cursor = h;
	
	while(cursor->next)
		cursor = cursor->next;  

	head = cursor;

	while(cursor != h)
	{
		temp = h;
		while(temp->next != cursor)
			temp = temp->next;
		cursor->next = temp;
		cursor = temp;
	}

	cursor->next = 0;
}

//-------------------IN LAB EXERCISE : 1B----------------------------
 
template < class LE >
void List<LE>:: stackWriteMirror ( void ) const

//Iterative version of the writeMirror() function

{
	Stack <ListNode<LE> *> tempStack;
	ListNode <LE> *p;

	cout << "\n\n\tMirror: ";

	p = head;

	while(p)
	{
		tempStack.push(p);
		cout << p->element;
		p = p->next;
	}

	while(!tempStack.empty())
	{
		p = tempStack.pop();
		cout << p->element;
	}

	cout << endl << endl;
}

//---------------------IN LAB EXERCISE : 2---------------------------

template < class LE >
void List<LE> :: aBeforeb ( void )

//Inserts element 'a' before all the occurances of element 'b'

{
	if(head == 0)
		return;
	cursor = head;
	if(head->element == 'b')
	{	
		ListNode<LE> *temp;
		temp = new ListNode<LE>('a', head);
		head = temp;

	}
	aBeforebSub(cursor);
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template < class LE >
void List<LE> :: aBeforebSub ( ListNode<LE> *&p)

//Recursive partner of the function aBeforeb(void)

{

    if (p == 0 || p->next == 0){
        return;
    }
    
    if (p->next->element == 'b') {
        ListNode<LE> *temp = new ListNode<LE>('a', p->next);
        p->next = temp;
        this->counter += 1;
        aBeforebSub(temp->next);
    } else {
        aBeforebSub(p->next);
    }
}

//-----------------IN LAB EXERCISE : 3-------------------------------

template < class LE >
void List<LE> :: cRemove ( void )

//Removes all the occurances of element 'c' from a list

{
	cursor = head;
	cRemoveSub(cursor);
	cursor = head;
}

//-------------------------------------------------------------------

template < class LE >
void List<LE> :: cRemoveSub ( ListNode<LE> *&p)

//Recursive partner of the function cRemove(void)

{
    if (p == 0) {
        return;
    }
    
    if (p->next != 0 && p->next->element == 'c') {
        ListNode<LE> *temp = p->next;
        p->next = temp->next;
        delete temp;
        counter -= 1;
        cRemoveSub(p);
    } else {
        cRemoveSub(p->next);
    }
}

//--------------------------------------------------------------------
