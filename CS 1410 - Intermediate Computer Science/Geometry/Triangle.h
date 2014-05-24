//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Triangle Class Header

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Geometry.h"

using namespace std;

class Triangle : public Geometry {

public:
	//Constructors
	Triangle();
	Triangle(char*, int);
	Triangle(const Triangle&);
	//Constructor to pass children's constructor to parent.
	Triangle(char*, char*, int);
	//Base class will handle all destructor functions.

	//Overloaded Operators
	Triangle& operator= (const Triangle&);

	//Member Functions
	virtual double computeVolume();
	virtual double computeSurface();

};

#endif