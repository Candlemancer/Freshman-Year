#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	char workingChar;
	char processChar;
	ifstream message;
	ofstream decoded;

	// Open Files
	message.open( "secretMessage.txt");
	decoded.open("decodedMessage.txt");

	// Character Process Loop
	while(message){
		message.get(workingChar);
		processChar = workingChar;

		if(workingChar >= 'A' && workingChar <= 'M') processChar = workingChar + 13;
		if(workingChar >= 'N' && workingChar <= 'Z') processChar = workingChar - 13;
		if(workingChar >= 'a' && workingChar <= 'm') processChar = workingChar + 13;
		if(workingChar >= 'n' && workingChar <= 'z') processChar = workingChar - 13;

		decoded << processChar;
	}

	message.close();
	decoded.close();

	return 0;
}
