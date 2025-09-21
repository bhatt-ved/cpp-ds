//--------------------------------------------------------------------
//
//  Laboratory 6                                        queuelnk.cpp
//
//  Function Definition for the linked list implementation of the
//  Queue ADT
//
//--------------------------------------------------------------------

#include "queuelnk.h"
#include <stdlib.h>			//for exit function

//--------------------------------------------------------------------

template < class QE >
Queue <QE>:: Queue (int ignored)

//Constructor. Provides sufficient space for intialization. The size of 
//queue is ignored.

{
}

//--------------------------------------------------------------------

template < class QE >
Queue <QE>:: ~Queue ()

//Destructor. Deletes all the memory allocated to the queue.

{
}

//--------------------------------------------------------------------


template < class QE >
void Queue <QE>:: enqueue( const QE &newElement)

//Creates a new node for newElement and inseret it at the rear.

{
}

//--------------------------------------------------------------------

template < class QE >
QE Queue <QE>:: dequeue()

//Removes the least recently added element form the front of queue and
//returns it.

{
}

//--------------------------------------------------------------------

template < class QE >
void Queue <QE>:: clear()  

//Removes all the elements in a queue.

{
}
		
//--------------------------------------------------------------------

template < class QE >
int Queue <QE>:: empty() const

//Returns 1 if queue is empty. Otherwise retuns 0.

{
}

//--------------------------------------------------------------------

template < class QE >
int Queue <QE>:: full() const

//Returns 1 if queue is empty. Otherwise retuns 0.

{
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>:: showStructure () const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
    QueueNode<QE> *p;   // Iterates through the queue

    if (empty())
       cout << "Empty queue" << endl;
    else
    {
       cout << "rear ";
	   p = rear;
	   while(p)
	   {
		   cout << p->element << " ";
		   p = p->next;
	   }
       cout << "front" << endl;
    }
}

//--------------------------------------------------------------------

template < class QE >
QueueNode<QE> :: QueueNode ( const QE &elem, QueueNode *nextPtr )

//Constructor for queue node.

{
}

//--------------------------------------------------------------------

template < class QE >
int Queue<QE>:: length() const

//This function is used in InLab # 3 of lab 6.
//It returns the length of the queue.

{
}
