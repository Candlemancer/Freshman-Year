#include "Friend.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

//Return the Mean Age
float AgeStats (Friend friends[], int SIZE){
	float total = 0;
	float count = 0;
	//int i = 0;

	//For each friend, add their ages.
	for (int i=0; i<SIZE; ++i){
		if (friends[i].age) {
			total += friends[i].age;
			count++;
		}
	}

	//Calculate the Average
	return (total / count);
}


//Functions to Add or Remove Friends from the list.

//Add a friend to the List.
void AddFriend (Friend friends[], int SIZE){
	int i = 0;
	string newlike;

	//Find the first empty spot.
	for (i=0; i<=SIZE; i++) {

		//Return an error if no spots were found.
		if (i == SIZE) {
			cout << "You have reached the limit of available friends. \n" << "Please remove some friends and try again. \n";
			return;
		}
	
		//If slot is not empty, continue searching.
		if (friends[i].name != "EMPTY") continue;

		//Otherwise, stop searching and pass on the index value.
		break;
	}

	//Ask user for input. Do not format at this time.
	cout << "What is the name of your new friend? [Issac5671, or Issac Kastigar]\n";
	getline(cin, friends[i].name);
	cout << endl;

	//Okay, this is kind of a mess. I'll explain as we go. First, ask for a new interest ...
	cout << "What interests does your new friend have? [Swimming]\n";
	cout << "You can put in up to " << (MAXLIKES) << " interests, or type \"Q\" to quit.\n";
	for (int j=0; j<MAXLIKES; j++){
		getline(cin, newlike);
		cout << endl;
		//Get the quitters out of here ...
		if (newlike == "q" || newlike == "Q") break;
		//Then, add the new interest to the array of interests associated with this friend slot.
		friends[i].like[j] = newlike;
		//Finally, ask for input again and continue, unless all of the slots for interests have been filled.
		if ((MAXLIKES - (j + 1))){
			cout << "Do you have more interests to add? You have " << (MAXLIKES - (j + 1)) << " spots remaining.\n";
			cout << "(Type in a new interest or \"Q\" to quit.) \n";
		}
	}

	//Ask the user for the age of the friend.	
	cout << "How old is your new friend? [20] \n";
	//Validate input of the new age.
	while (!(cin >> friends[i].age) || friends[i].age < 0 || friends[i].age > 150) {
		cin.clear();
		cin.ignore(1000, '\n');
		cin.sync();
		cout << endl << "Invalid age. Please input a numeric value between 1 and 150. \n";
	}
	cin.clear();
	cin.ignore(1000, '\n');
}

//Remove a friend from the list.
void RemFriend (Friend friends[], int SIZE){
	int remID;
	//Show a list of friends.
	cout << "Which friend would you like to remove? \n";
	SeeFriend(friends, SIZE);

	//Ask for the ID of the friend to remove.
	cout << endl << "Please enter the ID of the friend you wish to delete: ";
	//Validate Input
	while (!(cin >> remID) || remID < 0 || remID > SIZE) {
		cin.clear();
		cin.ignore(1000, '\n');
		cin.sync();
		cout << "That ID could not be found, please try again. [1-" << (SIZE + 1) << "]\n";
	}
	cin.clear();
	cin.ignore(1000, '\n');

	//Adjust for user-readable Text.
	remID--;

	//Remove the friend.
	IniFriend(friends, SIZE, remID);
}

//See all of the friends on the list.
void SeeFriend (Friend friends[], int SIZE){
	//Figure out how wide the Name columns need to be.
	int maxNameLength = 1;
	int nameWhitespace = 5;
	for (int i=0; i<SIZE; i++){
		string tempName = friends[i].name;
		if (tempName.length() > maxNameLength) maxNameLength = tempName.length();
	}
	//Using the longest name size, evenly divide the whitespace on both sides, leaving 4 characters for "NAME" itself.
	nameWhitespace = ceil((maxNameLength - 4) / 2.0); //Adjust this 4 if more space is desired on each side.

	//Print out the header, in two columns if it will fit.
	if (maxNameLength <= 16) {
		cout << " ID " << setw(nameWhitespace) << " " << "NAME" << setw(nameWhitespace) << " "
		     << " ID " << setw(nameWhitespace) << " " << "NAME" << setw(nameWhitespace) << " " 
		     << endl;
		cout << setfill('-') << setw(16 + 4 * (nameWhitespace)) << "-" << endl;
		//And the actual information.
		for (int i=0; i<(SIZE/2); i++) {
			cout << setfill(' ')

				 << right << setprecision(2) << fixed << setw(3) << (i + 1)            << " " 
				 << left << setw(maxNameLength) << friends[i].name 
			     
			     << right << setprecision(2) << fixed << setw(3) << (i + (SIZE/2) + 1) << " " 
			     << left << setw(maxNameLength) << friends[i + (SIZE/2)].name

			     << endl;
		}
	}
	//Or just one if it won't.
	if (maxNameLength >  16) {
		cout << " ID " << setw(nameWhitespace) << " " << "NAME" << setw(nameWhitespace) << " " << endl;
		cout << setfill('-') << setw(8 + 2 * (nameWhitespace)) << "-" << endl;
		//Don't forget the information!
		for (int i=0; i<SIZE; i++) {
			cout << setfill(' ') 
				 
				 << right << setprecision(2) << fixed << setw(3) << (i + 1) << " " 
				 << left << setw(maxNameLength) << friends[i].name 
			     			     
			     << endl;
		}
	}
}
//See one friend in detail. Not a user-facing function.
void SeeFriend (Friend friends[], int SIZE, int ID){
		cout << setfill(' ') 
			 //Print their ID.
			 << right << setprecision(2) << fixed << setw(3) << (ID + 1) << " " 
			 //And their Name.
			 << left << setw(16) << friends[ID].name << " ";
			 //Then their interests.
			 for (int j=0; j<MAXLIKES; j++) cout << setw(16) << friends[ID].like[j] << " ";
		cout << endl;
}

