//--------------------------------------------------------------------
//
//                       inlab.cpp
//	Program with data file interface.
//
//--------------------------------------------------------------------

#include <stdio.h>
#include <iostream.h>
#include <iomanip.h>
#include <process.h>    //For exit() function
#include "logbook.CPP"

int main(void)
{
	FILE *fp;
	Logbook mylog(20);

	fp=fopen("values.dat","r+");   // Format of the file: <int-day>,<int-value>; example: 1,675   You will have 20 such entries in the file

	if(fp==NULL)
	{
		cout << "\nCan not open file.\n\n\n";
		exit(0);
	}

	// TODO:  Read from the file, populate mylog, and then display its content

	return 0;
}