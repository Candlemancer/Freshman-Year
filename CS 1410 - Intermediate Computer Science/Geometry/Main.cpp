//Jonathan Petersen
//A01236750
//Geometry Derived Classes
//Main Driver Code

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>

#ifdef _WIN32
#include "Geometry.h"
#include "Circle.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "Rectangle.h"
#include "Box.h"

#endif

#ifndef _WIN32
#include "Geometry.cpp"
#include "Circle.cpp"
#include "Sphere.cpp"
#include "Triangle.cpp"
#include "Tetrahedron.cpp"
#include "Rectangle.cpp"
#include "Box.cpp"

#endif

using namespace std;

void report(Geometry*);
void report(Geometry**, int&);
void create(Geometry**&, int&);
void create(Geometry**&, int&, bool);
void remove(Geometry**&, int&);
void statistics(Geometry**, int&);
void sortVolume(Geometry**&, int&);
void sortSurface(Geometry**&, int&);

int main() {

	int choice;
	double dimension;
	Geometry** geometryArray;
	int numObjects = -1;

	//Display the initialization menu.
	cout << endl;
	cout << "Welcome to GeometryObjects!\n"
		 << "Would you like to . . . \n"
		 << "1: Create your own objects.\n"
		 << "2: Use the default Objects.\n";

	while( !(cin >> choice)	  ||
			choice < 1 		  ||
			choice > 2 		  ||
			cin.get() != '\n'  ){
		cin.ignore(1000, '\n');

		cout << "Please enter 1 to create unique objects \n"
			 << "or enter 2 to use the default objects. [1 or 2]: ";
	}

	//Create the objects.
	if(choice == 1) create(geometryArray, numObjects);
	if(choice == 2) create(geometryArray, numObjects, false);	

	cout << endl;

	//Process the objects.
	while(choice != 6) {
		//Main menu shenanigans.
		cout << "Welcome to the Main Menu!\n"
			 << endl
			 << "1: Print a report of all objects.\n"
			 << "2: Arrange all objects by volume.\n"
			 << "3: Arrange all objects by area.\n"
			 << "4: View statistics report.\n"
			 << "5: Reinitialize all objects.\n"
			 << "6: Exit\n"
			 << endl
			 << "What would you like to do? [1-6]: ";

		while( !(cin >> choice)	 ||
				choice < 1 		 ||
				choice > 6		 ||
				cin.get() != '\n' ){
			cin.ignore(1000, '\n');

		cout << "Welcome to the Main Menu!\n"
			 << endl
			 << "1: Print a report of all objects.\n"
			 << "2: Arrange all objects by volume.\n"
			 << "3: Arrange all objects by area.\n"
			 << "4: View statistics report.\n"
			 << "5: Reinitialize all objects.\n"
			 << "6: Exit\n"
			 << endl
			 << "What would you like to do? [1-6]: ";

		}

		cout << endl;

		switch(choice) {

		case 1: report(geometryArray, numObjects);	
				break;

		case 2: sortVolume(geometryArray, numObjects);	
				break;

		case 3: sortSurface(geometryArray, numObjects);
				break;

		case 4: statistics(geometryArray, numObjects);	
				break;

		case 5: remove(geometryArray, numObjects);
				create(geometryArray, numObjects);	
				break;

		case 6:	break;

		}

		cout << endl;

	}

	remove(geometryArray, numObjects);

	return 0;
}

//Generate a report on the provided object.
void report(Geometry* geometry) {

	//static int numObjects = 1;
	int index;

	//Print out the header, type, and name of the object.
	cout << setw(15) << right << "----------------------\n"
		 << "Object Type: " << geometry->getType() << endl
		 << "Object Name: " << geometry->getName() << endl;

	//Decide which type of object we are reporting on, and print out relevant data.
	if(strcmp(geometry->getType(), "Box") 			== 0) { index = 0; }
	if(strcmp(geometry->getType(), "Rectangle") 	== 0) { index = 1; }
	if(strcmp(geometry->getType(), "Sphere") 		== 0) { index = 2; }
	if(strcmp(geometry->getType(), "Circle") 		== 0) { index = 3; }
	if(strcmp(geometry->getType(), "Tetrahedron") 	== 0) { index = 4; }
	if(strcmp(geometry->getType(), "Triangle") 		== 0) { index = 5; }

	switch(index) {

		case 0:
		case 2:
		case 4:
			cout << "Volume: " << fixed << setprecision(2) << geometry->computeVolume() << endl << "Surface ";
		case 1:
		case 3:
		case 5:
			cout << "Area: " << fixed << setprecision(2) << geometry->computeSurface() << endl;
			break;

		default:
			cout << "Unknown object type.\n";
			break;
	}

	//Print out the footer.
	cout << "----------------------\n\n";

	return;
}
//Or all objects.
void report(Geometry** geometryArray, int& numObjects) {

	for(int i=0; i<numObjects; i++) { report(geometryArray[i]); }

	return;
}

