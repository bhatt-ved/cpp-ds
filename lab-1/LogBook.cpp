//-------------------------------------------------------------------
//
//	Laboratory 1, CS-401	                          logbook.cpp
//	Declaration of class Logbook for logbook ADT
//
//--------------------------------------------------------------------

#include "logbook.h"

//--------------------------------------------------------------------

Logbook :: Logbook(int month, int year=1998)		//Default year

//Constructor. Allocates enough memory for the object.

{
	if((month<1)||(month>12)||(year<1900)||(year>2150))
	{
		cout << "Invalid month or year.\nAccess denied\n\n\n\n\n\n";
		exit(0);
	}

	logMonth = month;
	logYear = year;
	for(int i=0; i<31; i++)
		entry[i]=0;
	leapyear();
}

//--------------------------------------------------------------------

void Logbook :: putentry(int day, int value)

//Puts the entry in the the day of the month specified by the day.

{

}

//--------------------------------------------------------------------

int Logbook :: getentry(int day) const

//Returns the entry of the logbook specified by the 'day'. Returns 0
//for invalid day.

{

}

//--------------------------------------------------------------------

void Logbook :: dsply(void)

//Displays the logbook.

{
	cout << endl << endl;
	cout <<"\t\t\t"<< logMonth; 
	cout<< " / " << logYear << endl;
	int days = daysInMonth();
	cout << endl<<"---------------------------------------------------------------\n|";
	for(int i=0; i < days; i++)
	{
		int j;
		j=i+1;
		cout << setw(2) << j << setw(4) << entry[i] << " | ";
		
		if(!(j % 7))
			cout << endl<<"---------------------------------------------------------------\n|";
	}
}

//--------------------------------------------------------------------

int Logbook :: month() const

//Returns the current month of the logbook

{

}

//--------------------------------------------------------------------

int Logbook :: year() const

//Returns the current year of the logbook.

{

}

//--------------------------------------------------------------------

int Logbook :: daysInMonth() const

//Returns the maximum days in the given month. Takes care for leap year

{

}

//--------------------------------------------------------------------

void Logbook :: leapyear() 

//Sets the lflag if current year is leap year otherwise lefts if reset.

{

}

//--------------------------------------------------------------------

void Logbook :: operator += (const Logbook &rightLogbook)

//Operator overloading. Adds the entries of two logbooks, if the number
//of right-side month is less than or equal to the left-side month.
//Prompts error and does nothing with the left-side logbook otherwise.

{

}

