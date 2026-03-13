#include <iostream>

using namespace std;

int counter = 0;

int main()
{
	unsigned long n;
	unsigned long fibo (unsigned long n);
	unsigned long iterFibo (unsigned long n);

	do
	{
		cout << "\nEnter the element position of Fibonacci series\a:";

		cin >> n;

		if(n>0)
		{
			cout << "Using recursive formula:\n\a";
			cout << "The answer is: " << fibo(n);
			cout << "\nSee the power of iterative formula:\n";
			cout << "The answer is: " << iterFibo(n);
		}

		else
			cout << "Position should be any integer\n";

	}while(n);

	return 0;
}

unsigned long fibo(unsigned long n)
{
	
	//cout << ++counter << ". Calling myself\n";
	counter ++;
    if(n==1 || n==2)
		return 1;

	else
		return (fibo(n-1) + fibo(n-2));
}

unsigned long iterFibo(unsigned long n)
{
	unsigned long i=1,j=1,k;
	counter = 0;

	if(n==1 || n==2)
		k = 1;

	else
	{
		for(;n!=2;n--)
		{
			//cout << ++counter << ".Executing loop\n";
			counter ++;
            k = i + j;
			i = j;
			j = k;
		}
	}
	
	return k;
}
	


