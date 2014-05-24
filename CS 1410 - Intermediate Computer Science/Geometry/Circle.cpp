//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Circle Class Implementation

#define _USE_MATH_DEFINES

#include "Circle.h"
#include <cstring>
#include <cmath>

//Empty Constructors call Geometry Constructor with appropriate information. 
Circle::Circle() 							: Geometry() 								{}
Circle::Circle(char* name, int dimension) 	: Geometry(name, "Circle", dimension) 		{}
Circle::Circle(const Circle&) 				: Geometry(*this) 							{}
//Constructor used to pass the proper type to Geometry from a child class.
Circle::Circle(char* name, char* type, int dimension) : Geometry(name, type, dimension) {}

//Overloaded assignment operator
Circle& Circle::operator= (const Circle& another) {

	//Deep copy of data
	this->name = new char[ static_cast <int> (strlen(another.name)) ];
	this->type = new char[ static_cast <int> (strlen(another.type)) ];
	strcpy(this->name, another.name);
	strcpy(this->type, another.type);
	this->dimension = another.dimension;

	return *this;
}

//Compute the volume (0) and area of the circle
double Circle::computeVolume()  { return 0; }
double Circle::computeSurface() { return (M_PI * dimension * dimension); }

