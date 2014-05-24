//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Tetrahedron Class Header

#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Triangle.h"

using namespace std;

class Tetrahedron : public Triangle {

public:
	//Constructors
	Tetrahedron();
	Tetrahedron(char*, int);
	Tetrahedron(const Tetrahedron&);
	//Base class will handle all destructor functions.

	//Overloaded Operators
	Tetrahedron& operator= (const Tetrahedron&);

	//Member Functions
	virtual double computeVolume();
	virtual double computeSurface();

};

#endif