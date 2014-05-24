// Jonathan Petersen
// A01236750
// Friend Database
// Friend Function Implementation

#include "Friend.h"

//Add a friend
void addFriend(fstream& file) {

	Friend newFriend;
	char temp[100];
	int tempInt = 0;

	cout << "What is your new friend's name? ";
	cin.clear();
	cin.sync();
	cin.getline(newFriend.name, sizeof(newFriend.name));

	cout << "What are your new friend's interests? ";
	cin.clear();
	cin.sync();
	cin.getline(newFriend.interests, sizeof(newFriend.interests));

	cout << "What is your new friend's age? ";
	cin.clear();
	cin.sync();
	while( !(cin >> newFriend.age) || cin.get() != '\n' ) {
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Inalid age. Please enter an appropriate age: ";
	}
	cout << endl;

	//Prepare to append friend.
	file.seekp(0, ios_base::end);

	//Write blanks first, then go back and fill in data.
	file.write("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", sizeof(newFriend.name));
	file.seekp( -30 , ios_base::cur);
	file.write(newFriend.name, strlen(newFriend.name));
	file.seekp(0, ios_base::end);

	file.write("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", sizeof(newFriend.interests));
	file.seekp( -100 , ios_base::cur);
	file.write(newFriend.interests, strlen(newFriend.interests));
	file.seekp(0, ios_base::end);

	file.write("\0\0", sizeof(newFriend.age));
	file.seekp( -2 , ios_base::cur);
	file.write( reinterpret_cast<char*> (&newFriend.age), 2);
	file.seekp(0, ios_base::end);

	cout << "The ID of the Friend you just entered is: " << getNumFriends(file) << endl;

 /*
	cout << newFriend.name << endl;
	cout << newFriend.interests << endl;
	cout << newFriend.age << endl;

	file.seekg( -2, ios_base::cur);

	file.read(temp, 30);
	cout << endl << temp << endl;
	file.read(temp, 30);
	cout << temp << endl;
	file.read(temp, 30);
	cout << temp << endl;
	file.read(temp, 30);
	cout << temp << endl;
	file.read(temp, 10);
	cout << temp << endl;

	file.read( reinterpret_cast<char*>(&tempInt), sizeof(short int));
	cout << endl << tempInt << endl;
 */
	return;
}

//Remove a friend
void remFriend(fstream& file) {

	int id;
	int size;
	int count = 0;
	char temp[30];
	char copy;
	fstream atomic("myNetwork.atm", fstream::out | fstream::binary | fstream::trunc );

	//Ask user for an ID
	cout << "Please enter the ID of the friend you wish to delete,\n or 0 to quit: ";
	cin.clear();
	cin.sync();
	//Verify input
	while( !(cin >> id) || id < 0 || id > getNumFriends(file) || cin.get() != '\n') {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid ID. Please enter a new ID, or 0 to quit: ";
	}

	if (id == 0) {atomic.close(); remove("myNetwork.atm"); return;}

	//Move to the selected friend
	id = --id * sizeof(Friend);
	file.seekg(id);
	file.read(temp, sizeof Friend().name);
	cout << "Are you sure you want to delete " << temp << "? This is the point of no return. [Y/N] ";

	//Create atomic save
	file.seekg(0, ios_base::end);
	size = file.tellg();

	file.seekg(0);
	atomic.seekp(0);
	for(int i=0; i<id; i++) {
		file.read(&copy, 1);
		atomic.write(&copy, 1);
		count++;
	}
	cout << "Wrote " << count << " bytes of data.\n";
	count = 0;
	for(int i=(id + sizeof(Friend)); i<=size; i++) {
		file.read(&copy, 1);
		atomic.write(&copy, 1);		
		count++;
	}
	cout << "Wrote " << count << " bytes of data.\n";
	

	//And replace the originial file with the atomic.
	file.close();
	atomic.close();

	remove("myNetwork.dat");
	rename("myNetwork.atm", "myNetwork.dat");

	//And reopen the file for business.
	file.open( "myNetwork.dat", fstream::in | fstream::out | fstream::binary );
	
	return;
}


//Return the number of friends in the file.
int getNumFriends(fstream& file) {

	double size;

	//Reset the file
	file.flush();
	file.clear();	
	file.seekp(0);
	file.seekg(0);

	//Get the lenght of the file
	file.seekp(0, ios_base::end);
	size = static_cast<double> (file.tellp());

	//Divide by the length of the friend objects.
	size = size / sizeof(Friend);

	//Re-reset the file.
	file.clear();
	file.seekp(0);

	return size;
}

//Checks if the network file exists.
bool fileExists() {

	fstream file("myNetwork.dat");
	return file;
}

//Prompts user to overwrite the file if it does.
bool fileOverwrite() {

	char choice;
	fstream file;

	//Check if file needs to be overwritten
	if(fileExists()) {
		cout << "\nmyNetwork.dat already exists, overwrite? [Y/N]: ";
		cin >> choice;

		//Validate Input
		//cout << "Choice: " << choice << endl;
		while(choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y') {
			cout << "Invalid input. Do you want to overwrite \"myNetwork.dat\"? [Y/N]: ";
			cin >> choice;
		}

		cout << endl;

	}

	if(choice == 'y' || choice == 'Y') return true;
	if(choice == 'n' || choice == 'N') return false;

	return true;
}

//Overloaded Instertion Operator for Enums
istream& operator>>(istream& is, enumerations::menuOptions& choice) {

    string text;

    //cout << "Stringing.\n";

    if (is >> text) {

    	//cout << "String : " << text << endl;

        if (text == "a" || text == "A") { choice = enumerations::A; return is; }
        if (text == "d" || text == "D") { choice = enumerations::D; return is; }
        if (text == "m" || text == "M") { choice = enumerations::M; return is; }
        if (text == "s" || text == "S") { choice = enumerations::S; return is; }
        if (text == "e" || text == "E") { choice = enumerations::E; return is; }
        if (text == "pd" || text == "pD" || text == "Pd" || text == "PD") { choice = enumerations::PD; return is; }
        if (text == "po" || text == "pO" || text == "Po" || text == "PO") { choice = enumerations::PO; return is; }

        choice = enumerations::_;
    }

    return is;
}
