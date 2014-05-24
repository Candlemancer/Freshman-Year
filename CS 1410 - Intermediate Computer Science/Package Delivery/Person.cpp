//Jonathan Petersen
//A01236750
//Package delivery system
//Person Class Implementation

#include "Person.h"

//Empty Person
Person::Person() {
	name  = "NONE";
	addr  = "NONE";
	city  = "NONE";
	state = "NONE";
	zip   = "NONE";
}

//Initialize Person
Person::Person(string n, string a, string c, string s, string z) {
	name  = n;
	addr  = a;
	city  = c;
	state = s;
	zip   = z;
}

string Person::getName() {
	return name;
}

string Person::getAddr() {
	return addr; 
}

string Person::getCity() {
	return city; 
}

string Person::getState() {
	return state;
}

string Person::getZip()   {
	return zip;  
}