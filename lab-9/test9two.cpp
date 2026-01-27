//--------------------------------------------------------------------
//
//  Laboratory 9, In-lab Exercises 2                   test9two.cpp
//
//  Test program for the operations in the Ordered List ADT that
//  manipulate two lists.
//
//--------------------------------------------------------------------

#include <iostream.h>
#include "listord.cpp"

//--------------------------------------------------------------------

class TestData
{
  public:

    void setKey ( char newKey )
        { keyField = newKey; }   // Set the key

    char key () const
        { return keyField; }     // Returns the key

  private:

     char keyField;              // Key for the element
};

//--------------------------------------------------------------------

void main()
{
    OrdList<TestData,char> testList1(8),  // Test lists
                           testList2(8);
    TestData testElement;                 // List element
    char ch;                              // Input character

    cout << endl << "Enter first list of characters (no spaces) : ";
    cin.get(ch);
    while ( ch != '\n' )
    {
        testElement.setKey(ch);
        testList1.insert(testElement);
        cin.get(ch);
    }

    cout << endl << "Enter second list of characters (no spaces) : ";
    cin.get(ch);
    while ( ch != '\n' )
    {
        testElement.setKey(ch);
        testList2.insert(testElement);
        cin.get(ch);
    }

    cout << endl << "List 1 : " << endl;
    testList1.showStructure();
    cout << endl << "List 2 : " << endl;
    testList2.showStructure();

  // Merge list 2 into list 1.
  testList1.merge(testList2);
  cout << endl << "After merge -- List 1 : " << endl;
  testList1.showStructure();

//S  // Check whether list 2 is a subset of list 1.
//S  cout << endl;
//S  if ( testList1.subset(testList2) )
//S     cout << "List 2 is a subset of list 1" << endl;
//S  else
//S     cout << "List 2 is NOT a subset of list 1" << endl;

}