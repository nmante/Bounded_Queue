#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>

class TestSuite;

class Queue
{
private:

	/* The size of the bounded queue */
	int size; 
	
	/* 
		Keeps track of the back of the queue (i.e. where/if we can insert) 
		Initially 0
	*/
	int currentIndex;

	/* The dynamic array in which we store our elements */
	int *array;
public:
	/*
		Ctor

		Takes in an integer (size) and creates a bounded queue of
		this size
	*/
	Queue(int size);

	/*
		Dtor 

		A destructor wasn't mentioned in the description,
		but it is necessary to handle deletion of our 
		dynamic array to avoid memory leaks
	*/
	~Queue();

	/*
		enqueue:
		Add an integer to the back of our queue.

		If there's space at 'back' of queue
			put in element at 'currentIndex'
			increment currentIndex
		Else
			cant insert
	*/

	bool enqueue(int value);

	/*
		dequeue:

		If 'front' of queue is not empty
			pop off element
			update 'returnValue'
			return true
		else
			return false
	*/

	bool dequeue(int & returnValue);

	/*
		Make TestSuite a Friend class.
		This way, TestSuite can have access to the private
		members of Queue like the array, currentIndex and size
	*/
	friend class TestSuite;


	/* Helper method for printing the Queue to Standard Output */

	friend std::ostream & operator << (std::ostream & out, const Queue & q);

};

#endif // _QUEUE_HPP_