// Jonathan Petersen
// A01236750
// Shapes
// Shape Class Implementation

#include "shapes.h"
#include <cmath>

//--------Square Functions--------//

//Return values for the dimension and area of the square.
float Square::getDimension()		{return dimension;}
float Square::getArea()			{return dimension * dimension;}
//Set values for the dimension and area of the square, in terms of dimension.
//If the user inputs a new value which is negative, set the value to 0.
void Square::setDimension(float newDim) {
	if (newDim >= 0) dimension = newDim;
	if (newDim <  0) dimension = 0;
}
void Square::setArea(float newArea) {
	if (newArea >= 0) dimension = sqrt(newArea);
	if (newArea <  0) dimension = 0;
}
//Setup the square, using 1.0 as the initial dimension unless user specified.
Square::Square()			 {dimension = 1.0;}
Square::Square(float initialDim)	 {dimension = initialDim;}


//--------Circle Functions--------//

//Return values for the radius, diameter, and area of the circle.
float Circle::getRadius()		{return radius;}
float Circle::getDiameter()		{return 2.0 * radius;}
float Circle::getArea()			{return 3.14159 * radius * radius;}
//Set values for the radius and area of the circle, in terms of the radius.
//If the user inputs a new value which is negative, set the value to 0.
void Circle::setRadius(float newRadius) {
	if (newRadius >= 0) radius = newRadius;
	if (newRadius <  0) radius = 0;
}
void Circle::setArea(float newArea) {
	if (newArea >= 0) radius = sqrt(newArea / 3.14159);
	if (newArea <  0) radius = 0;
}
//Setup the circle, using 1.0 as the initial radius unless user specified.
Circle::Circle()			{radius = 1.0;}
Circle::Circle(float initialRadius) 	{radius = initialRadius;}


//--------Rectangle Functions--------//

//Return the values for the height, width, and area of the rectangle.
float Rectangle::getHeight()		{return height;}
float Rectangle::getWidth()		{return width;}
float Rectangle::getArea()		{return height * width;}
//Set values for the height, width, and area of the rectangle.
//If the user inputs a new value which is negative, set the value to 0.
void Rectangle::setHeight(float newHeight) {
	if (newHeight >= 0) height = newHeight;
	if (newHeight <  0) height = 0;
}
void Rectangle::setWidth(float newWidth) {
	if (newWidth >= 0) width = newWidth;
	if (newWidth <  0) width = 0;
}
void Rectangle::setArea(float newArea, float newHeight) {
	if (newArea >= 0 && newHeight >= 0) {
		height = newHeight;
		width = (newArea / newHeight);
	}
	else {
		height = 0;
		width = 0;
	}
}
//Setup the rectangle, using 1.0 as default unless user specified.
Rectangle::Rectangle() {
	height = 1.0;
	width = 1.0;
}
Rectangle::Rectangle(float initialHeight, float initialWidth) {
	height = initialHeight;
	width = initialWidth;
}


//--------Triangle Functions--------//

//Return the values for the height, base, and area of the triangle.
float Triangle::getHeight()		{return height;}
float Triangle::getBase()		{return base;}
float Triangle::getArea()		{return 0.5 * height * base;}
//Set values for the height, base, and area of the triangle.
//If the user inputs a new value which is negative, set the value to 0.
void Triangle::setHeight(float newHeight) {
	if (newHeight >= 0) height = newHeight;
	if (newHeight <  0) height = 0;
}
void Triangle::setBase(float newWidth) {
	if (newWidth >= 0) base = newWidth;
	if (newWidth <  0) base = 0;
}
void Triangle::setArea(float newArea, float newBase) {
	if (newArea >= 0 && newBase >= 0) {
		height = (2.0 * newArea) / newBase;
		base = newBase;
	}
	else {
		height = 0;
		base = 0;
	}
}
//Setup the Triangle, using 1.0 as default unless user specified.
Triangle::Triangle() {
	height = 1.0;
	base = 1.0;
}
Triangle::Triangle(float initialHeight, float initialBase) {
	height = initialHeight;
	base = initialBase;
}

