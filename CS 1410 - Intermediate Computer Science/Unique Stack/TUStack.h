// Jonathan Petersen
// A01236750
// Unique Stack
// TUStack Template File 

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T>  
class TUStack {
public:
	//Constructors
	 TUStack(int size);
	~TUStack();

	//Member Functions
	void push(T item);
	T    pop();
	int  size();
	int  position();
	T    operator[](int pos);

private:
	//More Member Functions
	T getValue(int pos);

	//Data Members
	T*  data;
	int capacity;
	int top; //NOTE: top points to the first free space in the stack, NOT the last item added to the stack.


};


//Construct a stack of size 'size'.
template <typename T>
TUStack<T>::TUStack(int size) {
	
	//Error Handling
	try {
		
		//If size is too small
		if(size < 1) throw "Array is too small."; 

	}
	//Catch input error
	catch (char* error) {
		
		//Output Error Message
		cout << "ERROR: " << error << endl
			 << "Current Stack Size: " << capacity << endl
			 << "Current Stack Position: " << top << endl;

		//Repair Error
		cout << "Creating Array of size 1.\n";
		size = 1;

	}

		//Assign memory and default data values
		capacity = size;
		data = new T[size];
		top = 0;

	return;
}

template <typename T>
TUStack<T>::~TUStack() { delete [] data; }

template <typename T>
void TUStack<T>::push(T item) {
	
	try {
		
		//Check if stack is full
		if(top == capacity) throw "No room in the stack.";

		//Check if top needs to be incremented manually
		if(data[top] == item && top <= 0) throw 1.0;
		if(data[top] == item && data[top - 1] != item) throw 1.0;

		//Check for duplicates
		for(int i=0; i<=top; i++) {
			if(data[i] == item) throw i;
		}

	}
	//Catch Input Error
	catch (char* error) {

		//Print Error Message.
		cout << "ERROR: " << error << endl
			 << "Current Stack Size: " << capacity << endl
			 << "Current Stack Position: " << top << endl;
		
		//Attempt to show new object.
		try {
			if( !(cout << "Item: " << item << endl)) throw "Item Cannot be Printed.";
		}
		catch (char* error) {
			cout << error << endl;
		}

		cout << "Ignoring last push.\n";
		return;
	}
	//Catch pointer error
	catch (double error) {
	
		//Manually increment top. This gets called only if the top of the stack is a duplicate of the most recent item,
		//And only if there is not another duplicate below it.
		top++;
		return;
	}
	//Catch duplicate error
	catch (int error) {

		cout << "A duplicate was found on the stack at position " << error << ". Ignoring input.\n";
		return;
	}

	data[top] = item;
	top++;

	return;
}

template <typename T> 
T TUStack<T>::pop() {

	try {

		//If stack has data
		if(top == 0) throw "Nothing left to pop.";

	}
	catch (char* error) {

		//Print Error Message.
		cout << "ERROR: " << error << endl
			 << "Current Stack Size: " << capacity << endl
			 << "Current Stack Position: " << top << endl;

		//Create dummy object.
		T dummy = T();

		return dummy;
	}

	top--;
	return data[top];

}

template <typename T>
int TUStack<T>::size() { return capacity; }

template <typename T>
int TUStack<T>::position() { return top; }

template <typename T>
T TUStack<T>::operator[](int pos) { return getValue(pos); }

template <typename T>
T TUStack<T>::getValue(int pos) {

	try {

		//Insure the position we're looking for exists.
		if (pos < 0 || pos >= top) throw "Pointer out of Bounds.";

	}
	catch (char* error) {

		//Print Error Message.
		cout << "ERROR: " << error << endl
			 << "Current Stack Size: " << capacity << endl
			 << "Current Stack Position: " << top << endl;

		//Create Dummy Value
		T dummy = T();

		return dummy;
	}

	return data[pos];
}