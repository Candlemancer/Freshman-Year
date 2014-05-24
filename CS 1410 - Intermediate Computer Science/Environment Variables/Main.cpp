// Jonathan Petersen
// A01236750
// Environment Analysis
// Main 

#include <iostream>
#include <sstream>

//Multiplatform #include's 
#ifdef _WIN32
#include "Environment.h"

#else
#include "Environment.cpp"

#endif

using namespace std;




int main() {

	stringstream ss;

	//Read In Variables
	getEVars(ss);

	//Convert Input to Words
	getWords(ss);

//	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
//	cout << ss.str() << endl;
//	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	//Output word analysis
	analysis(ss);

	//Search for User Input
	userFind(ss);

	return 0;
}