//--------------------------------------------------------------------
//
//  Laboratory 7                                           test7.cpp
//
//  Test program for the operations in the List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "listlnk.cpp"

using namespace std;

int main()
{
    List<char> testList(10);   // Test list
    char testElement;          // List element
    char cmd;                  // Input command
	inline void commands(void);	
 
	commands();
    do
    {
        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '='  ||  cmd == '#' )
           cin >> testElement;

        switch ( cmd )
        {
          case '+' :                                  // insert
               cout << "Insert " << testElement << endl;
               testList.insert(testElement);
               break;

          case '-' :                                  // remove
               cout << "Remove the element marked by the cursor"
                    << endl;
               testList.remove();
               break;

          case '=' :                                  // replace
               cout << "Replace the element marked by the cursor "
                    << "with " << testElement << endl;
               testList.replace(testElement);
               break;

          case '@' :                                  // getCursor
               cout << "Element marked by the cursor is "
                    << testList.getCursor() << endl;
               break;

          case '<' :                                  // gotoBeginning
               if ( testList.gotoBeginning() )
                  cout << "Go to the beginning of the list" << endl;
               else
                  cout << "Failed -- list is empty" << endl;
               break;

          case '>' :                                  // gotoEnd
               if ( testList.gotoEnd() )
                  cout << "Go to the end of the list" << endl;
               else
                  cout << "Failed -- list is empty" << endl;
               break;

          case 'N' : case 'n' :                       // gotoNext
               if ( testList.gotoNext() )
                  cout << "Go to the next element" << endl;
               else
                  cout << "Failed -- either at the end of the list "
                       << "or the list is empty" << endl;
               break;

          case 'P' : case 'p' :                       // gotoPrior
               if ( testList.gotoPrior() )
                  cout << "Go to the prior element" << endl;
               else
                  cout << "Failed -- either at the beginning of the "
                       << "list or the list is empty" << endl;
               break;

          case 'C' : case 'c' :                       // clear
               cout << "Clear the list" << endl;
               testList.clear();
               break;

          case 'E' : case 'e' :                       // empty
               if ( testList.empty() )
                  cout << "List is empty" << endl;
               else
                  cout << "List is NOT empty" << endl;
               break;

          case 'F' : case 'f' :                       // full
               if ( testList.full() )
                  cout << "List is full" << endl;
               else
                  cout << "List is NOT full" << endl;
               break;

		  case 'S': case 's':
				testList.showStructure();
				break;			    

		  case 'H': case 'h':
			   commands();
			   break;

          case 'M' : case 'm' :                   // In-lab Exercise 2
               cout << "Move the element marked by the cursor to the "
                    << "beginning of the list" << endl;
               testList.moveToBeginning();
               break;

          case '#' :                              // In-lab Exercise 3
               cout << "Insert " << testElement << " before the "
                    << "cursor" << endl;
               testList.insertBefore(testElement);
               break;  

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }
		testList.showStructure();
    }
    while ( cmd != 'Q'  &&  cmd != 'q' );
    return 1;
}

void commands(void)
{
    cout << "  +x  : Insert x after the cursor" << endl;
    cout << "  -   : Remove the element marked by the cursor" << endl;
    cout << "  =x  : Replace the element marked by the cursor with x"
         << endl;
    cout << "  @   : Display the element marked by the cursor" << endl;
    cout << "  <   : Go to the beginning of the list" << endl;
    cout << "  >   : Go to the end of the list" << endl;
    cout << "  N   : Go to the next element" << endl;
    cout << "  P   : Go to the prior element" << endl;
    cout << "  C   : Clear the list" << endl;
    cout << "  E   : Empty list?" << endl;
    cout << "  F   : Full list?" << endl;
	cout << "  S   : Show structure of the List" << endl;
    cout << "  M   : Move element marked by cursor to beginning  "<< endl;
    cout << "  #x  : Insert x before the cursor " << endl;
    cout << "  Q   : Quit the test program" << endl;
	cout << "  H   : Show this list of commands" << endl;
	 
    cout << endl;
}
