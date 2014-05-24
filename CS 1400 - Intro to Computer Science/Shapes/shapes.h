// Jonathan Petersen
// A01236750
// Shapes
// Shape Class Headers


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
