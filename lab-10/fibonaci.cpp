#include <iostream.h>
int counter = 0;

int main()
{
	int n;
	int fibo (int n);
	int iterFibo (int n);

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
			cout << "Position should be any positive integer\n";

	}while(n);

	return 0;
}

int fibo(int n)
{
	
	cout << ++counter << ". Calling myself\n";
	if(n==1 || n==2)
		return 1;

	else
		return (fibo(n-1) + fibo(n-2));
}

int iterFibo(int n)
{
	int i=1,j=1,k;
	counter = 0;

	if(n==1 || n==2)
		k = 1;

	else
	{
		for(;n!=2;n--)
		{
			cout << ++counter << ".Executing loop\n";
			k = i + j;
			i = j;
			j = k;
		}
	}
	
	return k;
}
	


