//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Box Class Implementation

#include "Box.h"
#include <cstring>

//Empty Constructors call Rectangle Constructor with appropriate information.
Box::Box() 								: Rectangle()	 							{}
Box::Box(const Box&) 					: Rectangle(*this) 							{}
//Manually assigning the height.
Box::Box(char* name, double dimension, double width, double height) : Rectangle(name, "Box", dimension, width) { this->height = height; }

//Overloaded assignment operator
Box& Box::operator= (const Box& another) {

	//Deep copy of data
	this->name = new char[ static_cast <int> (strlen(another.name)) ];
	this->type = new char[ static_cast <int> (strlen(another.type)) ];
	strcpy(this->name, another.name);
	strcpy(this->type, another.type);
	this->dimension = another.dimension;

	return *this;
}

//Compute the volume (0) and area of the Box
double Box::computeVolume()  { return ( dimension * width * height ); }
double Box::computeSurface() { return ( (2 * dimension * width) + (2 * dimension * height) + (2 * width * height) ); }

