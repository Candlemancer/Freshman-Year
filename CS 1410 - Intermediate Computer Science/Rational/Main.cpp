//Jonathan Petersen
//A01236750
//Rational Fractions
#include "Rational.h"
#include <iostream>


using namespace std;

int main() {

//Personal Driver Code
/*
	Rational a;
	Rational b(1);
	Rational c(35,30);
	Rational d("2/3");
	Rational e(c);


	//Assignment Ops
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	e = d;
	d = 5;
	c = "6/7";

	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	//Addition Ops
	c = b + b;
	d = b + 100;
	e = b + "2/2";

	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	//Compound Ops

	c += b;
	d += 12;
	e += "9/8";

	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	cout << (c == c) << endl;
	cout << (c == d) << endl;
	cout << (c > d) << endl;

	cout << c++ << endl;
	cout << ++d << endl;
	cout << c << endl;
*/

/*
//Dr. Qi's Driver Code.
Rational a;													// default to 0/1
Rational b(a) ;												// 0/1
Rational c(3) ;
Rational d(2, 3);
Rational e("2/4");

b = a + c ; 
a = 2 + c ; 
d = e + 4 ; 

cin >> a;													// user enters 6/8,
cout << a << endl ;											// output is 3/4
a += 2 ;
//b = 3 + a; 													// Hint: You need to implement one outside function to accomplish the task
cout << b++;												// output is 23/4
cout << b << endl;											// output is 27/4

b = 12;
cout << b << endl;											// output is 12
double x = b; 												// where b = 3/2.
*/


//F'real Driver Code.

	Rational a;
	Rational b(6553542);
	Rational c("45/15");
	Rational d("1/420");
	Rational e( c + d );

	cout << "Constructor Demo        \n"
	     << "========================\n"
	     << "Fraction A = " << a << endl
	     << "Fraction B = " << b << endl
	     << "Fraction C = " << c << endl
	     << "Fraction D = " << d << endl
	     << "Fraction E = " << e << endl;

	cout << endl;

	cin >> a;
	b = 1337;
	c = "2013/1024";
	d = "435801";
	e = e;

	cout << endl;

	cout << "Assignment Demo         \n"
	     << "========================\n"
	     << "Fraction A = Assigned   \n"
	     << "Fraction A = " << a << endl
	     << "Fraction B = 1337       \n"
	     << "Fraction B = " << b << endl
	     << "Fraction C = 2013/1024  \n"
	     << "Fraction C = " << c << endl
	     << "Fraction D = 435801     \n"
	     << "Fraction D = " << d << endl
	     << "Fraction E = Fraction E \n"
	     << "Fraction E = " << e << endl;


	cout << endl;


	cout << "Arithmetic Binary Demo  \n"
		 << "========================\n"
		 << "Fraction A + Fraction C \n"
	//     << " = "       << a + c << endl
	     <<	"Fraction B + Fraction D \n"
	//     << " = "       << b + d << endl
	     << "Fraction E + 7          \n"
	//     << " = "       << e + 7 << endl
	     << "Fraction D + 1/13       \n"
	//     << " = "  << d + "1/13" << endl
	     << "2/9 + Fraction C        \n"
	     << " = "  << "2/9" + c << endl;

	cout << endl;

	a += b;
	b += 56;
	c += "1/365";
	d += "35/30";
	e += -100000;

	cout << "Compound Assignment Demo\n"
		 << "========================\n"
		 << "Fraction A += Fraction B\n"
 	     << "Fraction A = " << a << endl
 	     << "Fraction B += 56        \n"
	     << "Fraction B = " << b << endl
	     << "Fraction C += 1/365     \n"
	     << "Fraction C = " << c << endl
	     << "Fraction D += 35/30     \n"
	     << "Fraction D = " << d << endl
	     << "Fraction E += -100000   \n"
	     << "Fraction E = " << e << endl;


	cout << endl;


	cout << "Relational Operator Demo\n"
		 << "========================\n"
	     << "Fraction A == Fraction B\n"
	     << " = "      << (a==b) << endl
	     << "Fraction B >  Fraction D\n"
	     << " = "      << ( b>d) << endl
	     << "Fraction C == Fraction C\n"
	     << " = "      << (c==c) << endl
	     << "Fraction D >  Fraction D\n"
	     << " = "      << ( d>d) << endl
	     << "Fraction E <= Fraction A\n"
	     << " = "      << (!e>a) << endl;


	cout << endl;


    cout << "Prefix/Postfix Demo     \n"
    	 << "========================\n"
	     << "Fraction A = Fraction A+\n"
	     << " = "         << a++ << endl
	     << "Fraction A = " << a << endl
	     << "Fraction C = Fraction +C\n"
	     << " = "         << ++c << endl
	     << "Fraction C = " << c << endl;


	cout << endl;


    cout << "The final sum is:       \n"
    	 << "========================\n"
    	 << (double) (a+b+c+d+e) << endl;

	cout << endl;

	return 0;
}