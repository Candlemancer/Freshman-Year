//Jonathan Petersen
//A01236750
//Rational Functions
#include <iostream>
#include <sstream>
#include "Rational.h"


//---Constructors---//

//Default Constructor
Rational::Rational() {

	makeThis(0, 1);
	return;
}

//Half Constructor
Rational::Rational(int top) {

	makeThis(top, 1);
	return;
}

//Full Constructor
Rational::Rational(int top, int bot) {

	makeThis(top, bot);
	return;
}

//String Constructor 
Rational::Rational(string input) {

	int pos = input.find('/');

	//Find the '/', or exit if invalid.
	if(pos > input.size()) {
		cout << "Invalid string constructor input. Creating Whole number fraction.\n";
		makeThis(parseStr(input), 1);
		return;
	}

	//Send the string chunks off for processing.
	makeThis( parseStr(input.substr( 0, pos )), parseStr(input.substr( (pos + 1), (input.size() - (pos + 1)) )) ); 

	return;
}

//Copy Constructor
Rational::Rational(const Rational &input) {

	makeThis(input.num, input.dem);
	return;
}


//---Assignment Operators---//

//Assign from another Rational.
Rational& Rational::operator=(const Rational &rhs) {

	//Check for self-assignment
	if (this != &rhs) makeThis(rhs.num, rhs.dem);
	return *this;
}

//Assign from an integer.
Rational& Rational::operator=(const int rhs) {

	makeThis(rhs, 1);
	return *this;
}

//Assign from a string.
Rational& Rational::operator=(const string input) {

	int pos = input.find('/');

	//Find the '/', or exit if invalid.
	if(pos > input.size()) {
		cout << "Invalid program string input. Creating whole number fraction.\n";
		makeThis(parseStr(input), 1);
		return *this;
	}

	//Send the string chunks off for processing.
	makeThis( parseStr(input.substr( 0, pos )), parseStr(input.substr( (pos + 1), (input.size() - (pos + 1)) )) ); 
	return *this;
}


//---Arithmetic binary operators---//

//Add two rationals.
Rational Rational::operator+(const Rational &rhs) {

	Rational result;

	result.makeThis( ((num * rhs.dem) + (rhs.num * dem)), (dem * rhs.dem) );
	return result;
}

//Add an int.
Rational Rational::operator+(int input) {

	Rational result = input;
	return (*this + result);
}

//Add a string.
Rational Rational::operator+(string input) {

	Rational result = input;
	return (*this + result);
}


//---Compound assignment operators---//

//Plus equals a rational.
Rational& Rational::operator+=(const Rational &rhs) {

	*this = *this + rhs;
	return*this;
}

//Plus equals an int.
Rational& Rational::operator+=(int input) {

	*this = *this + input;
	return *this;
}

//Plus equals a string.
Rational& Rational::operator+=(string input) {

	*this = *this + input;
	return *this;
}


//---Relational operators---//

//Equal comparison
bool Rational::operator==(const Rational &rhs) {

	Rational temp = rhs;

	if (double() == static_cast <double>(temp)) return true;
	return false;
}

//Greater Than comparison
bool Rational::operator>(const Rational &rhs) {

	Rational temp = rhs;

	if (double() > static_cast <double>(temp) ) return true;
	return false;	
}


//---Prefix and Postfix operators---//

//Prefix Operator
Rational Rational::operator ++ () {

	*this += 1;
	return *this;
}

//Postfix Operator
Rational Rational::operator ++ (int) {

	Rational temp = *this;
	*this += 1;
	return temp;
}


//---Conversion Operators---//

//Convert our fraction into a double.
Rational::operator double() {return (static_cast <double>(num) / static_cast <double>(dem) );}


//---Private Functions---//

//Solve for the greatest common divisor.
int Rational::solveGCD(int top, int bot) { 

	//Find the remainder
	int rem;
	rem = top % bot;

	//Continually divide the remainder by the boterator until 0 is reached.
	while (rem != 0) {
		top = bot;
		bot = rem;
		rem = top % bot;
	}

	return bot;
}

//Simplify a fraction.
void Rational::simplify(int &top, int &bot) {

	int gcd = solveGCD(top, bot);

	top = top / gcd;
	bot = bot / gcd;

	return;
}

//Parse a string as an int.
int Rational::parseStr(string input) {

	int temp;
	stringstream ss(input);

	ss >> temp;

	return temp;
}

//Assign the proper values where they need to be.
void Rational::makeThis(int top, int bot) {

	stringstream str;

	//Make sure we're not dividing by 0
	if (bot == 0) {
		cout << "Zero denominator detected, please choose a new denominator.\n";
		cout << "The current numerator is: " << top << endl;
		while ( !(cin >> bot) || cin.get() != '\n' ) {
			cin.clear();
			cin.sync();
			cout << "That number is also invalid, please choose a new denominator.\n";
		}
	}

	//Simplify the fraction
	if(top != 0) simplify(top, bot);
	if(top == 0) bot = 1;

	//Put the numerical values in
	num = top;
	dem = bot;

	//Then format the numbers and spit out a string.
	str << num << '/' << dem;
	fraction = str.str();

	return;
}




//---Stream Operators---//

//
ostream& operator<<(ostream& out, Rational x) {

	if(x.dem == 1) out << x.num;
	if(x.dem != 1) out << x.fraction;
	return out;
}


istream& operator>>(istream& in, Rational& x) {

	string input;
	int pos = -1;

	cout << "Please enter a rational number in the form X/Y. [2/3]\n";
	in >> input;

	pos = input.find('/');

	if(pos >= input.size()) {
	x.makeThis( x.parseStr(input), 1);
	return in; 
	}

	x.makeThis( x.parseStr(input.substr( 0, pos )), x.parseStr(input.substr( (pos + 1), (input.size() - (pos + 1)) )) ); 
	return in;
}


//---Inverse Binary Operators---//

//Inverse integer addition.
Rational operator+(const int input, const Rational& x) {

	cout << "Welcome to inverse integer!\n";

	Rational result = input;
	result += x;
	return result;
}

//Inverse string addition.
Rational operator+(const string input, const Rational& x) {

	Rational result = input;
	result += x;
	return result;
}
