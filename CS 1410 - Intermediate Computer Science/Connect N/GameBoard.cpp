#include <iostream>
#include <cstdlib>
#include "GameBoard.h"


//Allocate Memory.
GameBoard::GameBoard(){

	//Figure out how large the board needs to be.
	cout << "How many pieces do you want to connect?: [3, 4, 5, 6] ";
	while( !(cin >> goal) 	 || 
		   goal < 3 		 ||
		   goal > 6 		 ||
		   cin.get() != '\n'){

		cin.clear();
		cin.ignore(1000, '\n');
		cout << "That number is invalid. What number of pieces do you want to connect?: [3-6]";
	
	}

	rows = goal + 2;
	cols = goal + 3;

	//Allocate Memory for the board.
	board = new char *[rows];
	
	for(int i=0; i < rows; i++) {
		board[i] = new char [cols];
	}

	//Fill in the board with blank spaces.
	for(int i=0; i < rows; i++) {

		for(int j=0; j < cols; j++) {
			board[i][j] = '-';
		}

	}

	//Set up the victory conditions and RNG.
	draw 	= 0;
	victory = false;

	srand(static_cast <unsigned int> (time(NULL)));
	rand();

	return;
}

//Deallocate Memory.
GameBoard::~GameBoard(){
	if( draw >= (rows * cols) ) cout << "It was a draw!\n";

	else {
		cout << "The Winner is ";
		if(winner == true ) cout << "the Player! (That's you.)\n";
		if(winner == false) cout << "the Computer!\n";
	}

	delete[] board;
	
	return;
}

//Take a turn.
void GameBoard::takeTurn(bool player){

	int  choice = 1;
	bool played = false;

	//Decide who's turn it is.
	switch (player){
		
	case true:

		while(!played && !victory){

			//Ask and validate input.
			cout << "Pick a column to play your piece in: [1-" << (rows + 1) << "] ";
			while( !(cin >> choice)				||
				   choice < 1 					||
				   choice > (rows + 1) 			||
				   board[0][choice - 1] != '-'	||
				   cin.get() != '\n'			 ){

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input. Please try again. [1-" << (rows + 1) << "] ";
			}

			//Attempt to play in that column
			if( attemptMove(player, (choice - 1)) ) played = true;

		} 

		break;

	case false:

		while(!played && !victory){

			//Computer plays in random slot.
			//Note that the choice variable here is not offset.
			choice = ( rand() % (rows + 1) );
			if(board[0][choice] != '-') continue;
			if( attemptMove(player, choice) ) played = true;

		}

		break;

	}

	return;
}

//Show the game board.
void GameBoard::seeBoard(){

	//Print Header
	cout << "  ";

	for(int i=0; i <= rows; i++){
		cout << (i + 1) << " ";
	}

	cout << endl;

	//Print actual board, with row labels.
	for(int i=0; i < rows; i++){

		cout << static_cast <char> (i+65) << " ";
		
		for(int j=0; j<cols; j++){
			cout << board[i][j] << " ";
		}
		
		cout << endl;
	
	}

	return;
}

//See if the game has been won.
bool GameBoard::checkWin() {

	//Check if the game is over.
	return victory;
}

//Get the longest connection of a piece.
int GameBoard::connections(int row, int col){

	int size = 0;
	int temp = 0;

	for(int test=0; test < 4; test++) {

		temp = 0;

		switch (test) {

		case 0: // Horizontal Test
			for(int i=0; i < (cols - 1); i++) {
				if ((board[row][i] == board[row][i+1]) &&
				    (board[row][i] == board[row][col])  ) temp++;

				if ((board[row][i] != board[row][i+1]) &&
				    (board[row][i] == board[row][col])  ) temp = 0;

				if(size < temp) size = temp;

			}

			//cout << "The Horizontal Test returns " << size << endl;

			break;

		case 1: // Vertical Test
			for(int i=0; i < (rows - 1); i++) {
				if ((board[i][col] == board[i+1][col]) &&
				    (board[i][col] == board[row][col])  ) temp++;

				else temp = 0;
				
				if(size < temp) size = temp;

			}

			//cout << "The Vertical Test returns " << size << endl;

			break;

		case 2: // "/" Test
			for(int i=1; i<=goal; i++){
				if( ((row + 1) <= (rows - i) && row       >= -i)	&&
					((col + i) <= cols 		 && (col + i) >=  0)	 ){

					if(board[row][col] == board[row+i][col-i]) temp++;

					if(board[row][col] != board[row+i][col-i]) temp = 0;

				}

				if(size < temp) size = temp;

			}

			//cout << "The \"/\" Test returns " << size << endl;

			break;

		case 3: // "\" Test
			for(int i=1; i<=goal; i++){
				if( ((row + 1) <= (rows - i) && row       >= -i)	&& 
				    ((col + i) <= cols       && (col + i) >=  0)	 ){

					if(board[row][col] == board[row+i][col+i]) temp++;

					if(board[row][col] != board[row+i][col+i]) temp = 0;

				}

				if(size < temp) size = temp;

			}

			//cout << "The \"\\\" Test returns " << size << endl;

			break;

		}

	}

	return (size + 1);
}

//Attempt to play a piece in a column.
bool GameBoard::attemptMove(bool player, int column){

	int lowest = 0;

	//Find the lowest free spot in the column.
	for(int i=0; i < rows; i++) {
		if(board[i][column] == '-') lowest = i;
	}

	//Place the piece in the column and test for victory.
	if(player ==  true) board[lowest][column] = 'o';
	if(player == false) board[lowest][column] = 'x';
	
	if(connections(lowest, column) >= goal){

		cout << "The game should be won!\n";

		victory = true;
		winner = player;
	}

	return true;
}

//Platform-independent console wiping.
void GameBoard::clearScreen() {

	#ifdef WINDOWS
	std::system ( "CLS" );
	#else

	// Assume POSIX
	std::system ( "clear" );
	#endif
}

//Check if the game is a draw.
void GameBoard::noMovesLeft(){

	draw += 2;
	if(draw >= (rows * cols)) victory = true;

	return;

}


