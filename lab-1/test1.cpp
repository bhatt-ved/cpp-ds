//--------------------------------------------------------------------
//
//                               test1.cpp
//	Laboratory 1, CS-401-054
//	Test program for Logbook ADT
//
//--------------------------------------------------------------------

#include <iostream.h>
#include <iomanip.h>
#include <process.h>
#include "LOGBOOK.H"

void main(void)
{
	int m,y;
	int d,v;
	
	cout << "Enter Month and Year, of which logbook is to be created :";
	cin >> m >> y;

	Logbook mylog(m,y);

	int option;

	do{
		cout << endl << "You have followint options :\n";
		cout << "1. Put an entry to logbook\n"
			 << "2. Read an entry from logbook\n"
			 << "3. Display logbook as a calander\n"
			 << "0. Exit\n";
		cout << "Enter an appropriate option :";
		cin >> option;

		switch (option)
		{
		case 1 :
			cout << "Enter day and value :";
			cin >> d >> v;
			mylog.putentry(d,v);
			break;
		case 2 :
			cout << "Enter day :";
			cin >> d;
			cout << "Year :" << mylog.year() << endl
				 << "Month :" << mylog.month() << endl
				 << "Entry of the Day " << d << " is :" << mylog.getentry(d) << endl;
			break;
		case 3 :
			mylog.dsply();
			break;
		case 0 :
			break;
		}
	}while(option);
}

