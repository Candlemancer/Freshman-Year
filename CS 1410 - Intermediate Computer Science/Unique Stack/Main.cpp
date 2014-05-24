// Jonathan Petersen
// A01236750
// Unique Stack
// Main

using namespace std;

#include <iostream>
#include "TUStack.h"
#include <string> //This is just included so I have some objects to stack. 
				  //It would work the same including any class that has overloaded the == operator.
				  //Feel free to change it if you would like, though there are two sections of code
				  //that you'll need to adapt to the type of object you're stacking. (Basically 
				  //anywhere that you need to create unique objects of that type.)

int main() {

	//Make a new stack of Integers
	TUStack<int> intStack (5);
	cout << "Created intStack of size " << intStack.size() << ".\n";

	//Fill it with stuff
	for(int i=0; i<intStack.size(); i++) {
		intStack.push(i);
	}

	//Read the stuff from start to finish
	for(int i=0; i<intStack.position(); i++) {
		cout << "The intStack at " << i << " is " << intStack[i] << ".\n";
	}

	//Pop the stuff
	while(intStack.position()) {
		cout << "Popping index " << intStack.position() << ": " << intStack.pop() << ".\n";
	}

	// ^ That should work fine. 
	cout << endl;


	//Make a new stack of objects
	TUStack<string> objStack (10);
	cout << "Created objStack of size " << objStack.size() << ".\n";

//NOTE: THE FOLLOWING LINES NEED TO BE CHANGED BASED ON THE OBJECTS YOU ARE STACKING.
	//Fill it with stuff
	objStack.push(string("Blessed")); 
	objStack.push(string(    "are"));  
	objStack.push(string(   "they")); 
	objStack.push(string(   "that")); 
	objStack.push(string("believe")); 

	//Read all the stuff from start to finish
	for(int i=0; i<objStack.position() - 1; i++) { //Note the - 1 for dramatic palindrome effect.
		cout << "The objStack at " << i << " is " << objStack[i] << ".\n";
	}
	
	//Pop the stuff
	while(objStack.position()) {
		cout << "Popping index " << objStack.position() << ": " << objStack.pop() << ".\n";
	}

	// ^ Also should work fine.


	// Lets break stuff! =)
	// /*
	cout << endl << endl << endl;
	intStack.pop(); //Nothing left to pop.
	intStack[-1];   //Invalid index
	cout << endl;
	intStack.push(42);  // Valid push
	intStack.pop();		// Valid pop. Note that 42 is left in memory however
	intStack.push(42);  // Valid push, only the below error should show
	intStack.push(42);  // Duplicate error!
	cout << endl;
	for(int i=0; i<=intStack.size(); i++) { //Filling up the stack one larger than it should be.
		intStack.push(i);					//No room in the inn error!
	}

	cout << endl << endl;
	objStack.pop(); //Nothing left to pop.
	objStack[-1];   //Invalid index
	cout << endl;
	objStack.push("42");  // Valid push
	objStack.pop();		  // Valid pop. Note that "42" is left in memory however
	objStack.push("42");  // Valid push, only the below error should show
	objStack.push("42");  // Duplicate error!
	cout << endl;
	for(int i=0; i<=objStack.size(); i++) { //Filling up the stack one larger than it should be.

//NOTE: THE FOLLOWING LINE NEEDS TO BE CHANGED BASED ON WHAT OBJECTS ARE IN YOUR STACK.
		objStack.push(to_string(i));		//No room in the inn error! 

	}
	// */

	return 0;
}