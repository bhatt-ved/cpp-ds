//--------------------------------------------------------------------
//
//  Laboratory 9                                           InLab1.cpp
//
//  This program demonstrates computer network packet arrangement simulation.
//
//--------------------------------------------------------------------

#include "Listord.cpp"
#include <fstream.h>
#include <string.h>

const int packetSize = 6; //Maximum size 5 + one space for '\0'

struct Packet
{
	int position;	      //Packet's position in message
	char body[packetSize];//Characters in packet

	int key() const
	{  return position; } //Returns the key field
};

int main()
{
	char option;
	OrdList<Packet,int> list;
	Packet data;
	char file[30];

	cout << "Default input file is \"message.dat\".\n";
	cout << "Do you want to open any other file?[Y/N]:";

	cin >> option; 
	cin.get();
	if(option == 'y' || option == 'Y')
	{
		cout << "Enter alternative file name : ";
		cin.getline(file,30);
	}

	else
		strcpy (file, "message.dat");

	ifstream inFile ( file, ios::nocreate);
	if(!inFile)
		cout << "Error opening file!";
	else
	{
		cout << "\nOpening data file  ";
		while(inFile)
		{
			inFile >> data.position;
			for(int i=0; i< 5; i++)
				inFile.get(data.body[i]);
			inFile.get();
			list.insert(data);
			cout << ".";
		}
		cout << "  done\n\n\n";

		inFile.close();

		if(list.gotoBeginning())
		{
			do
			{
				data = list.getCursor();
				for(int i=0; i< packetSize-1 ; i++)
					cout << data.body[i];
			}while(list.gotoNext());
		}

		else
			cout << "Message not received.";
	}

	cout << "\n\n\a";

	return 1;
}


	    



		

	




