// Jonathan Petersen
// A01236750
// Recursion Examples

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int cannonball(int);
void printBinary(int);
int sumOfDigits(int);
void maze(string);
void solver(bool&, char**&, int&, int&, int, int);

int main() {

	cout << "Cannonball Example ==============================\n"
		 << "Pyramid with  1 level : " << cannonball( 1) << " cannonballs.\n"
		 << "Pyramid with 42 levels: " << cannonball(42) << " cannonballs.\n"
		 << "=================================================\n" << endl;

	cout << "Binary Conversion Example =======================\n"
		 << "The number  1 in binary is: "; printBinary( 1); cout << ".\n"
		 << "The number 42 in binary is: "; printBinary(42); cout << ".\n"
		 << "=================================================\n" << endl;

	cout << "Sum of Digits Example ===========================\n"
		 << "The sum of the digits of  1 is: " << sumOfDigits( 1) << ".\n"
		 << "The sum of the digits of 42 is: " << sumOfDigits(42) << ".\n"
		 << "=================================================\n" << endl;

	cout << "Maze Solver Example =============================\n"
		 << "Maze Solution 1 ( maze.txt): --------------------\n"; 
			maze("maze"); 
	cout << "Maze Solution 2 (maze2.txt): --------------------\n"; 
			maze("maze2");
	cout << "=================================================\n" << endl;

	cout << "maze2.txt will now self-destruct." << endl;
	remove("maze2.txt");

	return 0;
}

//Count the number of cannonballs in a pyramid based on levels
int cannonball(int level) {

	//Base Case
	if(level < 1) return 0;

	//Alternative Case
	return ( (level*level) + cannonball(level - 1) );

}

//Print out the binary representation of a number
void printBinary(int n) {

	//Base Case
	if(n / 2 == 0) {cout << (n % 2); return;}

	//Alternative case
	printBinary(n / 2);
	cout << n % 2;

	return;
}

//Find the sum of all the digits in a number
int sumOfDigits(int num) {

	//Base Case
	if(num < 10) return num;

	//Alternative Case
	return ( (num % 10) + sumOfDigits(num / 10) );
	
}

//Solve a maze. This function only sets up file I/O, see below for the solver.
void maze(string filename) {

	ifstream file (filename + ".txt");
	ofstream newfile;
	char** maze;
	int rows, cols;
	int xpos, ypos;
	bool solved = false; // Defined here so I only need once instance of the variable.

	//See if there is a maze file, and if not create a generic one.
	if(!file) {
		
		cout << "No file by the name of " + filename + ".txt could be located.\n"
			 << "Generating new file.\n";
		
		newfile.open(filename + ".txt");
		newfile << "11 10" << endl
				<< "9 4" << endl
				<< "XXXXXXXXXX" //<< endl
				<< "XX...tX..X" //<< endl
				<< "XX.XXXX.XX" //<< endl
				<< "XX.......X" //<< endl
				<< "XXXXXXX.XX" //<< endl
				<< "X....XX.XX" //<< endl
				<< "X.XX.....X" //<< endl
				<< "X...XX.XXX" //<< endl
				<< "XXX..XXXXX" //<< endl
				<< "XXXX....XX" //<< endl
				<< "XXXXXXXXXX";
		newfile.close();

		file.open(filename + ".txt");
	}

	//Insure all variables are properly initialized.
	if( !(file >> rows) || !(file >> cols) || !(file >> xpos) || !(file >> ypos) ) {
		
		cout << filename + ".txt is not properly formatted. Program will now exit." << endl;
		//system("pause");
		exit(EXIT_FAILURE);
	}

	//cout << "SIZE: " << rows << "x" << cols << endl;
	//cout << "START: " << xpos << "," << ypos << endl;

	file.get();

	//Setup the maze array.
	maze = new char* [rows];
	for(int i=0; i<rows; i++) {
		maze[i] = new char [cols];
	}

	//Form the array
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			maze[i][j] = file.get();
		}
	}

	solver(solved, maze, rows, cols, xpos, ypos);

	//Print the array
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			cout << " " << maze[i][j];
		}
		cout << endl;
	}


	//Delete the maze array
	for(int i=0; i<rows; i++) {
		delete [] maze[i];
	}
	delete [] maze;

	file.close();
	return;
}

void solver(bool& solved, char**& maze, int& rows, int& cols, int xpos, int ypos) {

	//Base Case
	if(maze[xpos][ypos] == 't') {cout << "Treasure found at [" << xpos << ", " << ypos << "]! Congratulations!\n"; solved = true; return;}
	if(solved) return;

	//Alternative Cases
	maze[xpos][ypos] = '!';
	if(xpos < rows) 	if(maze[xpos - 1][ypos] != 'X' && maze[xpos - 1][ypos] != '!') 	solver(solved, maze, rows, cols, (xpos - 1), ypos);
	if(ypos < cols) 	if(maze[xpos][ypos + 1] != 'X' && maze[xpos][ypos + 1] != '!') 	solver(solved, maze, rows, cols, xpos, (ypos + 1));
	if(ypos > 0) 		if(maze[xpos][ypos - 1] != 'X' && maze[xpos][ypos - 1] != '!') 	solver(solved, maze, rows, cols, xpos, (ypos - 1));
	if(xpos > 0) 		if(maze[xpos + 1][ypos] != 'X' && maze[xpos + 1][ypos] != '!') 	solver(solved, maze, rows, cols, (xpos + 1), ypos);

	//Print Correct Path
	if(solved) {cout << "Treasure path is: [" << xpos << ", " << ypos << "]\n";	return;}
	return;
}