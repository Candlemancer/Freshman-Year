//Jonathan Petersen
//A01236750 - HW 02
#include <string>

const int MAXLIKES = 3;

using namespace std;
//Define the Friend Structure, with space for a name,
// multiple likes, and age. 
struct Friend {
	string name;
	string like[MAXLIKES];
	int age;
};

//Function definitions. See .cpp file for more info.

//Return the Mean Age
float AgeStats(Friend friends[], int SIZE);

//Functions to Add or Remove Friends from the list.
void AddFriend (Friend friends[], int SIZE);
void RemFriend (Friend friends[], int SIZE);
void SeeFriend (Friend friends[], int SIZE);
void SeeFriend (Friend friends[], int SIZE, int ID);
void IniFriend (Friend friends[], int SIZE);
void IniFriend (Friend friends[], int SIZE, int ID);

//Various Sort and Search Functions
void FindLikes (Friend friends[], int SIZE);
void AlphaSort (Friend friends[], int SIZE);
bool FriendCmp (Friend a, Friend b);