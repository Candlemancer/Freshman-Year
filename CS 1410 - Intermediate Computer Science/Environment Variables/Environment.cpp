// Jonathan Petersen
// A01236750
// Environment Analysis
// Function implementation

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cctype>
#include <limits>

#include "Environment.h"

const int WORD_SIZE = 40;

//Get the environment variables and store them in a stringstream
void getEVars(stringstream& ss) {

	extern char** environ;
	int index = 0;

	//Read in data
	while(environ[index]) {
		
		ss << " " << environ[index] << " " << endl;
		index++;

	}

	//Output PEE
	cout << "==============================================================\n";
	cout << ss.str() << endl;
	cout << "==============================================================\n\n";

	return;
}

//Convert a stringstream into a set of words.
void getWords(stringstream& ss) {

	stringstream temp;
	char* word = new char [WORD_SIZE * 10];

	//Filter Chars
	for(int i=0; i<ss.str().length(); i++) {
		temp << filterChars(ss.get());
	}
	//Clear first stream.
	ss.str("");

	//Check words
	while(temp.getline(word, numeric_limits<streamsize>::max(), ' ')) {
		if(filterWords(word)) ss << word << " ";
	}

	delete word;
	return;
}

//Create a report on all of the words in a stringstream.
void analysis(stringstream& ss) {

	bool skip;
	int num;
	int wordCount = 0;
	int blacklistCount = -1;
	char* word = new char [WORD_SIZE];
	char* temp = new char [WORD_SIZE];
	char** blacklist;
	stringstream outer, inner;

	//Get a wordcount
	while(ss.getline(word, numeric_limits<streamsize>::max(), ' ')) {
		wordCount++;
	}

	//Setup the blacklist.
	blacklist = new char* [wordCount];
	for(int i=0; i<wordCount; i++) {
		blacklist[i] = new char [WORD_SIZE];
		*blacklist[i] = 'X';
	}

	//Setup the two loops needed for word reports.
	outer.str(ss.str());
	inner.str(ss.str());
	//Print a report showing how many times each word appears.
	while(outer.getline(word, numeric_limits<streamsize>::max(), ' ')) {		

		//Reset loop variables.
		num = 0;
		skip = false;
		blacklistCount++;
		inner.str(ss.str());
		inner.seekp(0, inner.beg);
		inner.seekg(0, inner.beg);
		inner.clear();

		//First see if the word is on the blacklist.
		for(int i=0; i<wordCount; i++) {
			if(strcmp(word, blacklist[i]) == 0) {skip = true; break;}
		}
		//Then abort the current word if it is.
		if(skip == true) continue;


		//Or count the number of times it occurs if not.
		while(inner.getline(temp, numeric_limits<streamsize>::max(), ' ')) {
					if(strcmp(word, temp) == 0) num++;
		}

		//And append the word to the blacklist.
		strcpy(blacklist[blacklistCount], word);		

		cout << "The word " << setw(40) << left << word << " occurs " << num << " times.\n";


	}

	cout << "The number of words is: " << (wordCount - 1) << ".\n";

	delete word;
	delete temp;
	for(int i=0; i<wordCount; i++) delete blacklist[i];
	delete blacklist;

	cout << endl;

	return;
}

//Ask user what string they would like to find.
void userFind(stringstream& ss) {

	extern char** environ;
	char* choice = new char [WORD_SIZE];
	char* word   = new char [WORD_SIZE];
	char* environment = new char [WORD_SIZE];
	char temp;
	int numLine = 0;
	int count = 0;
	int lines = 0;
	streampos gpos, ppos;

	ss.str(ss.str());
	ss.seekp(0, ss.beg);
	ss.seekg(0, ss.beg);
	ss.clear();

	//Ask user what string they would like to search for.
	cout << "Please enter a string to search or \"END\" to quit. \n";
	cin >> choice;
	transform(choice, (choice + strlen(choice)), choice, ::toupper);

	while(strcmp(choice, "END") != 0) {
		//Search the stringstream for each occurance of the string.
		while(ss.getline(word, WORD_SIZE, ' ')) {
			transform(word, (word + strlen(word)), word, ::toupper);

			if(strcmp(word, choice) == 0) {
				//cout << "Word found!" << endl;
				count++;
			
				while(environ[lines]) {
					transform(environ[lines], (environ[lines] + strlen(environ[lines])), environment, ::toupper);
					if(strstr(environment, word)) cout << environ[lines] << endl;
					lines++;
				}

				//Incrememnt numLine for each newline character we find.

				//And print out the corresponding line.

			}



		}
	 
	 	//Then print out how many times the string appeared.
		cout << "Found " << count << " results!\n";
		cout << endl;
		cout << "Please enter a string to search or \"END\" to quit. \n";
		cin >> choice;
		transform(choice, (choice + strlen(choice)), choice, ::toupper);

		ss.str(ss.str());
		ss.seekp(0, ss.beg);
		ss.seekg(0, ss.beg);
		ss.clear();

		count = 0;

	}

	//delete environment;
	delete choice;
	delete word;

	return;
}

//Replace all non-alphanumeric characters with whitespace.
char filterChars(char c) {
	
	//Preserve lines
	if(c == '\n') return c;

	//Filter out nonalphanumeric characters
	if(!isalnum(c) && c != '_') c = ' ';

	return c;
}

//Check a word for length and letter requirements.
bool filterWords(char* word) {

	int index = 0;
	bool alpha = false;
	bool length = false;	

	//if(strcmp(word, "\n") == 0) return true;

	//Check if the word has at least one letter.
	while(word[index] != '\0') {

		//Make sure the word is at least two characters.
		if(index >= 1) length = true;
		//And contains at least one letter.
		if(isalpha(word[index])) alpha = true;

		//Early exit condition.
		if(length && alpha) return true;

		index++;
	}

	//Or Remove it from our list.
	return false;
}