// Jonathan Petersen
// A01236750
// Friend Database
// Main

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

#include "Friend.cpp"




int main() {

	enumerations::menuOptions choice = enumerations::_;
	fstream file;

	//Read Friend Info from file
	if( fileOverwrite() ) file.open( "myNetwork.dat", fstream::in | fstream::out | fstream::binary | fstream::trunc );
	else				  file.open( "myNetwork.dat", fstream::in | fstream::out | fstream::binary );

	//Print the menu
	while (choice != 7) {
		cout << "Welcome to the main menu! Please enter a choice below.\n"
			 << "A: Add a new friend\n"
			 << "D: Delete a friend by ID number\n"
			 << "M: Modify a friend by ID number\n"
			 << "S: Search interests\n"
			 << "PD: Print the \"myNetwork.dat\" friend database\n"
			 << "PO: Print information on the oldest and youngest friends\n"
			 << "E: Exit\n";
		cout << "What would you like to do: ";
		cin.clear();
		cin.sync();

		cin >> choice;

		//cout << "Choice: " << choice << endl;

		switch (choice) {
			
			//Add a Friend
			case enumerations::A:
				cout << "Creating Friend\n";
				addFriend(file);
				break;
			
			//Delete a Friend by ID
			case enumerations::D:
				cout << "Deleting Friend\n";
				remFriend(file);
				break;
			
			//Modify a Friend by ID
			case enumerations::M:
				cout << "Modifying Friend\n";
				break;

			//Search by Interests
			case enumerations::S:
				cout << "Searching Friend\n";
				break;

			//Print the Database Information
			case enumerations::PD:
				cout << getNumFriends(file) << endl;
				cout << "Printing Database\n";
				break;

			//Print the Oldest and Youngest Friends
			case enumerations::PO:
				cout << "Printing Oldest and Youngest\n";
				break;

			//Exit
			case enumerations::E:
				cout << "Exiting\n";
				break;

			default:
				cout << "Invalid Menu Option. Please Try Again.\n";
				break;

		}

		cout << endl;

	}


	file.close();
	return 0;
}

