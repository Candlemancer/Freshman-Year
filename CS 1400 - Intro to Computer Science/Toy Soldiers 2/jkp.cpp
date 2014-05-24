#include "toy.h"
#include "jkp.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int killEnemy() {return 5;}
int faceEnemy(int, int);
int seekEnemy(int, int);
int faceUp(int);
int victoryMarch(int);

recommendation jkp::recommend(intel sitRep){
	int decision = 0;
//	static int numReports = 0;
//	bool wounded = false;
//	bool victory = false;
/*
	if (sitRep.strongestEnemyDist == 100) victory = true;
	if (victory == true) {
		decision = victoryMarch(gamePiece::getDir());
		goto momentOfTruth;
	}
*/	

	/*
	if (sitRep.weakestAllyNum != 0) wounded = true;
	if (wounded == true && sitRep.inFront == empty) {
		decision = 4; 
		if ((sitRep.inFront == abyss || sitRep.inFront == ally) && decision == 4) decision = 1;
		goto momentOfTruth;
	}
	*/

	/*
	decision = faceEnemy(sitRep.nearestEnemyDir, gamePiece::getDir());
	if (sitRep.nearestEnemyDist == 2) decision = killEnemy();
	if (sitRep.inRight == enemy) decision = faceEnemy(sitRep.nearestEnemyDir, gamePiece::getDir());
	if (sitRep.inLeft == enemy) decision = faceEnemy(sitRep.nearestEnemyDir, gamePiece::getDir());
	if (sitRep.inFront == enemy) decision = killEnemy();
	if (gamePiece::getX() == 8) {
		if (numReports >=  8 && numReports <= 15) decision = faceUp(gamePiece::getDir());
		if (numReports >= 16 && numReports <= 32) decision = 4;
	}
	if ((sitRep.inFront == abyss || sitRep.inFront == ally) && decision == 4) decision = 3;
	else decision = 5;

	numReports++;
	*/

	decision = 5;

	if (sitRep.inLeft == enemy && sitRep.inFront != enemy) decision = 1;
	if (sitRep.inRight == enemy && sitRep.inFront != enemy) decision = 2;




momentOfTruth:
	switch (decision){
	case 0: return nothing;
	case 1: return lft;
	case 2: return rght;
	case 3: return rear;
	case 4: return goforward;
	case 5: return attck;
	}
}



int faceEnemy(int target, int current){
	switch (target){
	case 0:	if (current == 0) return 5;
		if (current == 1) return 1;
		if (current == 2) return 3;
		if (current == 3) return 2;
	case 1:	if (current == 0) return 2;
		if (current == 1) return 5;
		if (current == 2) return 1;
		if (current == 3) return 3;
	case 2:	if (current == 0) return 3;
		if (current == 1) return 2;
		if (current == 2) return 5;
		if (current == 3) return 1;
	case 3:	if (current == 0) return 1;
		if (current == 1) return 3;
		if (current == 2) return 2;
		if (current == 3) return 5;
	}
}

int faceUp(int current){
	if (current == 0) return 5;
	if (current == 1) return 1;
	if (current == 2) return 3;
	if (current == 3) return 2;
}


int victoryMarch(int facing){
	if (facing == 0) return 3;
	if (facing == 1) return 2;
	if (facing == 2) return 4;
	if (facing == 3) return 1;
}
