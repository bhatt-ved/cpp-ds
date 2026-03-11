//--------------------------------------------------------------------
//
//  Laboratory 10                                         test10.cpp
//
//  Test program for a set of recursive linked list functions
//
//--------------------------------------------------------------------

// Reads a list of characters and calls the specified recursive
// routine.

#include <iostream>
#include "listrec.cpp"

List<char> testList;   // Test list
char testElement;      // List element


int main()
{
	int option=100;
	void test1(void);
	void test2(void);
	void test3(void);
	void test4(void);
	void test5(void);
	void test6(void);
	void test7(void);
	void test8(void);
	void test9(void);
	void test10(void);
	void test11(void);
	void test12(void);


	while(option != 0)
	{
		cout << "TEST PROGRAM OPTIONS:\a\n\n";
		cout << "1   Pre-lab-1: write()\n"
			<< "2   Pre-lab-2: insertEnd()\n"
			<< "3   Pre-lab-3: writeMirror()\n"
			<< "4   Pre-lab-4: reverse()\n"
			<< "5   Pre-lab-5: deleteEnd()\n"
			<< "6   Pre-lab-6: length()\n"
			<< "7   Pre-lab-7: unknown1()\n"
			<< "8   Pre-lab-8: unknown2()\n"
			<< "9   In-lab-1A: iterReverse()\n"
			<< "10  In-lab-1B: stackWriteMirror()\n"
			<< "11  In-lab-2: aBeforeb()\n"
			<< "12  In-lab-3: cRemove()\n"
			<< "0   Quit\n";

		cout << "\nEnter option:";
		cin >> option;

		switch(option)
		{
		case 1:
			test1();
			break;

		case 2:
			test2();
			break;

		case 3:
			test3();
			break;

		case 4:
			test4();
			break;

		case 5:
			test5();
			break;

		case 6:
			test6();
			break;

		case 7:
			test7();
			break;

		case 8:
			test8();
			break;

		case 9:
			test9();
			break;

		case 10:
			test10();
			break;
		
		case 11:
			test11();
			break;

		case 12:
			test12();
			break;

		case 0:
			cout << "Quitting.....\n\n\n\n";
			break;

		default:
			cout << "\nInvalid option.\n";
			break;

		}

	}
    return 1;
}

void ipList()
{
	testList.clear();
    cout << endl << "Enter a list of characters : ";
	cin.get();
    cin.get(testElement);
    while ( testElement != '\n' )
    {
        testList.insert(testElement);
        cin.get(testElement);
    }
    testList.showStructure();
}

void test1()
{
	ipList();
 	cout << "\n\aTesting recursive function-1: write():\n\n\t";
	testList.write();
	cout << "\n\nHit Enter to continue";
	cin.get();
}

void test2()
{
	ipList();
	cout << "\n\aTesting recursive function-2: insertEnd() with parameter '!':\n";
	testList.insertEnd('!');
	testList.showStructure();
	cout << "Hit Enter to continue";
	cin.get();
}

void test3()
{
	ipList();
	cout << "\n\aTesting recursive function-3: writeMirror():\n\n\t";
	testList.writeMirror();
	cout << "\n\nHit Enter to continue";
	cin.get();
}

void test4()
{
	ipList();
	cout << "\n\aTesting recursive function-4: reverse():\n\n";
	testList.reverse();
	testList.showStructure();
	cout << "Hit Enter to continue";
	cin.get();
}

void test5()
{
	ipList();
	cout << "\n\aTesting recursive function-5: deleteEnd():\n\n";
	testList.deleteEnd();
	testList.showStructure();
	cout << "Hit Enter to continue";
	cin.get();
}

void test6()
{
	ipList();
	cout << "\n\aTesting recursive function-6: length():\n\n\t";
	cout << "length = " <<  testList.length() << endl;
	cout << "\n\nHit Enter to continue";
	cin.get(); 
}

void test7()
{
	ipList();
	cout << "\nOutput of unknown1() function:   ";
    testList.unknown1();
	testList.showStructure();
	cout << "\n\nHit Enter to continue:";
	cin.get();
}

void test8()
{
	ipList();
	cout << "\nOutput of unknown2() function:\n";
    testList.unknown2();
	testList.showStructure();
	cout << "\n\nHit Enter to continue:";
	cin.get();
}

void test9()
{
	ipList();
	cout << "\nOutput of iterReverse() function:\n";
    testList.iterReverse();
	testList.showStructure();
	cout << "\n\nHit Enter to continue:";
	cin.get();
}

void test10()
{
	ipList();
	cout << "\nOutput of stackWriteMirror() function:\n";
    testList.stackWriteMirror();
	testList.showStructure();
	cout << "\n\nHit Enter to continue:";
	cin.get();
}

void test11()
{
	ipList();
	cout << "\nOutput of aBeforeb() function:\n";
    testList.aBeforeb();
	testList.showStructure();
	cout << "\n\nHit Enter to continue:";
	cin.get();
}

void test12()
{
	ipList();
	cout << "\nOutput of cRemove() function:\n";
    testList.cRemove();
	testList.showStructure();
	cout << "\n\nHit Enter to continue:";
	cin.get();
}
