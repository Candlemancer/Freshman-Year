//Jonathan Petersen
//A01236750
//Package delivery system
//Main Class

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Person.cpp"
#include "Package.cpp"
#include "TwoDayPackage.cpp"
#include "OvernightPackage.cpp"

void readPkgs(stringstream&, int&);
void makePkgs(stringstream&, int, Package*); 
void workPkgs(int, Package*);

int main() {
	//Variable Declarations
	stringstream ss;
	int numPkgs = 0;
	Package* pkgArray;

	//Handle File Operations
	readPkgs(ss, numPkgs);
	//Allocate Memory for Packages
	pkgArray = new Package [numPkgs];
	//Create Package Objects
	makePkgs(ss, numPkgs, pkgArray);
	//Print Labels and Gather Data
	workPkgs(numPkgs, pkgArray);
	//Free Memory from Array
	delete[] pkgArray;

	return 0;
}

//////////////////////////////////////////////////////////////////

//Read the file into formatted data.
void readPkgs(stringstream &ss, int &numPkgs) {
	//Variable Declarations
	ifstream fin;
	char pkgType;
	string temp;

	//Open file and verify.
	fin.open("package.txt");
	if(!fin) {cout << "Unable to open file\n"; exit(EXIT_FAILURE);}

	while(!fin.eof()) {
		//Determine type of package - LINE 1
		fin >> pkgType;
		cout << "Original PkgType: " << pkgType << endl;
		fin.ignore(1000, '\n');
		pkgType = toupper(pkgType);
		ss << pkgType << endl;

		//Read data into stringstream - LINES 2 - 13
		for(int i=0; i<12; i++) {
			getline(fin, temp);
			ss << temp << endl;
		}

		//Possible 14th line.
		cout << "PkgType: " << pkgType << endl;
		if(pkgType != 'P') {
			getline(fin, temp);
			ss << temp << endl;
			cout << "14th: " << temp << endl;
		}

		numPkgs++;
		cout << numPkgs << endl << endl;
		fin.peek();
	}

	fin.close();
	return;
}

//Make the package objects from the data
void makePkgs(stringstream &ss, int numPkgs, Package *pkgArray) {

	char pkgType;
	double tempWeight = 0;
	double tempOzRate = 0;
	double tempOthers = 0;
	string tempName  = "NONE";
	string tempAddr  = "NONE";
	string tempCity  = "NONE";
	string tempState = "NONE";
	string tempZip   = "NONE";
	Person *send, *recv;

	//Create Package objects
	for(int i=0; i<numPkgs; i++) {

		//Read in Package Type
		ss >> pkgType;

		//Read in the weight and ozRate
		ss >> tempWeight;
		ss >> tempOzRate;
		ss.ignore(1000, '\n');

		//Initialize the sender Person
		getline(ss, tempName );
		getline(ss, tempAddr );
		getline(ss, tempCity );
		getline(ss, tempState);
		getline(ss, tempZip  );

		send = new Person(tempName, tempAddr, tempCity, tempState, tempZip);

		//Initialize the recver Person
		getline(ss, tempName );
		getline(ss, tempAddr );
		getline(ss, tempCity );
		getline(ss, tempState);
		getline(ss, tempZip  );

		recv = new Person(tempName, tempAddr, tempCity, tempState, tempZip);

		//Create the Package Object
		switch(pkgType) {
		case 'P':
			pkgArray[i] = Package(*send, *recv, tempWeight, tempOzRate);
			break;

		case 'T':
			ss >> tempOthers;
			ss.ignore(1000, '\n');
			pkgArray[i] = TwoDayPackage(*send, *recv, tempWeight, tempOzRate, tempOthers);
			break;

		case 'O':
			ss >> tempOthers;
			ss.ignore(1000, '\n');
			pkgArray[i] = TwoDayPackage(*send, *recv, tempWeight, tempOzRate, tempOthers);
			break;

		default:
			cout << "Unable to determine Package Type. Creating generic Package.\n";
			pkgArray[i] = Package();
			break;
		}

		//Clean Up memory.
		delete send;
		delete recv;

	}

	return;
}

//Work the Packages, producing shipping labels and cost to ship.
void workPkgs(int numPkgs, Package *pkgArray) {

	double total = 0.0;
	int stdPkgs  = 0;
	int tdPkgs   = 0;
	int onPkgs   = 0;

	for(int i=0; i<numPkgs; i++) {
		//Print Shipping Label
		cout << pkgArray[i] << endl;
		//Update Totals
		cout << "Getting cost\n";
		total += pkgArray[i].getCostOf();
		cout << "Cost got\n";
		if(pkgArray[i].getTypeOf() == "Standard" ) {stdPkgs++;}
		if(pkgArray[i].getTypeOf() == "Two-Day"  ) {tdPkgs++; }
		if(pkgArray[i].getTypeOf() == "Overnight") {onPkgs++; }
	}

	//Print footer.
	cout << "TOTAL COST OF SHIPPING: $" << fixed
		 << setprecision(2) << total << endl << endl
		 << "TOTAL NUMBER OF STANDARD PACKAGES:  " 
		 << stdPkgs << endl
		 << "TOTAL NUMBER OF TWO-DAY PACKAGES:   " 
		 << tdPkgs << endl
		 << "TOTAL NUMBER OF OVERNIGHT PACKAGES: " 
		 << onPkgs << endl;

	return;
}	