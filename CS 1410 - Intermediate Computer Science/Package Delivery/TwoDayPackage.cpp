//Jonathan Petersen
//A01236750
//Package Delivery System
//Two-Day Package Implementation

#include "TwoDayPackage.h"

//Default Constructor for TwoDayPackage
TwoDayPackage::TwoDayPackage() { 
	sender = Person();
	recver = Person();
	weight = 0.0 ;
	ozRate = 0.00;
	ozPlus = 0.00;

	//tdPkgToDate = 0;
	//tdPkgToDate++;
}

//Constructor for TwoDayPackage
TwoDayPackage::TwoDayPackage(Person send, Person recv, double wegt, double rate, double plus) {
	sender = send;
	recver = recv;
	weight = wegt;
	ozRate = rate;
	ozPlus = plus;

	//tdPkgToDate = 0;
	//tdPkgToDate++;
}

