//--------------------------------------------------------------------
//
//  Laboratory 9                                          listarr2.h
//
//  Class declaration for the array implementation of the List ADT
//  (Laboratory 4) with modifications to support inheritance by the
//  array implementation of the Ordered List ADT
//
//--------------------------------------------------------------------

const int defMaxListSize = 10;   // Default maximum list size

template < class LE >
class List
{
  public:

    // Constructor
    List ( int maxNumber = defMaxListSize );

    // Destructor
    ~List ();

    // List manipulation operations
    virtual void insert ( const LE &newElement );    // Insert
    void remove ();                                  // Remove
    virtual void replace ( const LE &newElement );   // Replace
    void clear ();                                   // Clear list

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

    // In-lab operations (Laboratory 4)
    void moveToNth ( int n );                // Move element to pos. n
    int find ( const LE &searchElement );    // Find element

  protected:

    // Data members
    int maxSize,   // Maximum number of elements in the list
        size,      // Actual number of elements in the list
        cursor;    // Cursor array index
    LE *element;   // Array containing the list elements
};
