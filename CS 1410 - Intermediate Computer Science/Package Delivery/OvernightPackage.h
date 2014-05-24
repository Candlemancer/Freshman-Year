//Jonathan Petersen
//A01236750
//Package delivery system
//Two-Day Package Class

#include <string>
//#include "Package.h"

class OvernightPackage : public Package {

public:
	OvernightPackage();
	OvernightPackage(Person, Person, double, double, double);
	virtual string getTypeOf();
	virtual double getCostOf();
	//virtual int getPkgToDate() 	{return onPkgToDate;}

protected:
	double costUp;
	//static int onPkgToDate;

};

////////////////////////////////////////////////////////////////////////

//Print label to the stream.
ostream& operator<< (ostream& out, OvernightPackage pkg) {

	out << "=======OVERNIGHT PACKAGE======\n"
	    << pkg.printLabel()
	    << "==============================\n"
	    << endl;

	return out;
}
