//--------------------------------------------------------------------
//
//  Laboratory 8                                           listdbl.h
//
//  Class declarations for the non-circular, doubly linked list
//  implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef DOUBLELINK_H
#define DOUBLELINK_H


template < class LE >		   //Declaration
class List;

template < class LE >
class ListNode                 // Facilitator class for the List class
{
  private:

    // Constructor
    ListNode ( const LE &elem,
               ListNode *priorPtr, ListNode *nextPtr );

    // Data members
    LE element;         // List element
    ListNode *prev,    // Pointer to the previous element
             *next;     // Pointer to the next element

  friend class List<LE>;
};

//--------------------------------------------------------------------


// Doubly linked list data structure visual representation:

//   NULL <-- Prev   Node1   Next --> <-- Prev   Node2   Next --> <-- Prev  Node3   Next --> ... --> <-- Prev   NodeN   Next --> NULL
//                     ^
//                     |
//                   head


template < class LE >
class List
{
  public:

    // Constructor
    List ( int ignored = 0 );

    // Destructor
    ~List ();

    // List manipulation operations
    void insert ( const LE &newElement );    // Insert after cursor
    void remove ();                          // Remove element
    void replace ( const LE &newElement );   // Replace element
    void clear ();                           // Clear list

    // List status operations
    int empty () const;                      // List is empty
    int full () const;                       // List is full

    // List iteration operations
    int gotoBeginning ();                    // Go to beginning
    int gotoEnd ();                          // Go to end
    int gotoNext ();                         // Go to next element
    int gotoPrior ();                        // Go to prior element
    LE getCursor () const;                   // Return element

    // Output the list structure -- used in testing/debugging
    void showStructure () const;

    // In-lab opertions
    void reverse ();

  private:

    // Data members
    ListNode<LE> *head,     // Pointer to the beginning of the list
                 *cursor;   // Cursor pointer
};

#endif
