#include "Friend.h"
#include <iostream>


using namespace std;

int main() {
	//Variable Definition
	const int SIZE = 10;
	char choice = '!';

	//Get the Array ready.
	Friend friends[SIZE];
	IniFriend(friends, SIZE);

	//Create the Main Menu.
	while (choice != 'E') {
		cout << endl
			 << "*** Network of My Friends ***\n"
			 << "A: Add a Friend\n"
			 << "R: Remove a Friend\n"
			 << "S: Search Interests\n"
			 << "D: Display All Friends\n"
			 << "L: List All Friends in Alphabetic Order Based on ScreenName\n"
			 << "C: Calculate the Average Age of All Friends in My Network\n"
			 << "E: Exit\n"
			 << endl
			 << "Selection: ";
		cin.get(choice);
		cin.ignore(1000, '\n');
		cin.sync();
		choice = toupper(choice);

		switch (choice) {

		case 'A': AddFriend(friends, SIZE); break;
		case 'R': RemFriend(friends, SIZE); break;
		case 'S': FindLikes(friends, SIZE); break;
		case 'D': AlphaSort(friends, SIZE); break;
		case 'L': AlphaSort(friends, SIZE); break;
		case 'C': 
			cout << "The average age of your friends is " << AgeStats (friends, SIZE) << ".\n";
			break;
		case 'E':                           
			break;
		default: 
			cout << "Please try again later.\n"; 
			break;

		}
	}


	return 0;
}
