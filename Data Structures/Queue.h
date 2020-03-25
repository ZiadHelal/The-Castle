
/*
This code was copied from "Data Abstraction & Problem Solving with C++,WALLS AND MIRRORS ,SIXTH EDITION"
*/

/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers, a frontPtr pointer for the front of the queue
and a backPtr pointer for the back of the queue.
Note that we have used  exception instead of assertions in function peekFront()*/


#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class T>
class Queue
{
private :
	
	Node<T>* backPtr;
	Node<T>* frontPtr;
public :
	Queue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue();
	/** @throw PrecondViolatedExcep if the queue is empty */
	T peekFront() const throw (PrecondViolatedExcep);
	~Queue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <class T>
Queue<T>::Queue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <class T>
bool Queue<T>::isEmpty() const
{
	if(frontPtr==nullptr)
		return true;
	else
		return false;
}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
Returns the front of this queue. That is, gets the item that was added earliest. The
operation does not change the queue.

Input: None.
Output: The front of the queue.
*/


template <class T>
T Queue<T>:: peekFront() const throw (PrecondViolatedExcep)
{
	if(isEmpty())
	{
		string message="peekFront() called with empty queue";
		throw (new PrecondViolatedExcep(message));
	}
	else
	{
		return frontPtr->getItem();
	}

}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <class T>
bool Queue<T>::enqueue( const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue was empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	return true ;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <class T>
bool Queue<T>::dequeue()
{
	bool result = false ;
	if (!isEmpty())
	{
		// Queue is not empty; remove front
		Node<T>* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{ // Special case: one node in queue
			frontPtr = nullptr ;
			backPtr = nullptr ;
		}
		else
			frontPtr = frontPtr->getNext();
		// Return deleted node to system
		nodeToDeletePtr->setNext( nullptr );
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr ;
		result = true ;
	} // end if
	return result;
} // end dequeue

///////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T>::~Queue()
{
}