//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Rectangle Class Implementation

#include "Rectangle.h"
#include <cstring>

//Empty Constructors call Geometry Constructor with appropriate information. 
Rectangle::Rectangle() 					: Geometry() 		{}
Rectangle::Rectangle(const Rectangle&) 	: Geometry(*this) 	{}
//Constructor used to pass the proper type to Geometry from a child class. Note the additional assignment of width.
Rectangle::Rectangle(char* name, char* type, double dimension, double width) 	: Geometry(name, type, dimension) 			{ this->width = width; }
Rectangle::Rectangle(char* name, double dimension, double width) 				: Geometry(name, "Rectangle", dimension) 	{ this->width = width; }

//Overloaded assignment operator
Rectangle& Rectangle::operator= (const Rectangle& another) {

	//Deep copy of data
	this->name = new char[ static_cast <int> (strlen(another.name)) ];
	this->type = new char[ static_cast <int> (strlen(another.type)) ];
	strcpy(this->name, another.name);
	strcpy(this->type, another.type);
	this->dimension = another.dimension;
	this->width = another.width;

	return *this;
}

//Compute the volume (0) and area of the Rectangle
double Rectangle::computeVolume()  { return 0; }
double Rectangle::computeSurface() { return (dimension * width); }

