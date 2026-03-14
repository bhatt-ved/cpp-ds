//--------------------------------------------------------------------
//
//  Laboratory 11                                           bstree.cpp
//
//  Member function implementation for the linked implementation of the
//  Binary Search Tree ADT 
//
//--------------------------------------------------------------------

#include <iostream>
#include "bstree.h"

using namespace std;

//--------------------------------------------------------------------

template < class TE, class KF >
BSTreeNode<TE,KF> :: BSTreeNode ( const TE &elem,
                 BSTreeNode *leftPtr, BSTreeNode *rightPtr )


//Constructor of the tree node.

{
	element = elem;
	left = leftPtr;
	right = rightPtr;
}

//--------------------------------------------------------------------

template < class TE, class KF >
BSTree<TE,KF> :: BSTree ( void )

//Constructor. Creates an empty binary tree

{
	root = NULL;
}

//--------------------------------------------------------------------

template < class TE, class KF >
BSTree<TE,KF> :: ~BSTree ( void )

//Destructor. Deallocates the memory used to store a binary search tree

{
	clear();
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF> :: insert ( const TE &newElement )

//Inserts newElement into a binary search tree. If an element with the 
//key as newElement already exists in a trer, then updates that elements'
//nonkey fields with newElement's nonkey fields.

{
	insertSub ( root, newElement );
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template < class TE, class KF >
void BSTree<TE,KF> :: insertSub ( BSTreeNode<TE,KF> *&p, const TE &newElement )

//Recursive partner of function insert

{
	if(p)
	{
		if(p->element.key() == newElement.key() )
		{
			BSTreeNode<TE,KF> *tmp = new BSTreeNode<TE,KF> ( newElement, p->left, p->right);
			delete p;
			p = tmp;
		}

		else if ( p->element.key() > newElement.key() )
			insertSub ( p->left, newElement );

		else
			insertSub ( p->right, newElement );
	}

	else
	{
		p = new BSTreeNode<TE,KF> ( newElement, NULL, NULL );
	}
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF> :: retrieve ( KF searchKey, TE &searchElement ) 

//Searches a binary search tree for the element with key searchKey. If
//this element is found, then copies the element to searchElement,and returns 1.
//Otherwise, returns 0 with searchElement undefined.

{
	return retrieveSub ( searchKey, searchElement, root );
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template < class TE, class KF >
int BSTree<TE,KF> :: retrieveSub ( KF searchKey, TE &searchElement,
			                             BSTreeNode<TE,KF> *&p ) 

//Recursive partner of function retrieve

{
	if(p)
	{
		if( p -> element.key() == searchKey )
		{
			searchElement = p -> element;
			return 1;
		}

		else if ( p ->element.key() > searchKey )
			return retrieveSub ( searchKey, searchElement, p->left);

		else
			return retrieveSub ( searchKey, searchElement, p->right);
	}

	else
		return 0;
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF> :: remove ( KF deleteKey )

//Removes the element with dey deleteKey from a binary search tree.
//if this element is fournd, then deletes it from the tree and returns 1.
//Otherwise returns 0.

{
	return removeSub (deleteKey, root);
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template < class TE, class KF >
void BSTree<TE,KF> :: fixup ( BSTreeNode<TE,KF> *&p, 
							 BSTreeNode<TE,KF> *&del )

//Recursive partner of function remove(), which handles the typical 
//case that the node to be deleted has two children.

{
	if(p->left)
		fixup ( p->left, del);

	else
	{
		del -> element = p -> element;
		del = p;
		p = p -> right;
	}
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template < class TE, class KF >
int BSTree<TE,KF> :: removeSub ( KF deleteKey, BSTreeNode<TE,KF> *&p)

//Recursive partner of function remove

{
	if(p)
	{
		if(p->element.key() == deleteKey )
		{
			BSTreeNode<TE,KF> *del;
			if( p -> left == NULL )
			{
				del = p;
				p = p -> right;
			}

			else if( p -> right == NULL )
			{
				del = p;
				p = p -> left;
			}

			else
			{
				del = p;
				fixup ( p->right, del);
			}

			delete del;
			return 1;
		}

		else if( p->element.key() > deleteKey )
			return removeSub ( deleteKey, p -> left);

		else
			return removeSub ( deleteKey, p -> right);
	}

	else
		return 0;
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF> :: writeKeys ( ) 

//Outputs the keys of the elements in a binary tree. The keys are 
//output in ascending order, one per line.

{
	writeKeysSub ( root );
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template < class TE, class KF >
void BSTree<TE,KF> :: writeKeysSub ( BSTreeNode<TE,KF> *&p ) 

//recursive partner of function writeKeys()

{
	if(p)
	{
		writeKeysSub ( p -> left );
		cout << p->element.key() << endl;
		writeKeysSub ( p -> right );
	}
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF> :: clear ( ) 

//Removes all the elements in a binary search tree

{
	clearSub ( root );
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

template < class TE, class KF >
void BSTree<TE,KF> :: clearSub ( BSTreeNode<TE,KF> *&p )

//Recursive partner of function clear()

{
	if(p)
	{
		clearSub(p->left);
		clearSub(p->right);
		delete p;
		p = NULL;
	}
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF> :: empty ( void ) const

//Returns 1 if binary search tree is empty, otherwise returns 0.

{
	return ( root == NULL );
}

//--------------------------------------------------------------------

template < class TE, class KF >
int BSTree<TE,KF> :: full ( void ) const

//Returns 1 if binary search tree is full, otherwise returns 0.

{
	TE temp;
	BSTreeNode<TE,KF> *tmp = new BSTreeNode<TE,KF> ( temp, NULL, NULL );
	delete tmp;
	return ( tmp == NULL );
}

//--------------------------------------------------------------------

template < class TE, class KF >
void BSTree<TE,KF>:: showStructure () const

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.

{
    if ( root == 0 )
       cout << "Empty tree" << endl;
    else
    {
       cout << endl;
       showSub(root,1);
       cout << endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
void BSTree<TE,KF>:: showSub ( BSTreeNode<TE,KF> *p,
                               int level             ) const

// Recursive partner of the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the tree.

{
     int j;   // Loop counter

     if ( p != 0 )
     {
        showSub(p->right,level+1);         // Output right subtree
        for ( j = 0 ; j < level ; j++ )    // Tab over to level
            cout << "\t";
        cout << " " << p->element.key();   // Output key
        if ( ( p->left != 0 ) &&           // Output "connector"
             ( p->right != 0 ) )
           cout << "<";
        else if ( p->right != 0 )
           cout << "/";
        else if ( p->left != 0 )
           cout << "\\";
        cout << endl;
        showSub(p->left,level+1);          // Output left subtree
    }
}

//------------------------IN LBA EXERCISE 2---------------------------

template < class TE, class KF >
int BSTree<TE,KF> :: height ( void ) const

//Returns the height of a binary search tree

{
	return heightSub ( root );
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
int BSTree<TE,KF> :: heightSub (  BSTreeNode<TE,KF> *p ) const

//Recursive partner of the function height()

{
	if(p)
	{
		int leftHight, rightHight;
		leftHight = heightSub ( p->left );
		rightHight = heightSub ( p->right );
		return ( leftHight > rightHight ? leftHight : rightHight ) +1;
	}

	else
		return 0;
}

//------------------------IN LBA EXERCISE 3---------------------------

template < class TE, class KF >
void BSTree<TE,KF> :: writeLessThan ( KF searchKey ) const

//Outputs the keys in a binary search tree that are less than searchKey.
//The keys are output in ascending order, one per line. The searchKey is
//not necessarily be in the tree.

{
	writeLessThanSub ( root, searchKey );
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class TE, class KF >
void BSTree<TE,KF> :: writeLessThanSub (  BSTreeNode<TE,KF> *p,
											KF searchKey ) const

//Recursive partner of the function writeLessThan()

{
	if(p)
	{
		if ( p->element.key() >= searchKey )
			writeLessThanSub ( p->left, searchKey );
		else
		{
			writeLessThanSub ( p -> left, searchKey );
			cout << p->element.key() << endl;
			writeLessThanSub ( p -> right, searchKey );
		}
	}
}
























