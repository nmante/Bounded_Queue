#include "TestSuite.hpp"
#include "Queue.hpp"
#include <iostream>
#include <string>

using namespace std;

TestSuite::TestSuite(): numberOfTests(0), numberOfTestsPassed(0)
{}
TestSuite::~TestSuite(){}

void TestSuite::runAllTests(){

	/*
		Delimit the starting point of the test suite
	*/

	std::cout << "======================================================" << std::endl;
	std::cout << "Bounded Queue Test Suite" << std::endl;
	std::cout << "======================================================" << std::endl;
	
	/*
		run the tests, and pass the parameters to the printResult function
	*/

	std::string testString = "Simple Enqueue Test";
	printResult(testString, enqueueTest());

	testString = "Simple Dequeue Test";
	printResult(testString, dequeueTest());


	testString = "Enqueue Too Many Test";
	printResult(testString, enqueueTooManyTest(10));


	testString = "Dequeue Too Many Test";
	printResult(testString, dequeueTooManyTest(4));

	testString = "Create queue of size 0";
	printResult(testString, zeroSizeQueueTest());


	std::cout << "========== Final Results =============" << std::endl;
	std::cout << std::endl;
	/*
		Print the number of tests that passed (out of total)
	*/

	std::cout <<  "******** " << numberOfTestsPassed << "/" << numberOfTests << " TESTS PASSED" <<  " ********" << std::endl;

	std::cout << "======================================================" << std::endl;
	std::cout << "End Bounded Queue Test Suite" << std::endl;
	std::cout << "======================================================" << std::endl;

}

void TestSuite::printResult(std::string & testName, bool testRetVal){
	/*
		Print the test number, test name, pass fail 
		pass in ref to number, pass in name, pass in bool
	*/


	std::string testOutputString = testRetVal ? " |PASSED|" : " |FAILED|";
	testRetVal ? numberOfTestsPassed++ : numberOfTestsPassed;

	cout << endl;

	cout << ++numberOfTests << ") " << testName << testOutputString << endl;
	cout << endl;

}

bool TestSuite::enqueueTest(){
	
	/*
		Insert a few values, and update the boolean retVal
		each time.  If we return false at any point, the test
		has failed.	
	*/

	std::cout << "Enqueue Test" << std::endl;
	std::cout << "------------" << std::endl;

	int size = 4;

	Queue queue1(size);
	std::cout << "Create queue of size " << size << std::endl;

	bool retVal = queue1.enqueue(1);
	std::cout << "Inserting " << 1 << " into queue" << std::endl;
	
	retVal = queue1.enqueue(4) && retVal;
	std::cout << "Inserting " << 4 << " into queue" << std::endl;

	std::cout << "Contents of the Queue after insert(s)" << std::endl;

	std::cout << queue1 << std::endl;

	return retVal;
}


bool TestSuite::dequeueTest(){

	/*
		Insert two values
		Dequeue both of them.
		Check that the last one you inserted, is equal to the last
		one you dequeued
	*/

	std::cout << "Dequeue Test" << std::endl;
	std::cout << "------------" << std::endl;
	int dequeueValue; // The variable to hold our dequeued value
	bool retVal;
	
	std::cout << "Creating queue of size 3" << endl;
	Queue queue(3);
	
	std::cout << "Inserting 1, then 3" << endl;
	
	retVal = queue.enqueue(1);
	retVal = queue.enqueue(3);

	std::cout << "Queue after inserts " << endl;
	std::cout << queue << endl;

	retVal = queue.dequeue(dequeueValue);
	
	std::cout << "Queue after remove " << endl;
	std::cout << queue << endl;

	retVal = queue.dequeue(dequeueValue) && retVal;
	
	std::cout << "Queue after remove " << endl;
	std::cout << queue << endl;

	retVal = retVal && ((dequeueValue == 3) ? true : false);

	return retVal;
}

bool TestSuite::enqueueTooManyTest(int n){
	std::cout << "Enqueue Too Many Test" << std::endl;
	std::cout << "---------------------" << std::endl;

	int dequeueValue;
	bool returnValue;
	Queue queue(n);
	/*
		Insert one too many values.  

		Expected returnValue == false
	*/
	for (int i = 0; i < n + 2; ++i)
	{
		returnValue = queue.enqueue(i);
		std::cout << "Inserted ";
		if (returnValue)
		{
			std::cout << i << std::endl;	
		}else{
			std::cout << "(None)" << std::endl;
		}
	}

	return !returnValue;
}

bool TestSuite::dequeueTooManyTest(int n){
	std::cout << "Dequeue Too Many Test" << std::endl;
	std::cout << "---------------------" << std::endl;

	int dequeueValue;
	bool returnValue;
	Queue queue(n);

	std::cout << "Queue before inserts " << std::endl;
	std::cout << queue << std::endl;

	/*
		Insert n elements 
	*/
	for (int i = 0; i < n; ++i)
	{
		returnValue = queue.enqueue(i);	
		std::cout << "Inserted " << i << std::endl;
	}

	std::cout << "Queue after inserts " << std::endl;
	std::cout << queue << std::endl;

	/*
		Remove n+1 elements
	*/
	for (int i = 0; i < n + 1; ++i) 
	{
		returnValue = queue.dequeue(dequeueValue);
		std::cout << "Removed ";
		if (returnValue)
		{
			std::cout << dequeueValue << std::endl;	
		}else{
			std::cout << "(None)" << std::endl;
		}
	}

	std::cout << "Queue after removes " << std::endl;
	std::cout << queue << std::endl;


	return !returnValue;

}


bool TestSuite::zeroSizeQueueTest(){

	std::cout << "Zero size queue test" << std::endl; 
	std::cout << "--------------------" << std::endl;
	//Create queue of size zero
	Queue queue(0);
	int dequeueValue;
	//Try enqueue
	bool retVal = queue.enqueue(1);

	/*
		Try dequeue, and '||' it with prev value
		A final retVal of 'false' symbolizes the a positive result
	*/
	retVal = queue.dequeue(dequeueValue) || retVal;

	return !retVal;

}





