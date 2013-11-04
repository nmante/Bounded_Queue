#include <iostream>
#include "TestSuite.hpp"
#include "Queue.hpp"

/*

	I have encapsulated all of the testing inside the 
	TestSuite Class.

	The TestSuite checks for these boundary cases:
		- Proper enqueue
		- Proper dequeue
		- Enqueueing too many values
		- Dequeueing too many values
		- Creating a zero size queue and trying enqueue/dequeue
			- No inserts, or dequeues should break or increase
			size of array

*/

int main(int argc, char const *argv[])
{

	TestSuite testSuite;
	testSuite.runAllTests();

	return 0;
}