//Initialize all of the friends.
void IniFriend (Friend friends[], int SIZE){
	for (int i=0;i<SIZE;i++){
		friends[i].name = "EMPTY";
		friends[i].like[0] = "EMPTY";
		friends[i].age = 0;
	}
}
//Initialize only one of the friends.
void IniFriend (Friend friends[], int SIZE, int ID){
		friends[ID].name = "EMPTY";
		friends[ID].like[0] = "EMPTY";
		for (int i=1; i<MAXLIKES; i++) {
			friends[ID].like[i] = "";
		}
		friends[ID].age = 0;
}


//Various Sort and Search Functions

//Search the database to find friends with similiar interests.
void FindLikes (Friend friends[], const int SIZE){
	const int t1 = SIZE;

	Friend temp[t1];
	string keyLike;

	//Move the friends array into temporary storage.
	for (int i=0; i<SIZE; i++) temp[i] = friends[i];
	//Standardize the information in temp. Ready? GO!
	for (int i=0; i<SIZE; i++) {
		transform(temp[i].name.begin(), temp[i].name.end(), temp[i].name.begin(), ::toupper);
		for(int j=0; j<MAXLIKES; j++) {
			transform(temp[i].like[j].begin(), temp[i].like[j].end(), temp[i].like[j].begin(), ::toupper);
		}
	}

	//Get user input
	cout << "Which interest would you like to search for? [Swimming] : ";
	getline(cin, keyLike);
	//Standardize the input, using in-place replacement.
	transform(keyLike.begin(), keyLike.end(), keyLike.begin(), ::toupper);

	//Print the header.
	cout << " ID " << setw(6) << " " << "NAME" << setw(6) << " " << setw(21) << " " << "INTERESTS" << setw(21) << " " << endl;
	cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
	//Step-by-Step instructions to follow ...
	//Run through all of the likes of all of the friends ...
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<MAXLIKES; j++) {
			//and for each like, compare it with the key ...
			if (!(keyLike.compare(temp[i].like[j]))) {
				//then print their info if the two match ...
				SeeFriend(temp, SIZE, i);
			}
		}
	}
}

//Sort friend list alphabetically and display results.
void AlphaSort (Friend friends[], int SIZE){
	Friend temp[SIZE];
	Friend tempFriend;
	bool passSwap = 1;
	static int bubble;
	bubble = SIZE;

	//Move the friends array into temporary storage.
	for (int i=0; i<SIZE; i++) temp[i] = friends[i];
	//Standardize the information in temp. Ready? GO!
	for (int i=0; i<SIZE; i++) {
		transform(temp[i].name.begin(), temp[i].name.end(), temp[i].name.begin(), ::toupper);
		for(int j=0; j<MAXLIKES; j++) {
			transform(temp[i].like[j].begin(), temp[i].like[j].end(), temp[i].like[j].begin(), ::toupper);
		}
	}
	/*
	//Run through the alphabet and assign positions in the alphaID array based on order.
	for (char c='A';c<='Z',c++) {
		for (int i=0; i<SIZE; i++) {
			if (c == cin.get(temp[i].name)

	}
	*/
	//Bubble sort the array using string compare.
	while (passSwap) {
		passSwap = false;
		for (int i=0; i<(bubble - 1); i++) {
	//		if (!(temp[i].name.compare(temp[i+1].name))) continue;
	//		if (temp[i].name.compare(temp[i+1].name) > 0) {
			if (!(FriendCmp(temp[i], temp[i+1]))) {
			tempFriend = temp[i];
			temp[i] = temp[i+1];
			temp[i+1] = tempFriend;
			passSwap = true;
			}
	//		if (temp[i].name.compare(temp[i+1].name) < 0) continue;
		}
		bubble--;
	}

	//Display the results
	SeeFriend(temp, SIZE);
}

//Check to see if friend one comes before friend two.
bool FriendCmp (Friend one, Friend two){
	//True means one comes before two, no swap needs to be made.

	//Check to see if either one of the two friends is "EMPTY".
	if (two.name == "EMPTY") return true;
	if (one.name == "EMPTY") return false;
	//Compare the two names.
	if (one.name.compare(two.name) < 0) return true;
	if (one.name.compare(two.name) > 0) return false;
	//Compare the two ages.
	if (one.age < two.age) return true;
	if (one.age > two.age) return false;
	//Finally, return true if they are identical.
	return true;
}