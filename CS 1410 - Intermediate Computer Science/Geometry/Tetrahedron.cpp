//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Tetrahedron Class Implementation

#define _USE_MATH_DEFINES

#include "Tetrahedron.h"
#include <cstring>
#include <cmath>

//Empty Constructors call Triangle Constructor with appropriate information.
Tetrahedron::Tetrahedron() 								: Triangle()	 							{}
Tetrahedron::Tetrahedron(char* name, int dimension) 	: Triangle(name, "Tetrahedron", dimension) 	{}
Tetrahedron::Tetrahedron(const Tetrahedron&) 			: Triangle(*this) 							{}

//Overloaded assignment operator
Tetrahedron& Tetrahedron::operator= (const Tetrahedron& another) {

	//Deep copy of data
	this->name = new char[ static_cast <int> (strlen(another.name)) ];
	this->type = new char[ static_cast <int> (strlen(another.type)) ];
	strcpy(this->name, another.name);
	strcpy(this->type, another.type);
	this->dimension = another.dimension;

	return *this;
}

//Compute the volume (0) and area of the Tetrahedron
double Tetrahedron::computeVolume()  { return ( pow(dimension, 3) / (6 * pow(2, 0.5)) ); }
double Tetrahedron::computeSurface() { return ( pow(3, 0.5) * pow(dimension, 2) ); }

