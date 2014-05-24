//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Geometry Implementation

#include "Geometry.h"
#include <cstring>

//Default Constructor
Geometry::Geometry() {

	name = new char[0];
	type = new char[0];
	dimension = 0.0;

}

//Constructor with parameters to create an object.
Geometry::Geometry(char* name, char* type, double dimension) {

	//Set the name
	this->name = new char[ static_cast <int> (strlen(name)) ];
	strcpy(this->name, name);
	
	//Set the type
	this->type = new char[ static_cast <int> (strlen(type)) ];
	strcpy(this->type, type);

	//Set the dimensions of the object.
	this->dimension = dimension;

}

//Copy Constructor
Geometry::Geometry(const Geometry& another) {

	*this = another;

}

//Destructor
Geometry::~Geometry() {

	//Deallocate Memory
	delete[] name;
	delete[] type;

}

//Overloaded Assignment operator
Geometry& Geometry::operator= (const Geometry& another) {

	//Deep copy of data
	this->name = new char[ static_cast <int> (strlen(another.name)) ];
	this->type = new char[ static_cast <int> (strlen(another.type)) ];
	strcpy(this->name, another.name);
	strcpy(this->type, another.type);
	this->dimension = another.dimension;

	return *this;
}

char* Geometry::getName() {return name;}
char* Geometry::getType() {return type;}