//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Triangle Class Implementation

#include "Triangle.h"
#include <cstring>
#include <cmath>

//Empty Constructors call Geometry Constructor with appropriate information. 
Triangle::Triangle() 							: Geometry() 								{}
Triangle::Triangle(char* name, int dimension) 	: Geometry(name, "Triangle", dimension) 	{}
Triangle::Triangle(const Triangle&) 			: Geometry(*this) 							{}
//Constructor used to pass the proper type to Geometry from a child class.
Triangle::Triangle(char* name, char* type, int dimension) : Geometry(name, type, dimension) {}

//Overloaded assignment operator
Triangle& Triangle::operator= (const Triangle& another) {

	//Deep copy of data
	this->name = new char[ static_cast <int> (strlen(another.name)) ];
	this->type = new char[ static_cast <int> (strlen(another.type)) ];
	strcpy(this->name, another.name);
	strcpy(this->type, another.type);
	this->dimension = another.dimension;

	return *this;
}

//Compute the volume (0) and area of the Triangle
double Triangle::computeVolume()  { return 0; }
double Triangle::computeSurface() { return ( (pow(3, 0.5) / 4) * pow(dimension, 2) ); }

