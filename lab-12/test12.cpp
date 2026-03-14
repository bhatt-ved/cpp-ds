//--------------------------------------------------------------------
//
//  Laboratory 11                                         test11.cpp
//
//  Test program for the operations in the Binary Search Tree ADT
//
//
//--------------------------------------------------------------------

#include <iostream>
#include "bstree.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the binary search tree element class
//

class TestData
{
  public:

    void setKey ( int newKey )
        { keyField = newKey; }   // Set the key

    int key () const
        { return keyField; }     // Returns the key

  private:

    int keyField;                // Key for the element
};

//--------------------------------------------------------------------

int main()
{
    BSTree<TestData,int> testTree;   // Test binary search tree
    TestData testElement;            // Binary search tree element
    int inputKey;                    // User input key
    char cmd;                        // Input command
	void showHelp (void);			 // Function to show help

	showHelp();
    do
    {
        testTree.showStructure();                     // Output tree

        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '?'  ||
             cmd == '-'  ||  cmd == '<'     )
           cin >> inputKey;

        switch ( cmd )
        {
          case '+' :                                  // insert
               testElement.setKey(inputKey);
               cout << "Insert : key = " << testElement.key()
                    << endl;
               testTree.insert(testElement);
               break;

          case '?' :                                  // retrieve
			   if ( testTree.retrieve(inputKey,testElement) )
                  cout << "Retrieved : key = "
                       << testElement.key() << endl;
               else
                  cout << "Not found" << endl;
               break;

          case '-' :                                  // remove
               if ( testTree.remove(inputKey) )
                  cout << "Removed element" << endl;
               else
                  cout << "Not found" << endl;
               break;

          case 'K' : case 'k' :                       // writeKeys
               cout << "Keys:" << endl;
               testTree.writeKeys();
               break;

          case 'C' : case 'c' :                       // clear
               cout << "Clear the tree" << endl;
               testTree.clear();
               break;

          case 'E' : case 'e' :                       // empty
               if ( testTree.empty() )
                  cout << "Tree is empty" << endl;
               else
                  cout << "Tree is NOT empty" << endl;
               break;

          case 'F' : case 'f' :                       // full
               if ( testTree.full() )
                  cout << "Tree is full" << endl;
               else
                  cout << "Tree is NOT full" << endl;
               break;

          case 'L' : case 'l' :                   // height
               cout << "Tree height = " << testTree.height() << endl;
               break;

          case '<' :                              // less than keys
               cout << "Keys < " << inputKey << " : " << endl;
               testTree.writeLessThan(inputKey);
               cout << endl;
               break;

		  case 'H': case 'h':
			  showHelp();

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }
    }
    while ( ( cmd != 'Q' ) && ( cmd != 'q' ) );
    
    return 0;
}

void showHelp ( void )
{
    cout << endl << "Commands:" << endl;
    cout << "  +key : Insert (or update) element" << endl;
    cout << "  ?key : Retrieve element" << endl;
    cout << "  -key : Remove element" << endl;
    cout << "  K    : Write keys in ascending order" << endl;
    cout << "  C    : Clear the tree" << endl;
    cout << "  E    : Empty tree?" << endl;
    cout << "  F    : Full tree?" << endl;
    cout << "  H    : Help";
	cout << "  L    : Height of tree	(Inactive : "
         << "In-lab Exercise 2)" << endl;
    cout << "  <key : Write keys that are < key   (Inactive : "
         << "In-lab Exercise 3)" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}