//Initialize objects.
void create(Geometry**& geometryArray, int& numObjects) {

	int choice;
	char* tempName = new char [30];
	double temp1, temp2, temp3;

	//Decide how many objects to create.
	cout << "How many objects would you like to create? ";
	while( !(cin >> numObjects) || numObjects < 0 || cin.get() != '\n' ) {
		cin.ignore(1000, '\n');
		cout << "How many objects would you like to create? ";
	}

	//Allocate memory for the array.
	geometryArray = new Geometry* [numObjects];

	//Ask user to create each object.
	for(int i=0; i<numObjects; i++) {

		cout << endl;

		//Ask for selection of object type.
		cout << "------------------Object Types-----------------\n"
			 << "1: Rectangular Prism    2: Rectangle\n"
			 << "3: Sphere               4: Circle\n"
			 << "5: Regular Tetrahedron  6: Equilateral Triangle\n"
			 << endl
			 << "What kind of object would you like to make?\n";
		while( !(cin >> choice) || choice < 1 || choice > 6 || cin.get() != '\n' ) {
			cin.ignore(1000, '\n');
			cout << "Unable to process selection. Please try again. [1-6] :";
		}

		//Ask for additional data based on object type.
		switch(choice) {

		case 1:
			cout << "What is the name of your new rectangular prism? ";
			cin.getline(tempName, 30);

			cout << "Please input the length, width, and height of the prism. [LENGTH, WIDTH, HEIGHT]: ";
			while(  !(cin >> temp1 >> temp2 >> temp3) 	||
					temp1 < 0 							||
					temp2 < 0 							|| 
					temp3 < 0 							||
					cin.get() != '\n' 					 ){
				cin.ignore(1000, '\n');

				cout << "Those are invalid dimensions for your prism. \n"
					 << "Please input new dimensions. [LENGTH, WIDTH, HEIGHT]: ";

			}					 
			
			//Create the object. Yea!
			geometryArray[i] = new Box(tempName, temp1, temp2, temp3);
			
			break;

		case 2:
			cout << "What is the name of your new rectangle? ";
			cin.getline(tempName, 30);

			cout << "Please input the length and width of the rectangle. [LENGTH, WIDTH]: ";
			while(  !(cin >> temp1 >> temp2) ||
					temp1 < 0 				 ||
					temp2 < 0 				 || 
					cin.get() != '\n' 		  ){
				cin.ignore(1000, '\n');

				cout << "Those are invalid dimensions for your rectangle. \n"
					 << "Please input new dimensions. [LENGTH, WIDTH]: ";

			}					 
			
			//Create the object. Yea!
			geometryArray[i] = new Rectangle(tempName, temp1, temp2);
			
			break;

		case 3:
			cout << "What is the name of your new sphere? ";
			cin.getline(tempName, 30);

			cout << "Please input the radius of the sphere. [RADIUS]: ";
			while(  !(cin >> temp1) 	||
					temp1 < 0 			||
					cin.get() != '\n' 	 ){
				cin.ignore(1000, '\n');

				cout << "That is an invalid radius for your sphere. \n"
					 << "Please input a new radius. [RADIUS]: ";

			}					 
			
			//Create the object. Yea!
			geometryArray[i] = new Sphere(tempName, temp1);
			
			break;

		case 4:
			cout << "What is the name of your new circle? ";
			cin.getline(tempName, 30);

			cout << "Please input the radius of the circle. [RADIUS]: ";
			while(  !(cin >> temp1) 	||
					temp1 < 0 			||
					cin.get() != '\n' 	 ){
				cin.ignore(1000, '\n');

				cout << "That is an invalid radius for your circle. \n"
					 << "Please input a new radius. [RADIUS]: ";

			}					 
			
			//Create the object. Yea!
			geometryArray[i] = new Circle(tempName, temp1);
			
			break;

		case 5:
			cout << "What is the name of your new tetrahedron? ";
			cin.getline(tempName, 30);

			cout << "Please input the side length of the tetrahedron. [SIDE LENGTH]: ";
			while(  !(cin >> temp1) 	||
					temp1 < 0 			||
					cin.get() != '\n' 	 ){
				cin.ignore(1000, '\n');

				cout << "That is an invalid side length for your tetrahedron. \n"
					 << "Please input a new side length. [LENGTH]: ";

			}					 
			
			//Create the object. Yea!
			geometryArray[i] = new Tetrahedron(tempName, temp1);
			
			break;

		case 6:
			cout << "What is the name of your new triangle? ";
			cin.getline(tempName, 30);

			cout << "Please input the side length of the triangle. [SIDE LENGTH]: ";
			while(  !(cin >> temp1) 	||
					temp1 < 0 			||
					cin.get() != '\n' 	 ){
				cin.ignore(1000, '\n');

				cout << "That is an invalid side length for your triangle. \n"
					 << "Please input a new side length. [LENGTH]: ";

			}					 
			
			//Create the object. Yea!
			geometryArray[i] = new Triangle(tempName, temp1);
			
			break;

		default: 
			//Bad things went down. Delete the array and EXIT FAILURE!
			cout << "A fatal error occured while determining object type.\n";

			for(int j=i; j>=0; j--) { delete geometryArray[j]; }
			delete geometryArray;

			exit(EXIT_FAILURE);

		}

	}

	delete tempName;

	return;
}
//Or set to defaults.
void create(Geometry**& geometryArray, int& numObjects, bool b) {

	numObjects = 6;

	geometryArray = new Geometry* [numObjects];
	geometryArray[0] = new Box("Boxen", 2, 2, 2);
	geometryArray[1] = new Rectangle("Rectangulen", 2, 2);
	geometryArray[2] = new Sphere("Planet", 2);
	geometryArray[3] = new Circle("Plate", 2);
	geometryArray[4] = new Tetrahedron("Trigon Trifecta", 2);
	geometryArray[5] = new Triangle("Gold Trigon", 2);

	return;
}

