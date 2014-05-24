//Jonathan Petersen
//A01236750
//Package delivery system
//Two-Day Package Class
//Implementation Below

#include <string>
//#include "Package.h"

class TwoDayPackage : public Package {

public:
	TwoDayPackage();
	TwoDayPackage(Person, Person, double, double, double);
	virtual string getTypeOf()		{cout << "td" << endl; return "Two-Day";}
	virtual double getCostOf() 		{cout << "td" << endl; return weight * (ozRate + ozPlus);}
	//virtual int getPkgToDate() 	{return tdPkgToDate;}

protected:
	double ozPlus;
	//static int tdPkgToDate;

};

////////////////////////////////////////////////////////////////////////

//Print label to the stream.
ostream& operator<< (ostream& out, TwoDayPackage pkg) {

	out << "=======TWO DAY PACKAGE========\n"
	    << pkg.printLabel()
	    << "==============================\n"
	    << endl;

	return out;
}

