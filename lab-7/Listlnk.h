//--------------------------------------------------------------------
//
//  Laboratory 7                                           listlnk.h
//
//  Class declarations for the linked list implementation of the
//  List ADT
//
//--------------------------------------------------------------------
 
template <class LE>
class List;

template < class LE >
class ListNode                 // Facilitator class for the List class
{
  private:

    // Constructor
    ListNode ( const LE &elem, ListNode *nextPtr );

    // Data members
    LE element;       // List element
    ListNode *next;   // Pointer to the next element

  friend class List<LE>;
};

//--------------------------------------------------------------------

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
    int full ();                             // List is full

    // List iteration operations
    int gotoBeginning ();                    // Go to beginning
    int gotoEnd ();                          // Go to end
    int gotoNext ();                         // Go to next element
    int gotoPrior ();                        // Go to prior element
    LE getCursor () const;                   // Return element

    // Output the list structure -- used in testing/debugging
    void showStructure ();

    // In-lab operations
    void moveToBeginning ();                 // Move to beginning
    void insertBefore ( const LE &newElement );
                                             // Insert before cursor

  private:

    // Data members
    ListNode<LE> *head,     // Pointer to the beginning of the list
                 *cursor;   // Cursor pointer
	friend class ListNode<LE>;

	int maxSize;			//To put an upper limit to link nodes
	int counter;			//Counts current nodes of list
};