//Deallocate memory for the objects.
void remove(Geometry**& geometryArray, int& numObjects) {

	cout << "Deleting begin. \n";

	//delete geometryArray[0];

	for(int i=0; i<numObjects; i++) { delete geometryArray[i]; }
	cout << "One Deleted\n";

	delete[] geometryArray;
	numObjects = 0;

	return;
}

//Print out the statistical report.
void statistics(Geometry** geometryArray, int& numObjects) {

	double average;
	double total;

	cout << "------------------Statistical Report---------------------\n";

	//Compute the average volume
	average = 0;
	total = 0;

	for(int i=0; i<numObjects; i++) { 
		if(geometryArray[i]->computeVolume() == 0) continue;
		total += geometryArray[i]->computeVolume(); 
	}
	average = total / static_cast<double> (numObjects);

	cout << "The average volume of your 3D objects is: " << average << " units.\n";

	//Compute the average area/surface area
	for(int i=0; i<numObjects; i++) { total += geometryArray[i]->computeSurface(); }
	average = total / static_cast<double> (numObjects);

	cout << "The average surface area of your objects is: " << average << " units.\n";

	cout << "---------------------------------------------------------\n";

	return;
}

//Sort the array by volume.
void sortVolume(Geometry**& geometryArray, int& numObjects) {

	int smallestIndex = 0;
	Geometry* swapValue;

	//We'll use a selection sort here.
	for(int i=(numObjects - 1); i>0; i--) {
		int smallestIndex = 0;

		for(int j=1; j<=i; j++) {

			if( (geometryArray[j]->computeVolume()) > (geometryArray[smallestIndex]->computeVolume()) ) smallestIndex = j;

		}

		swapValue = geometryArray[smallestIndex];
		geometryArray[smallestIndex] = geometryArray[i];
		geometryArray[i] = swapValue;

	}

	return;
}
//Or by Area/Surface Area.
void sortSurface(Geometry**& geometryArray, int& numObjects) {

	int smallestIndex = 0;
	Geometry* swapValue;

	//We'll use a selection sort here.
	for(int i=(numObjects - 1); i>0; i--) {
		int smallestIndex = 0;

		for(int j=1; j<=i; j++) {

			if( (geometryArray[j]->computeSurface()) > (geometryArray[smallestIndex]->computeSurface()) ) smallestIndex = j;

		}

		swapValue = geometryArray[smallestIndex];
		geometryArray[smallestIndex] = geometryArray[i];
		geometryArray[i] = swapValue;

	}

	return;
}