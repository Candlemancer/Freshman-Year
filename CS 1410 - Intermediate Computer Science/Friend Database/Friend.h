// Jonathan Petersen
// A01236750
// Friend Database
// Friend Function Headers

//Friend Structure
struct Friend {
	char name[30];
	char interests[100];
	short age;
};

namespace enumerations {
	enum menuOptions {
		A  = 1,
		D  = 2,
		M  = 3,
		S  = 4,
		PD = 5,
		PO = 6,
		E  = 7,
		_  = 0
	};	
}

//Various top-level functions
void addFriend(fstream&);
void remFriend(fstream&);
//void modFriend();
//void searchInterests();
//void printFriends();
//void printOldestYoungest();

//Various low-level functions
int getNumFriends(fstream&);
bool fileExists();
bool fileOverwrite();

istream& operator>>(istream& is, enumerations::menuOptions& choice);
