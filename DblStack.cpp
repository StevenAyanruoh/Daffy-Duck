// File name: DblStack.cpp
// Name: 
// VUnetid: 
// Email: 
// Class: 
// Assignment Number:
// Honor statement: 
// Description:  Maintains a stack of ItemType.  Implements functions to
//     push, pop, retrieve top, and retrieve size of the stack.
// Last Changed:  

#include <cstddef>  //for NULL
#include <stdexcept>
#include "DblStack.h"
using namespace std;

// Class Constructor
// post: stack is created & initialized to be empty
DblStack::DblStack() : myTop(nullptr), mySize(0)
{
}


// Copy Constructor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack
DblStack::DblStack(const DblStack& rhs)
{
	if (rhs.myTop != nullptr)
	{
		myTop = new Node;
		myTop->next = rhs.myTop->next;
		NodePtr newPtr = myTop;

		for (NodePtr origPtr = myTop->next; origPtr != nullptr; origPtr = origPtr->next)
		{
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->value = origPtr->value;
		}

		newPtr->next = nullptr;
	}

	myTop = rhs.myTop;

}



// Class Deconstructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
DblStack::~DblStack()
{
	while (!isEmpty())
	{
		pop();
	}

}


// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const DblStack& DblStack::operator= (const DblStack& rhs)
{
	if (this != &rhs)
	{
		DblStack tmp(rhs);
		std::swap(myTop, tmp.myTop);
		std::swap(mySize, tmp.mySize);
	}
	return *this;

}


// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
bool DblStack::isEmpty() const
{
	if (mySize == 0)
	{
		return true; 
	}
	else
	{
		return false; 
	}
}


// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.
void DblStack::push(const ItemType& item)
{
	NodePtr cur = new Node();
	cur->value = item;
	cur->next = myTop -> next; 
	myTop = cur; 
	mySize++; 
}


// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
void DblStack::pop()
{
	if(isEmpty())
	{
		throw std::underflow_error("The stack is empty");
	}

	mySize--;
	NodePtr cur = myTop;
	myTop = cur->next; 
	delete cur; 

}


// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
ItemType DblStack::top() const
{
	if (isEmpty())
	{
		throw std::underflow_error("The stack is empty");
	}
	else
	{
		return myTop->next->value;
	}
}


// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
size_t DblStack::size() const
{
	return mySize; 
}
