// Jonathan Petersen
// A01236750
// Postfix Conversion
// Postfix Class Implementation

#include "DynamicStack.h"
#include "Postfix.h"

using namespace std;

//Default Constructor
Postfix::Postfix() {}

//Constructor from string
Postfix::Postfix(string str) {

	//Make sure there aren't two ['s
	if (str[0] == '[') str = str.substr(1, str.size() - 1);

	//Ignore spaces
	for (unsigned int i=0; i<str.length(); i++) {
		if(str[i] == ' ') continue;
		if( !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '+' || str[i] == '-' ||
			  str[i] == '*' || str[i] == '/'  ||   str[i] == '(' || str[i] == ')' ||
			  str[i] == '[' || str[i] == ']')									  ) throw ImproperInput();
		expression.append(1, str[i]);
	}

	//Insure the terminating character is a ]
	if(str[str.length() - 1] != ']') expression.append("]");

	return;
}

string Postfix::toPostfix() {

	//Initialize the stack
	Stack<char> stack;
	char current = '[';
	char temp;
	string output;

	//Process data
	for (int i=0; current != ']'; i++) {
		switch (current) {
			
		case '[': //Initialize the expression
			stack.push(current);
			break;

		case '(': //Create Start of Parenthetical
			stack.push(current);
			break;

		case ')': //Terminate and process parenthetical
			temp = stack.pop();
			while(temp != '(') {
				output.append(1, temp);
				output.append(" ");
				temp = stack.pop();
			}
			break;

		default: //Handle all other cases

			//Operand case
			if (current >= 'A' && current <= 'Z') {
				output.append(1, current);
				output.append(" ");
				break;
			}

			//Higher Precedence case
			temp = current;
			while (stack.last() == '*' || stack.last() == '/') {
				temp = stack.pop();
				output.append(1, temp);
				output.append(" ");
			}

			stack.push(current);
			break;
		}

		//Get the next character
		current = expression[i];


	}

	//Terminate Processing
	temp = stack.pop();
	while (temp != '[') {
		output.append(1, temp);
		output.append(" ");
		temp = stack.pop();
	}

	return output;
}