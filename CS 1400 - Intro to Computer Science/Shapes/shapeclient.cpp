// Jonathan Petersen
// A01236750
// Shapes
// Driver Code

#include <iostream>
#include "shapes.h"

/************

#ifndef SHAPES_H
#define SHAPES_H

// please note: any attempt to set a dimension or area to less than zero
// will be replaced by setting that dimensiton or area to zero


class Square {
public:
	float getDimension();
	float getArea();
	void setDimension(float newDim);
	void setArea(float newArea);
	Square(); //set initial dimension to 1.0
	Square(float initialDim);

private:
	float dimension;
};

class Circle {
public:
	float getRadius();
	float getDiameter();
	float getArea();
	void setRadius(float newRadius);
	void setArea(float newArea);
	Circle(); //set initial radius to 1.0
	Circle(float initialRadius);

private:
	float radius;
};

class Rectangle {
public:
	float getHeight();
	float getWidth();
	float getArea();
	void setHeight(float newHeight);
	void setWidth(float newWidth);
	void setArea(float newArea, float newHeight);
	Rectangle(); //set height and width to 1.0
	Rectangle(float initialHeight, float initialWidth);

private:
	float height;
	float width;
};

class Triangle {
public:
	float getHeight();
	float getBase();
	float getArea();
	void setHeight(float newHeight);
	void setBase(float newWidth);
	void setArea(float newArea, float newBase);
	Triangle(); //set initial base and height to 1.0
	Triangle(float initialHeight, float initialBase); //set initial base and height to 1.0

private:
	float height;
	float base;
};

#endif
*************/

using namespace std;

int main(){
	Square s1;
	Square s2(3.14);;
	Circle c1;
	Circle c2(23.5);
	Rectangle r1;
	Rectangle r2(6,7);
	Triangle t1;
	Triangle t2(4,3);


	cout << "s1 dimension = " << s1.getDimension() << endl;
	cout << "s1      area = " << s1.getArea() << endl;
	s1.setDimension(42);
	cout << "s1 dimension = " << s1.getDimension() << endl;
	cout << "s1      area = " << s1.getArea() << endl;
	s1.setArea(49);
	cout << "s1 dimension = " << s1.getDimension() << endl;
	cout << "s1      area = " << s1.getArea() << endl;
	cout << endl;

	cout << "s2 dimension = " << s2.getDimension() << endl;
	cout << endl;

	cout << "c1    radius = " << c1.getRadius() << endl;
	cout << "c1  diameter = " << c1.getDiameter() << endl;
	cout << "c1      area = " << c1.getArea() << endl;
	c1.setRadius(-1);
	cout << "c1    radius = " << c1.getRadius() << endl;
	cout << "c1  diameter = " << c1.getDiameter() << endl;
	cout << "c1      area = " << c1.getArea() << endl;
	c1.setArea(5.0);
	cout << "c1    radius = " << c1.getRadius() << endl;
	cout << "c1  diameter = " << c1.getDiameter() << endl;
	cout << "c1      area = " << c1.getArea() << endl;
	cout << endl;

	cout << "c2    radius = " << c2.getRadius() << endl;
	cout << endl;

	cout << "r1    height = " << r1.getHeight() << endl;
	cout << "r1     width = " << r1.getWidth() << endl;
	cout << "r1      area = " << r1.getArea() << endl;
	r1.setWidth(-1);
	cout << "r1    height = " << r1.getHeight() << endl;
	cout << "r1     width = " << r1.getWidth() << endl;
	cout << "r1      area = " << r1.getArea() << endl;
	r1.setWidth(3);
	r1.setHeight(6);
	cout << "r1    height = " << r1.getHeight() << endl;
	cout << "r1     width = " << r1.getWidth() << endl;
	cout << "r1      area = " << r1.getArea() << endl;
	r1.setArea(13,5);
	cout << "r1    height = " << r1.getHeight() << endl;
	cout << "r1     width = " << r1.getWidth() << endl;
	cout << "r1      area = " << r1.getArea() << endl;
	cout << endl;

	cout << "r2    height = " << r2.getHeight() << endl;
	cout << "r2     width = " << r2.getWidth() << endl;
	cout << "r2      area = " << r2.getArea() << endl;
	cout << endl;

	cout << "t1    height = " << t1.getHeight() << endl;
	cout << "t1      base = " << t1.getBase() << endl;
	cout << "t1      area = " << t1.getArea() << endl;
	t1.setBase(-1);
	cout << "t1    height = " << t1.getHeight() << endl;
	cout << "t1      base = " << t1.getBase() << endl;
	cout << "t1      area = " << t1.getArea() << endl;
	t1.setBase(3);
	t1.setHeight(6);
	cout << "t1    height = " << t1.getHeight() << endl;
	cout << "t1      base = " << t1.getBase() << endl;
	cout << "t1      area = " << t1.getArea() << endl;
	t1.setArea(13,5);
	cout << "t1    height = " << t1.getHeight() << endl;
	cout << "t1      base = " << t1.getBase() << endl;
	cout << "t1      area = " << t1.getArea() << endl;
	cout << endl;

	cout << "t2    height = " << t2.getHeight() << endl;
	cout << "t2      base = " << t2.getBase() << endl;
	cout << "t2      area = " << t2.getArea() << endl;
	cout << endl;

	return 0;
}
