#include "Queue.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

Queue::Queue(int size): size(size), currentIndex(0)
{
	/*
		Construct our dynamic array
		The queue will use this to store it's elements
	*/
	array = new int[size];
}

Queue::~Queue(){
	/*
		Delete the array that was dynamically allocated 
		when we created the queue
	*/
	delete [] array;
	/*
		Assure we're not pointing at garbage memory and
		NULL/0 it
	*/
	array = 0;
}


bool Queue::enqueue(int value){
	// Check if we're within the bounds of the Queue
	if (currentIndex < size)
	{
		array[currentIndex] = value;
		currentIndex++;
		return true;
	}

	return false;
}


bool Queue::dequeue(int & returnValue){
	// Check if at least 1 value has been entered
	if (currentIndex > 0)
	{
		returnValue = array[0];

		/*
			Traverse the array and shift each element forward
		*/

		for (int i = 0; i < size - 1; ++i)
		{
			array[i] = array[i+1];
		}
		currentIndex--;
		return true;
	}

	else return false;
}


std::ostream & operator << (std::ostream & out, const Queue & q){
	/* 
		Iterate through the array and append the output to a stream operator
	*/
	for (int i = 0; i < q.currentIndex; ++i)
	{
		out << q.array[i] << " ";
	}
	out << (q.currentIndex == 0 ? "(EMPTY)" : "");
	return out;
}

