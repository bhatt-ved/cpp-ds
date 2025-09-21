//--------------------------------------------------------------------
//
//  Laboratory 6, In-lab Exercise 1                      InLab1.cpp
//
//  Store simulation program
//
//--------------------------------------------------------------------

// Simulates the flow of customers through a line in a store.

const RAND_MAX = 4;

#include <iostream.h>
#include <iomanip.h>
#include <time.h>
#include "queuelnk.cpp"

void main ()
{
    Queue<int> custQ;      // Line (queue) of customers containing the
                           //   time that each customer arrived and
                           //   joined the line
    int simLength,         // Length of simulation (minutes)
        minute,            // Current minute
        timeArrived,       // Time dequeued customer arrived
        waitTime,          // How long dequeued customer waited
        totalServed = 0,   // Total customers served
        totalWait   = 0,   // Total waiting time
        maxWait     = 0,   // Longest wait
        numArrivals = 0;   // Number of new arrivals

	srand( (unsigned)time( NULL ) );

    cout << endl
         << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    for ( minute = 0 ; minute < simLength ; minute++ )
    {

		// Dequeues the first customer in line (if any).

		if(!custQ.empty())
		{
			timeArrived = custQ.dequeue();
			
			waitTime = minute - timeArrived;

			totalServed++;
			totalWait += waitTime;
		
			maxWait = (waitTime > maxWait) ? waitTime : maxWait;
		
		}
		
       //The number of new customers added to the line.

		int rndno = rand() % 4;

		switch(rndno)
		{
		case 0:
			custQ.enqueue(minute);
			break;

		case 1:
			custQ.enqueue(minute);
			custQ.enqueue(minute);
			break;
		
		case 2: case 3:
			break;
		}
    }

    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;
}