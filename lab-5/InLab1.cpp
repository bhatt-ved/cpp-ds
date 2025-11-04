//--------------------------------------------------------------------
//
//  Laboratory 5      In Lab # 1                          InLab1.cpp
//
//  Postfix Notation and Arithmatic using Stack ADT
//
//--------------------------------------------------------------------

#include "stacklnk.cpp"

//Uses atoi() function which is defined in stdlib.h; included in stackarr.cpp

int main()
{
	Stack <float> PostFix(20);		//Creates a stack of type char
	float operand1, operand2;
	char cmd;
	
	while(1)
	{

		cout << "Enter erithmatic expression in Postfix notation :\a\n"
			<< "Press E to indicate end of expression and A to abort the program\n>";

		do{
			cin >> cmd;
			switch(cmd)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				PostFix.push(float(cmd-'0'));
				break;

			case '+':
				// TODO - Implement
				break;

			case '-':
				// TODO - Implement
				break;
	
			case '*':
				// TODO - Implement
				break;

			case '/':
				// TODO - Implement
				break;

			case 'e': case 'E': 
				break;

			default:
				cout << "\nNot a valid digit or operator\n";
				break;

			case 'a': case 'A':
				cout << "\nThankyou for using PostFix.\n\n\n\n\t\t Good Bye ... \n\n\n\n";
				exit(0);

			}
		}while((cmd != 'e') && (cmd != 'E'));
		cout << "\nAnswer : " << PostFix.pop() << "\n";
	}
	return 0;

}
