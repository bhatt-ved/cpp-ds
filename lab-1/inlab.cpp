//--------------------------------------------------------------------
//
//                       inlab.cpp
//	Program with data file interface.
//
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <process.h>    //For exit() function
#include "LOGBOOK.H"

using namespace std;

int main(void)
{
	FILE *fp;
	Logbook mylog(8, 2002);

	fp=fopen("values.dat","r+");   // Format of the file: <int-day>,<int-value>; example: 1,675   You will have 20 such entries in the file

	if(fp==NULL)
	{
		cout << "\nCan not open file.\n\n\n";
		exit(0);
	}

	//Read from the file, populate mylog, and then display its content
    
    int num1, num2;

    while ((fscanf(fp, "%d,%d", &num1, &num2)) == 2) {
        cout << num1 << num2 << endl;
        if ((num1 > 31) || (num1 < 1))
            cout << "Day(" << num1 << ") not in range\n";
        else
            mylog.putentry(num1, num2);
    }
    mylog.dsply();
        
	return 0;
}
