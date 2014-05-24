// Jonathan Petersen
// A01236750
// Postfix Conversion
// Stack Class Template

#ifndef STACK_H
#define STACK_H
#define NULL 0

using namespace std;

//Node class of the dynamic stack
template <class T>
class Node {

public:

	//Constructors
	Node() { next = NULL; return; }

	//Data Members
	T		 data;
	Node<T>* next;

};

//Dynamic Stack Class
template <class T>
class Stack {

public:

	//Constructors
	Stack();
	
	//Data Manipulation
	void push(T data);
	T	 pop();
	
	//Stack Information
	int  size(); 
	T	 last();	
	
	//Exception Classes
	class StackEmpty {};

private:

	int		 count;
	Node<T>* top;


};

//Constructor
template <class T>
Stack<T>::Stack() {

	top = NULL;
	count = 0;

	return;
}

//Function to push data onto the stack
template <class T>
void Stack<T>::push(T data) {

	//Create new node
	Node<T>* temp = new Node<T>;

	//Assign data to the node
	temp->data = data;
	temp->next = top;

	//Manipulate stack information
	top = temp;
	count++;

	return;
}

//Function to pop data off of the stack
template <class T>
T Stack<T>::pop() {

	//Exception Handling
	if (count == 0) throw StackEmpty();

	//Select top node
	Node<T>* temp = top;
	T data = temp->data;

	//Manipulate stack information
	top = temp->next;
	count--;

	//Cleanup and return data
	delete temp;
	return data;
}

//Return the number of items in the stack
template <class T>
int Stack<T>::size() {

	return count;

}

//Return the topmost item
template <class T>
T Stack<T>::last() {

	return top->data;

}

#endif