//--------------------------------------------------------------------
//
//  Laboratory 9                                           listord.h
//
//  Class declaration for the array implementation of the Ordered
//  List ADT -- inherits the array implementation of the List ADT
//  (Laboratory 4)
//
//--------------------------------------------------------------------

#include "listarr.cpp"

template < class LE, class KF >     // LE : List Element
class OrdList : public List<LE>     // KF : Key field
{
  public:

    // Constructor
    OrdList ( int maxNumber = defMaxListSize );

    // Modified (or new) list manipulation operations
    virtual void insert ( const LE &newElement );
    virtual void replace ( const LE &newElement );
    int retrieve ( KF searchKey, LE &searchElement );

    // Output the list structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    void merge (OrdList &a);
    // int subset ( const OrdList &subL );

  private:

    // Locates an element (or where it should be) based on its key
    int binarySearch ( KF searchKey, int &index );
};
