//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Sphere Class Header

#ifndef SPHERE_H
#define SPHERE_H

#include "Circle.h"

using namespace std;

class Sphere : public Circle {

public:
	//Constructors
	Sphere();
	Sphere(char*, double);
	Sphere(const Sphere&);
	//Base class will handle all destructor functions.

	//Overloaded Operators
	Sphere& operator= (const Sphere&);

	//Member Functions
	virtual double computeVolume();
	virtual double computeSurface();

};

#endif