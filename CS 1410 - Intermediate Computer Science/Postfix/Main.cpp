// Jonathan Petersen
// A01236750
// Postfix Conversion
// Main Class

#include <iostream>
#include "Postfix.h"
using namespace std;

stringstream toPostfix(stringstream&);

int main (void)
{
	int example = 1;
	string equation;
	Postfix output;

	/*
	//Get user input
	cout << "Please input an equation in prefix notation.\n"
		 << "Represent all numbers with a single capital letter\n"
		 << "Terminate your expression with \"]\".\n"
		 << "[";

	cin >> equation;
	*/

	while(example < 9) {
		//Set up examples
		switch (example) {
		case 1:	equation = "A*(B-(C+D))]";					 break; //Good input
		case 2:	equation = " (A+B)*C/D";					 break; //No closing ]
		case 3:	equation = " (A+B)*(C-D)] ";				 break; //Extra padding
		case 4:	equation = "[A+B*(C+(D-E))]";				 break; //Opening [

/*!!*/	case 5:	equation = "A+B*C-D]";						 break; //SEE NOTE

		case 6:	equation = "A - B * C + D / E ]";			 break; //Extra spaces
		case 7:	equation = "((A + (B - C) * D) + F)]";		 break; //More Extra Spaces
		case 8: equation = "¸.·´¯`·.´¯`·.¸¸.·´¯`·.¸><(((º>"; break; //I think it's a fish.
		default: return -1; //Should never be called.
		}

		// NOTE:
		// Some of my examples will probably output slightly different answers
		// than the ones you get, or the ones Dr. Qi provided at least. The reason
		// for this is that in her code for precedence comparison, she popped off
		// any operators that were of the same or higher precedence, where mine only
		// pops off operators that are of higher precedence. Both methods are sound
		// mathematically, however. (A + (B * C)) - D is equal to A + ((B * C) - D),
		// just as (A + B) - C is equal to A + (B - C), just as A B C * + D - is 
		// equal to A B C * D - +. 

		//Process each example
		try {
			output = Postfix(equation);
			cout << output.toPostfix();
			cout << endl;
		}
		catch (Postfix::ImproperInput) {
	
			cout << "Invalid input sequence, run the program again with\n"
				 << "a valid input sequence.\n";
	
		}

		example++;
	}

	return 0;
}

