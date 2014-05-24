//Jonathan Petersen
//A01236750
//Connect N

/*-----------------*/
//This file contains
//the header for the 
//primary class file
//used in the game.
/*-----------------*/

using namespace std;

class GameBoard {

public:

	//Allocate and Deallocate memory
	 GameBoard();
	~GameBoard();

	//High-Level game functions
	void takeTurn (bool);
	void seeBoard (    );
	bool checkWin (    );

	//Basic game functions.
	int  connections (int , int);
	bool attemptMove (bool, int);
	void clearScreen (         );
	void noMovesLeft (         );


private:

	int  goal;
	int  rows;
	int  cols;
	int  draw;
	bool winner;
	bool victory;
	char **board;

};