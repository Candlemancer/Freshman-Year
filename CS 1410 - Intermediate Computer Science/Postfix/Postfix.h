// Jonathan Petersen
// A01236750
// Postfix Conversion
// Postfix class Header

#ifndef POSTFIX_H
#define POSTFIX_H

#include <string>

using namespace std;

class Postfix {

public:
	//Constructors
	Postfix();
	Postfix(string str);

	//Conversion
	string toPostfix();

	//Error Class
	class ImproperInput {};

private:
	string expression;

};

#endif