//--------------------------------------------------------------------
//
//                       testOperatorOverload.cpp
//	Laboratory 1, CS-401-054
//	Test program for Logbook ADT's += operator overloading
//
//--------------------------------------------------------------------

#include <iostream>
#include <cstdlib>      // For rand() and srand()
#include <ctime>   // For time()
#include "LOGBOOK.H"

using namespace std;

int main(void)
{
	int m,y;
    char c;
	
	cout << "Enter Month and Year, of which first logbook is to be created :";
	cin >> m >> y;

	Logbook log1(m,y);

	cout << "Enter Month and Year, of which second logbook is to be created :";
	cin >> m >> y;

	Logbook log2(m,y);

    cout << "Entering random entries for all days....\n";
    cout << "Press any key to display current values....\n";
    cin >> c;

    srand(time(0)); // Seed the random number generator

    int min_val = 1;
    int max_val = 49;
    int random_num;

    for (int i = 1; i <= log1.daysInMonth(); i++) {
        // Generate a random number between min_val and max_val (inclusive)
        random_num = (rand() % (max_val - min_val + 1)) + min_val;
        log1.putentry(i, random_num);
    }
    for (int i = 1; i <= log2.daysInMonth(); i++) {
        random_num = (rand() % (max_val - min_val + 1)) + min_val;
        log2.putentry(i, random_num);
    }

    log1.dsply();
    log2.dsply();

    cout << "\n\nNow, will add second log to first one and display the result...\n";
    cout << "Press any key to display current values....\n";
    cin >> c;

    log1 += log2;
    log1.dsply();

    return 0;
}
