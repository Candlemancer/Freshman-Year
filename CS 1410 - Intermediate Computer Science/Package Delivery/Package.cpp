//Jonathan Petersen
//A01236750
//Package delivery system
//Package Class Implementation

#include <sstream>
#include "Package.h"

//Default Constructor for Package
Package::Package() { 
	sender = Person();
	recver = Person();
	weight = 0.0 ;
	ozRate = 0.00;

	//pkgToDate = 0;
	//pkgToDate++;
}

//Constructor for Package
Package::Package(Person send, Person recv, double wegt, double rate) {
	sender = send;
	recver = recv;
	weight = wegt;
	ozRate = rate;

	//pkgToDate = 0;
	//pkgToDate++;
}

string Package::getTypeOf()	{
	return "Standard";
}
	
double Package::getCostOf() {
	return weight * ozRate;
}


//Print out info about the Package
string Package::printLabel() {

	stringstream temp;

	temp << "FROM ADDRESS:\n"
		 << sender.getName()  << endl
		 << sender.getAddr()  << endl
		 << sender.getCity()  << endl
		 << sender.getState() << endl
		 << sender.getZip()   << endl
		 << endl
		 << "TO ADDRESS:\n"
		 << recver.getName()  << endl
		 << recver.getAddr()  << endl
		 << recver.getCity()  << endl
		 << recver.getState() << endl
		 << recver.getZip()   << endl
		 << endl
		 << "WEIGHT (OZ): " << weight
		 << endl;

	return temp.str();
}