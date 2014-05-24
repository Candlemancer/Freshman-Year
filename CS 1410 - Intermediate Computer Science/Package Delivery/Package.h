//Jonathan Petersen
//A01236750
//Package delivery system
//Package Class Header

#include <string>
#include <iostream>

class Package {

public:
	Package();
	Package(Person, Person, double, double);
	virtual string getTypeOf();
	virtual double getCostOf();
	//virtual int getPkgToDate() 	{return pkgToDate;}
	string printLabel();

protected:
	Person sender;
	Person recver;
	double weight;
	double ozRate;
	//static int pkgToDate;

};

/////////////////////////////////////////////////////////////////////

//Print label to the stream.
ostream& operator<< (ostream& out, Package pkg) {

	out << "=======STANDARD PACKAGE=======\n"
	    << pkg.printLabel()
	    << "==============================\n"
	    << endl;

	return out;
}

