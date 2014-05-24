#include "ToySoldiers.h"

using namespace std;
   
//--------------------//
//Function Definitions//
//--------------------//

// Get Functions //

bool 		gamePiece::onBoard()		{return alive;}
int		gamePiece::getX()		{return x;}
int 		gamePiece::getY()		{return y;}
int 		gamePiece::getNumElements()	{return numSoldiers;}
compassPoint	gamePiece::getDir()		{return dir;}
provinceName 	gamePiece::getProvince()	{return province;}


// Set Functions //

// Kill the unit.
void gamePiece::die() {
	alive = false;
	return;
}

// Rotate the game piece to the left.
void gamePiece::turnLeft() {
	switch (dir) {
	case U:	dir = L;
		break;
	case R:	dir = U;
		break;
	case D: dir = R;
		break;
	case L:	dir = D;
		break;
	}

	return;
}

// Rotate the game piece to the right.
void gamePiece::turnRight() {
	switch (dir) {
	case U:	dir = R;
		break;
	case R:	dir = D;
		break;
	case D: dir = L;
		break;
	case L:	dir = U;
		break;
	}

	return;
}

// Rotate the game piece halfway around.
void gamePiece::aboutFace() {
	switch (dir) {
	case U:	dir = D;
		break;
	case R:	dir = L;
		break;
	case D: dir = U;
		break;
	case L:	dir = R;
		break;
	}

	return;
}

// Move the unit in the direction the unit is facing.
void gamePiece::moveForward() {
	if (dir == U) y--;
	if (dir == R) x++;
	if (dir == D) y++;
	if (dir == L) x--;

	return;
}

// Roll a d6 for every soldier, doing damage for every 5 or 6.
int gamePiece::attack() {
	int results;
	int chances;
	
	// For every soldier, increment results based on die roll.
	for (chances = 0; chances < numSoldiers; chances++) if (rand()%6 == 4 || rand()%6 == 5) results++;

	return results;
}

// Decrease the number of soldiers based on damage.
int gamePiece::suffer(int hits) {
	numSoldiers -= hits;
	if (numSoldiers < 0) numSoldiers = 0;
	return numSoldiers;
}

// Send the recommendation, right now to spin in cirlces.
recommendation 	gamePiece::recommend(intel sitRep) {
	switch(rand()%5) {
	case 0:	return lft;
	case 1:	return rght;
	case 2:	return rear;
	case 3:	return goforward;
	case 4:	return attck;
	case 5:	return nothing;
	}
}


// Constructors //

// Default Constructor
gamePiece::gamePiece() {
	alive = false;
	numSoldiers = 4;
	x = 0;
	y = 0;
	dir = D;
	province = anjou;

	return;
}

// Non-Default Constructor
gamePiece::gamePiece(int col, int row, compassPoint direction, int num, provinceName p) {
	alive = true;
	numSoldiers = num;
	x = col;
	y = row;
	dir = direction;
	province = p;

	return;
}

//return lft, rght, rear, move, attck, or nothing
// recommendation gamePiece::recommend(intel sitRep);

