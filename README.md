# Bounded Queue KPCB

Developed by Nii Mante [@nmante](http://www.github.com/nmante)

## <a href="#instructions">1. Usage Instructions</a>
## <a href="#prob_statement">2. Problem Statement</a>

## <a href="#solution">3. My Solution</a>
## <a href="#complexity">4. Algorithmic Complexity</a>

## <div id="instructions">Usage Instructions</div>

### Details
- Implementation Language - C++
- Compiler version - g++ 4.2.1
- No external libraries used

### Compilation instructions
run `make` from the top level directory (KPCB) to compile the executable

	KPCB
	|- Makefile
	|  README.md
	|- src/
	|  |- *.cpp
	|- inc/
	|  |- *.hpp
	|- bin/
	|  |- *.o
	
### How to run the program
The executable is named `NiiQueueKPCB`. Run this command from the command line to use it

	./NiiQueueKPCB

### Output
The program will output the results from a set of Unit Tests which test the enqueue and dequeue functions.
	

## <div id="prob_statement">Problem Statement</div>
Using only primitive types, implement a bounded queue to store integers. The data structure should be optimized for algorithmic runtime, memory usage, and memory throughput. No external libraries should be imported and/or used. The solution should be delivered in one class that provides the following functions:

***Constructor***: class should provide one method for object creation that takes an integer to set the size of the queue.

***Enqueue***: function should take an integer and store it in the queue if the queue isn't full. The function should properly handle the case where the queue is already full.

***Dequeue***: function should return an integer if one is currently stored in the queue. The function should properly handle the case where the queue is empty.


### Instructions
Please provide 
- the source
- tests 
- runnable command-line function 
- all the resources required to compile (if necessary) and run the following program. 

You are free to use any coding language that compiles/runs on *nix operating systems and requires no licensed software.

## <div id="solution">My Solution</div>

### Limitations

- Primitive Data types
	- Assuming no custom node class (i.e. struct node or something like that)
	- Must use only int, char, etc. 
	- Can't use Linked Lists... because that would require creation of custom data type (node/element) which is NOT primitive Data type

- Bounded queue
- No external libraries

### How I'll tackle it

#### One option

It is possible to implement the Bounded Queue with a linked list, but we are restricted to primitive data types.  If I we're to use a linked list implementation though, I would create a custom data structure for the list.

	typedef struct Element{
		Element *next;
		int data;
	}Element;
	
Then I would use composition:

	class Queue {
	private:
		Element *queue;
	public:
		//enqueue, dequeue, etc.
	}
	
#### The Final Solution - array encapsulated by Queue class

I will create a ***Queue*** class which contains a Integer array as a private member:

	class Queue{
	private:
		int *array;
		//other variables
	public:
		//enqueue, dequeue, etc.
	}

***Note:*** I am allocating the array dynamically, but this is not the same as the standard 'Dynamic Array'.  This is simply because we have no need to resize the array; we have been asked to solve a *bounded* queue.  

Additionally, we could make this a template class and then pass in the type of data we want, but I've left that out because the problem is constrained to integer data. For the curious, I would build it like so:

	template <class T>
	class Queue{
	private:
		T *array;
		//other vars
	public: 
		//enqueue, dequeue, etc.
	}

	
## <div id="complexity">Algorithmic Complexity</div>

With my current implementation, the algorithmic complexities will be as follows:

	Enqueue O(1)
	Dequeue O(n) //Delete first element with random access [ O(1) ], but must traverse to shift every element forward [ O(n) ]
	

	










		
