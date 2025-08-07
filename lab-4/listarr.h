//--------------------------------------------------------------------
//
//  Laboratory 4                                           listarr.h
//
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------

const int defMaxListSize = 10;   // Default maximum list size

template < class LE >
class List
{
// Data members Private by default

    LE *element;   // Array containing the list elements
  
    int maxSize,   // Maximum number of elements in the list
        size,      // Actual number of elements in the list
        cursor;    // Cursor array index
 


public:

    // Constructor
    List ( int maxNumber = defMaxListSize );

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

    // In-lab operations

    void moveToNth ( int n );                // Move element to pos. n
    int find ( const LE &searchElement );    // Find element
    void showDNAStructure(void) const;
};