//Jonathan Petersen
//A01236750
//Rational Header
#include <string>

using namespace std;

class Rational {

public:
	// Constructors and copy constructor
	Rational() ;
	Rational(int);
	Rational(int, int);
	Rational(string) ;
	Rational(const Rational &);

	// Assignment operators
	Rational& operator=(const Rational&);
	Rational& operator=(const int);
	Rational& operator=(const string);

	// Arithmetic binary operators
	Rational operator+(const Rational&);
	Rational operator+(int);
	Rational operator+(string);

	//Compound assignment operators
	Rational& operator+=(const Rational&);
	Rational& operator+=(int) ;
	Rational& operator+=(string) ;

	// Relational operators
	bool operator==(const Rational &);
	bool operator>(const Rational &);

	// Prefix and Postfix operators
	Rational operator ++ () ;		// prefix ++
	Rational operator ++ (int) ; 	// postfix ++

	// convert a Rational object to a double
	operator double(); 

private:
	//Variables to hold the numerator and denominator.
	int num;
	int dem;
	//Variable for the string representation.
	string fraction;

	//Functions to simiplify the fraction.
	int  solveGCD(int, int);
	void simplify(int&, int&);

	//Function to assign values.
	int  parseStr(string);
	void makeThis(int, int);

	//And since we can't add any public getter or wrapper functions to this class ...
	friend ostream& operator<<(ostream&, Rational);
	friend istream& operator>>(istream&, Rational&);
	friend Rational operator+(const int, const Rational&);
	friend Rational operator+(const string, const Rational&);

};
