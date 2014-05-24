#include <iostream>
#include "GameBoard.h"

using namespace std;


int main(){

	GameBoard *game;

	//Create the game board.
	game = new GameBoard();
	game->clearScreen();
	game->seeBoard();


	while(!game->checkWin()){

		//Player Turn
		game->takeTurn(true);
		//Computer Turn
		game->takeTurn(false);

		//End of Turn Sequence
		game->noMovesLeft();
		game->clearScreen();
		game->seeBoard();
	}

	//Conclusion
	game->~GameBoard();

	return 0;
}