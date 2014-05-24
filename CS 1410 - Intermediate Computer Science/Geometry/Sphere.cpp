//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Sphere Class Implementation

#define _USE_MATH_DEFINES

#include "Sphere.h"
#include <cstring>
#include <cmath>

//Empty Constructors call Circle Constructor with appropriate information.
Sphere::Sphere() 							 : Circle()	 							{}
Sphere::Sphere(char* name, double dimension) : Circle(name, "Sphere", dimension) 	{}
Sphere::Sphere(const Sphere&) 				 : Circle(*this) 						{}

//Overloaded assignment operator
Sphere& Sphere::operator= (const Sphere& another) {

	//Deep copy of data
	this->name = new char[ static_cast <int> (strlen(another.name)) ];
	this->type = new char[ static_cast <int> (strlen(another.type)) ];
	strcpy(this->name, another.name);
	strcpy(this->type, another.type);
	this->dimension = another.dimension;

	return *this;
}

//Compute the volume (0) and area of the Sphere
double Sphere::computeVolume()  { return ( 4/3 * M_PI * pow(dimension, 3)); }
double Sphere::computeSurface() { return ( 4   * M_PI * pow(dimension, 2)); }

