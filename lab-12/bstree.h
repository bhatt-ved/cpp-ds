//--------------------------------------------------------------------
//
//  Laboratory 11                                             bstree.h
//
//  Class declarations for the linked implementation of the
//  Binary Search Tree ADT -- including the recursive partners of
//  the public member functions
//
//--------------------------------------------------------------------

using namespace std;

template < class TE, class KF >    
class BSTree;                       


template < class TE, class KF >
class BSTreeNode             // Facilitator class for the BSTree class
{
  private:

    // Constructor
    BSTreeNode ( const TE &elem,
                 BSTreeNode *leftPtr, BSTreeNode *rightPtr );

    // Data members
    TE element;          // Binary search tree element
    BSTreeNode *left,    // Pointer to the left child
               *right;   // Pointer to the right child

  friend class BSTree<TE,KF>;
};

//--------------------------------------------------------------------

template < class TE, class KF >    // TE : tree element
class BSTree                       // KF : key field
{
  public:

    // Constructor
    BSTree ();

    // Destructor
    ~BSTree ();

    // Binary search tree manipulation operations
    void insert ( const TE &newElement );         // Insert element
    int retrieve ( KF searchKey, TE &searchElement);
                                                  // Retrieve element
    int remove ( KF deleteKey );                  // Remove element
    void writeKeys ();                            // Output keys
    void clear ();                                // Clear tree

    // Binary search tree status operations
    int empty () const;                           // Tree is empty
    int full () const;                            // Tree is full

    // Output the tree structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    int height () const;                          // Height of tree
    void writeLessThan ( KF searchKey ) const;    // Output keys
                                                  // searchKey

private:

    // Recursive partners of the public member functions  

	void insertSub ( BSTreeNode<TE,KF> *&p, const TE &newElement );

	int retrieveSub ( KF searchKey, TE &searchElement,
				                    BSTreeNode<TE,KF> *&p);

	void fixup ( BSTreeNode<TE,KF> *&p, BSTreeNode<TE,KF> *&del );

	int removeSub ( KF deleteKey, BSTreeNode<TE,KF> *&p);

	void writeKeysSub ( BSTreeNode<TE,KF> *&p );

	void clearSub ( BSTreeNode<TE,KF> *&p );

    void showSub ( BSTreeNode<TE,KF> *p, int level ) const;

	int heightSub ( BSTreeNode<TE,KF> *p ) const;

	void writeLessThanSub (  BSTreeNode<TE,KF> *p,
							KF searchKey ) const;

// Data member
    BSTreeNode<TE,KF> *root;   // Pointer to the root node
};
