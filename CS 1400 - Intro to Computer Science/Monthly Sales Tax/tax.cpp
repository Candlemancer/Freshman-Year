// Jonathan Petersen
// A01236750
// Monthly Sales Tax

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

	const float countyRate = 0.02;
	const float stateRate  = 0.04;
	const float totalRate  = countyRate + stateRate;
	float totalAmt  = 0;
	float grossTax  = 0;
	float stateTax  = 0;
	float countyTax = 0;
	float beforeTax = 0;
	int   year   =   -1;
	string month =   "";

	cout << "Welcome to Taxmaster Pro!\n";

	//Process inputs
	cout << "Please input the current year: [xxxx] ";
	cin  >> year;
	cin.clear();
	cin.ignore();
	while(year  <= 0     ||
      	      year  >= 10000  ){
		cout << "Invalid year. Please try again.\n";
		cout << "Year: [xxxx] ";
		cin  >> year;
		cin.clear();
		cin.ignore();
	}
	cout << "Please input the current month: [January] ";
	cin  >> month;
	while(month != "January"  &&
	      month != "February" &&
	      month != "March"    &&
	      month != "April"    &&
	      month != "May"      &&
	      month != "June"     &&
	      month != "July"     &&
	      month != "August"   &&
	      month != "September"&&
	      month != "October"  &&
	      month != "November" &&
	      month != "December"  ){
		cout << "Invalid month. Please try again.\n";
		cout << "Month: [January] ";
		cin >> month;
		cin.clear();
		cin.ignore();
	}
	cout << "Please input the total amount from cashdrawers: [xxxx.xx] $";
	cin  >> totalAmt;

	//Calculate Tax Percentages
	grossTax  = (totalAmt / (1 +  totalRate));
	stateTax  = (totalAmt / (1 +  stateRate));
	countyTax = (totalAmt / (1 + countyRate));

	//Calculate Earnings before Tax
	beforeTax = (totalAmt - grossTax);

	//Format and return output
	cout << endl << fixed << setprecision(2);
	cout << "Month: " << setw(9) << right << month << " " << year << endl;
	cout << "---------------------\n";
	cout << "Total Collected:   $" << right << setw(10) << totalAmt << endl;
	cout << "Sales:             $" << right << setw(10) << beforeTax<< endl;
	cout << "County Sales Tax:  $" << right << setw(10) << countyTax<< endl;
	cout << "State Sales Tax:   $" << right << setw(10) << stateTax << endl;
	cout << "Total Sales Tax:   $" << right << setw(10) << grossTax << endl;

	return 0;

}
