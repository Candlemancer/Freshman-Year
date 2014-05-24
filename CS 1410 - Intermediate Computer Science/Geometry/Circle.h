//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Circle Class Header

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Geometry.h"

using namespace std;

class Circle : public Geometry {

public:
	//Constructors
	Circle();
	Circle(char*, int);
	Circle(const Circle&);
	//Constructor to pass children's constructor to parent.
	Circle(char*, char*, int);
	//Base class will handle all destructor functions.

	//Overloaded Operators
	Circle& operator= (const Circle&);

	//Member Functions
	virtual double computeVolume();
	virtual double computeSurface();

};

#endif