/*
Overview

In this homework assignment, you will write a class specification
and definition to reflect the life and times of a generic gamepiece
in a toy soldier battle. Then you will put units onto a board and
let them duke it out.

 

Gamepiece Description

Each gamepiece in our  little game represents a unit of that includes
several toy soldiers.  As gamepieces are created, they are placed
on the board and given initial attributes through the constructor.

Each gamepiece has the following attributes:

Number of Soldiers:	each unit starts each game with 4 toy soldiers.

Location:		an x value 0-9 and a y value 0-9.  [0,0] is the
			upper left corner.

Direction:		the direction the unit is facing, either U (up),
			D (down), R (right), or L (left).

Province:		where the unit is from. Anjou, Bretagne, 
			Flandre, and Gascogne are the only possible home
			provinces for any unit.

alive:			bool indicating whether or not the unit is
			still with us.

Each gamepiece includes the following functionalities:

onBoard(...) - return the status of the alive variable
getX(...) - return the current x value.
getY(...) - return the current y value.
get Dir(...) - return the current unit direction
getNumElements(...)  - return the current number of soldiers in that unit.
getProvince(...) - returns an enumerated representation of its home province
die(...) - set alive to false
turnLeft(...) - turn the unit 90 degrees left.
turnRight(...)  - same for turnLeft, except to the right this time.
aboutFace(...) - same for turnRight, except to the rear this time.
moveForward(...) - move one space in the direction of Direction.
attack(...) - attack the space in front of you (more below),  return # hits
recommend(...) - return unit's recommendation for the next move (more below).
suffer(...) - remove one or more elements from the unit, return numSoldiers.
gamePiece(...) - default and nondefault contructors.


For attacking:  Each active toy soldier in a unit is 'given' a six-sided
die, which it 'rolls'.  If it rolls a 5 or 6, that counts as one
'hit'.  After each element rolls its die, the number of hits for the unit
are counted and returned to the client.  The client then takes that number
of soldiers away from the defending unit.  Units may attack empty spaces,
or even the edge of the board, not that
it will do any good.

For recommending:  The unit returns its recommendation for what it should
do next.  This is accomplished with an enumerated value with the
following possibilities:

nothing
left
right
rear
move
attack

To help your unit decide what to do, a Situation Report (or SitRep) is
provided to the recommend function with several pieces of useful data. 
The SitRep is a struct of type "intel" that is included in ToySoldiers.h

Thus, the basic sequence of events from the ToySoldiers perspective is:

1. The client code builds a SitRep
2. The client code calls your recommend function withh the SitRep
3. Your recommend code returns the recommendation for that unit
4. The client code calls your member function to effect that recommendation


The recommendation does not have to be especially useful for this
assignment; you may simply return 'random' recommendations, not that it
will be any fun.

 

Rules

We'll try not to be too demanding of our little toy soldiers, but there
have to be a few rules.

Units must stay on the board.
Units may not move over other units.
Units may not recommend any action that violates rules 1 or 2.
Any unit that violates a rule will be summarily removed from the board.



Details

Your class specifications should be kept in a file called  ToySoldiers.h.

Your class definitions should be kept in a separate file called ToySoldiers.cpp.

Your client code should be kept in a separate file called GameBoard.cpp.

ToySoldiers.h and GameBoard.h can be found in the files section of canvas.

 

What to Turn In

Turn in your ToySoldiers.cpp file.

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
 

// enums for various things used in the game
enum provinceName {anjou, flandre, gascogne, bretagne};
enum compassPoint {U, R, D, L};
enum recommendation {nothing, lft, rght, rear, goforward, attck};
enum id {empty, ally, enemy, abyss};

// this struct is given to the unit when a recommendation is requested
struct intel{
	id inFront;
	int inFrontNum;

	id inRear;
	int inRearNum;

	id inLeft;
	int inLeftNum;

	id inRight;
	int inRightNum;

	compassPoint nearestEnemyDir;
	int nearestEnemyDist;
	int nearestEnemyNum;

	compassPoint weakestEnemyDir;
	int weakestEnemyDist;
	int weakestEnemyNum;

	compassPoint strongestEnemyDir;
	int strongestEnemyDist;
	int strongestEnemyNum;

	compassPoint nearestAllyDir;
	int nearestAllyDist;
	int nearestAllyNum;

	compassPoint weakestAllyDir;
	int weakestAllyDist;
	int weakestAllyNum;

	compassPoint strongestAllyDir;
	int strongestAllyDist;
	int strongestAllyNum;
};
	

class gamePiece{
    public:
	// return the status of the alive variable
        bool onBoard();

	// return the current x value
        int getX();

	// return the current y value
        int getY();

	// return the current direction
        compassPoint getDir();

	// return the number of soldiers in the unit
        int getNumElements();

	// return the province
        provinceName getProvince();

	// set alive to false
	void die();

	// change the direction for a left turn
        void turnLeft();

	// change the direction for right turn
        void turnRight();

	// change the direction for an about face
        void aboutFace();

	// change x and y for a forward move
        void moveForward();

	// roll a die for each soldier in the unit.
	// each 5 or 6 counts as a 'hit'.
	// return the number of hits.
        int attack();

	//return lft, rght, rear, move, attck, or nothing
        recommendation recommend(intel sitRep);

	// reduce the number of soldiers by hits
        int suffer(int hits);

	// construct a nonliving gamepiece
        gamePiece();

	// construct a living gamepeice
        gamePiece(int col, int row, compassPoint direction, int num, provinceName p);

    private:
        int numSoldiers;
        int x;
        int y;
        compassPoint dir;
        provinceName province;
        bool alive;

};
 
