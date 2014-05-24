//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Rectangle Class Header

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Geometry.h"

using namespace std;

class Rectangle : public Geometry {

public:
	//Constructors
	Rectangle();
	Rectangle(char*, double, double);
	Rectangle(const Rectangle&);
	//Constructor to pass children's constructor to parent.
	Rectangle(char*, char*, double, double);
	//Base class will handle all destructor functions.

	//Overloaded Operators
	Rectangle& operator= (const Rectangle&);

	//Member Functions
	virtual double computeVolume();
	virtual double computeSurface();

protected:
	//Secondary side length
	double width;

};

#endif