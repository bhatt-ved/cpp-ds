#include <iostream>
#include <stdlib>
#include <time.h>
#include "listarr.h"

//--------------------------------------------------------------------
//
//  Function prototype
//

void countBases ( List<char> &dnaSequence,
                  int &aCount,
                  int &cCount,
                  int &tCount,
                  int &gCount              );

//--------------------------------------------------------------------


void main ()
{
    List<char> dnaSequence(1000);   // DNA sequence (1000 bases max.)
    int aCount,                   // Number of A's in the sequence
        cCount,                   // Number of C's in the sequence
        tCount,                   // Number of T's in the sequence
        gCount,	                	// Number of G's in the sequence
		rndno ;                    

	cout << "Randorm DNA sequence :\n";

	/* Seed the random-number generator with current time so that
     * the numbers will be different every time we run.        */
   
	srand( (unsigned)time( NULL ) );

	for(int i=0; i<1000; i++)
	{
		rndno = (rand() % 25) + 1;       //generates random number betn. 1-25

		//puts a,g,c or t on the bases of certain logic

		if(rndno % 7 == 0)
			dnaSequence.insert('t');

		else if(rndno % 5 == 0)
			dnaSequence.insert('c');

		else if(rndno % 3 == 0)
			dnaSequence.insert('g');

		else if(rndno % 2 == 0)
			dnaSequence.insert('a');

		else
			dnaSequence.insert('x');   //inserts invalid no. for 1,11,13,17,19,23
	}


    // Display the sequence.

    
	dnaSequence.showStructure();

	// Count the number of times that each base occurs.
      
    countBases(dnaSequence,aCount,cCount,tCount,gCount);

    // Output the totals.

    cout << "Number of A's : " << aCount << endl;
    cout << "Number of C's : " << cCount << endl;
    cout << "Number of T's : " << tCount << endl;
    cout << "Number of G's : " << gCount << endl;
	cout << "Number of total valid bases : " << aCount+cCount+tCount+gCount;
	cout << endl << endl;
	
	if(aCount != gCount)
		cout << "This is not a valid DNA sequence because #a != #g";
	if(tCount != cCount)
		cout << "\nThis is not a valid DNA sequence because #t != #c\n \n";
	if(aCount == gCount && tCount == cCount)
		cout << "Wow ! A valid DNA sequence through random generation !\n";


}

void countBases ( List<char> &dnaSequence,
                  int &aCount,
                  int &cCount,
                  int &tCount,
                  int &gCount              )

// Counts the number of times that each base (A, C, T, G) occurs in
// dnaSequence.

{
	// TODO -- Implement
}

template < class LE >
void List<LE>:: showDNAStructure () const
	
	{
    int j;   // Loop counter

    if ( size == 0 )
       cout << "Empty list" << endl;
    else
    {
		for(j=0; j<1000; j++)
		{
			if(!(j%200)) cout<<"\a";
			cout << element[j] << "\t";
		}
		cout << endl;	
	}
}

