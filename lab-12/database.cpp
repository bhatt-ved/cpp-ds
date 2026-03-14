//--------------------------------------------------------------------
//
//  Laboratory 11, In-lab Exercise 1                       database.cpp
//
//  Indexed accounts database program
//
//--------------------------------------------------------------------

// Builds a binary search tree index for the account records in the
// text file accounts.dat.

#include <iostream>
#include <fstream>
#include "bstree.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declarations specifying the accounts database
//

const int nameLength      = 11;   // Maximum number of characters in
                                  //   a name
const long bytesPerRecord = 38;   // Number of bytes used to store
                                  //   each record in the accounts
                                  //   database file

struct AccountRecord
{
    int acctID;                   // Account identifier
    char firstName[nameLength],   // Name of account holder
         lastName[nameLength];
    double balance;               // Account balance
};

//--------------------------------------------------------------------
//
// Declaration specifying the database index
//

struct IndexEntry
{
    int acctID;              // (Key) Account identifier
    long recNum;             // Record number

    int key () const
        { return acctID; }   // Return key field
};

//--------------------------------------------------------------------

int main ()
{
    ifstream acctFile ("accounts.dat");   // Accounts database file
    AccountRecord acctRec;                // Account record
    BSTree<IndexEntry,int> index;         // Database index
    IndexEntry entry;                     // Index entry
    int searchID;                         // User input account ID
    long recNum=0;                        // Record number
	char option;						  // User's option to exit

    // Iterate through the database records. For each record, read the
    // account ID and add the (account ID, record number) pair to the
    // index.

	while(!acctFile.eof())
	{
		acctFile >> acctRec.acctID >> acctRec.firstName 
		         >> acctRec.lastName >> acctRec.balance; //read record
		acctFile.get();					//skip newline character
		
		entry.acctID = acctRec.acctID;	//sets appropreate fields of 
		entry.recNum = recNum++;		//				struct entry			

		index.insert ( entry );
	}

    // Output the account IDs in ascending order.

	index.writeKeys();

    // Clear the status flags for the database file.

    acctFile.clear();

    // Read an account ID from the keyboard and output the
    // corresponding record.

	do{
		cout << "Enter the account ID: >\a";
		cin >> searchID;
		
		if(index.retrieve ( searchID, entry))  //search operation in BST
		{									   //If found, get details 
			recNum = entry.recNum;			   // from database file
			acctFile.seekg( recNum * bytesPerRecord );
			acctFile >> acctRec.acctID >> acctRec.firstName  //read record
		             >> acctRec.lastName >> acctRec.balance; // from file

			cout << recNum << " : " << acctRec.acctID << " " 
				 << acctRec.firstName << " " << acctRec.lastName << " " 
				 << acctRec.balance << endl << endl;
		}

		else									//Otherwise prompt error
			cout << "Record not found\n\a";

		cout << "Do you want to continue?[Y/N]:";
		cin >> option;
	}while(option == 'y' || option == 'Y');

	cout << "Good Bye!\n\n\n";
	acctFile.close();
    
    return 1;
}
