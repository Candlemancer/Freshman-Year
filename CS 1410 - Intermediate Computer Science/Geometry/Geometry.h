//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Geometry Class Header
#ifndef GEOMETRY_H
#define GEOMETRY_H

using namespace std;

//Abstract Base Class
class Geometry {

public:
	//Constructors
	 Geometry();
	 Geometry(char*, char*, double);
	 Geometry(const Geometry&);
	~Geometry();

	//Overloaded Operators
	virtual Geometry& operator= (const Geometry&);

	//Member Functions
	char* getName();
	char* getType();
	virtual double computeVolume()  = 0;
	virtual double computeSurface() = 0;

protected:
	//Data Values
	char* name;
	char* type;
	double dimension;

};

#endif