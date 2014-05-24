//Jonathan Petersen
//A01236750
//Package delivery system
//Two-Day Package Class Implementation

#include "OvernightPackage.h"

//Default Constructor for OvernightPackage
OvernightPackage::OvernightPackage() { 
	sender = Person();
	recver = Person();
	weight = 0.0 ;
	ozRate = 0.00;
	costUp = 0.00;

	//onPkgToDate = 0;
	//onPkgToDate++;
}

//Constructor for OvernightPackage
OvernightPackage::OvernightPackage(Person send, Person recv, double wegt, double rate, double cost) {
	sender = send;
	recver = recv;
	weight = wegt;
	ozRate = rate;
	costUp = cost;

	//onPkgToDate = 0;
	//onPkgToDate++;
}

string OvernightPackage::getTypeOf() {
	return "Overnight";
}

double OvernightPackage::getCostOf() {
	return (weight * ozRate) + costUp;
}