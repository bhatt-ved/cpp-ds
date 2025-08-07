//-------------------------------------------------------------------
//
//  Laboratory 1, CS-401                              logbook.cpp
//  Declaration of class Logbook for logbook ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include "LOGBOOK.H"

using namespace std;

//--------------------------------------------------------------------

Logbook :: Logbook(int month, int year) 

//Constructor. Allocates enough memory for the object.

{
    if((month<1)||(month>12)||(year<0)||(year>100000))
    {
        cout << "Invalid month or year.\n\n\n\n\n\n\n";
        exit(1);
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
    validateDay(day);    
    entry[day - 1] = value;
}

//--------------------------------------------------------------------

int Logbook :: getentry(int day) const

//Returns the entry of the logbook specified by the 'day'. Returns 0
//for invalid day.

{
    validateDay(day);
    return entry[day - 1];
}

//--------------------------------------------------------------------

void Logbook :: validateDay(int day) const

//If day is outside of valid days, exits program


{
    if (day < 1)
    {
        cout << "Invalid day. \n\n\n\n\n\n\n\n";
        exit(1);
    }
    
    if (day > daysInMonth()){
        cout << "Invalid day. \n\n\n\n\n\n\n\n";
        exit(1);
    }
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
    return logMonth;
}

//--------------------------------------------------------------------

int Logbook :: year() const

//Returns the current year of the logbook.

{
    return logYear;
}

//--------------------------------------------------------------------

int Logbook :: daysInMonth() const

//Returns the maximum days in the given month. Takes care for leap year

{

    switch(logMonth) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return (28 + lflag);
        default:
            return 31;
    }
}
//-----------------------------------------------&---------------------

void Logbook :: leapyear() 

//Sets the lflag if current year is leap year otherwise lefts if reset.

{
    if ((logYear % 4) == 0){
        if ((logYear % 100) == 0) {
            if ((logYear % 400) == 0)
                lflag = 1;
            else
                lflag = 0;
        }
        else
            lflag = 1;
    } else
        lflag = 0;
}

//--------------------------------------------------------------------

void Logbook :: operator += (const Logbook &rightLogbook)

//Operator overloading. Adds the entries of two logbooks. If LHS 
//logbook has fewer days than RHS, make number of days of LHS = RHS.
{
    if (rightLogbook.daysInMonth() > daysInMonth()) {
        logMonth = rightLogbook.logMonth;
        logYear = rightLogbook.logYear;
    }

    for (int i = 0; i < sizeof(entry)/sizeof(int); i++)
        entry[i] += rightLogbook.entry[i];
}

