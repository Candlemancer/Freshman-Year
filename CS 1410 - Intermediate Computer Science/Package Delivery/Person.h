//Jonathan Petersen
//A01236750
//Package delivery system
//Person Class Header
//Implementation Below

#include <string>

using namespace std;

class Person {

public:
	Person();
	Person(string, string, string, string, string);
	string getName();
	string getAddr();
	string getCity();
	string getState();
	string getZip();


private:
	string name;
	string addr;
	string city;
	string state;
	string zip;

};