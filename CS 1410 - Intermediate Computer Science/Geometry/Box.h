//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Box Class Header

#ifndef BOX_H
#define BOX_H

#include "Rectangle.h"

using namespace std;

class Box : public Rectangle {

public:
	//Constructors
	Box();
	Box(char*, double, double, double);
	Box(const Box&);
	//Base class will handle all destructor functions.

	//Overloaded Operators
	Box& operator= (const Box&);

	//Member Functions
	virtual double computeVolume();
	virtual double computeSurface();

protected:
	//Another additional variable for height of the box.
	double height;

};

#endif