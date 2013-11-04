#ifndef _TESTSUITE_HPP_
#define _TESTSUITE_HPP_ 

/* 
	Nii Mante
	KPCB Interview Question
	Test Suite Header file
	
	Explanation:
	Each testFunction returns a bool value (excluding runAllTests()).

	A test which passes returns 'true', and a test which fails returns 'false'.

	Example: (Enqueue Too Many)
		Create a queue of size 1.
		Enqueue 2, returns true
		Enqueue 3, returns false //i.e. enqueue failed because array too small
		The expected return value for the test is 'false'
		if retVal == false 
			then the Test PASSES

	This is the logic for all test cases.
	If the expected returnValue is correct (could be true or false) then the Test PASSES

*/

#include <string>

class TestSuite
{
private:
	int numberOfTests;
	int numberOfTestsPassed;
	void printResult(std::string & testName, bool testReturnValue);
public:
	TestSuite();
	~TestSuite();

	/*
		run()

		Run all of the tests in the suite
		Check the retVal of each test
		Print the test PASSED if the result of a test is true
		FAILED if the result of the test is false
	*/

	void runAllTests();

	/* 
		Try to insert 'value' to 'back' of the queue
		Confirm that inserting works
	*/
	bool enqueueTest();

	/*
		Try to insert remove from 'front' of queue
	*/

	bool dequeueTest();
	/*
		Create an queue of size 'n'
		Try to insert n+1 elements
	*/
	bool enqueueTooManyTest(int n);


	/*
		Try to remove too many elements from a queue
		of 'n' elements
	*/

	bool dequeueTooManyTest(int n);

	/*
		Create a queue of size zero. Try enqueing and dequeuing
		to see if any errors/segfaults happen.
	*/

	bool zeroSizeQueueTest();
};

#endif //_TESTSUITE_HPP_
