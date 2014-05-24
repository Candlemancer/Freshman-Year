// Jonathan Petersen
// A01236750
// Spell Check
// Main 

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

#include "BinaryTree.h"



int main() {

	//Data Members
	BinaryTree tree;
	vector <string> toTree;
	string temp;
	regex xkcd("[^a-zA-Z]");

	ifstream dictionary("dictionary.txt");
	fstream letter("letter.txt");

	if(!dictionary || !letter) {
		cout << "Error opening files!\n";
		return -1;
	}


	//Read in the dictionary
	while (dictionary >> temp) {
		
		//cout << temp << " ";
		toTree.push_back(temp);

	}
	dictionary.close();

	//Shuffle words and add to tree.
	random_shuffle(toTree.begin(), toTree.end());
	
	for (unsigned int i=0; i<toTree.size(); i++) {

		tree.insert(toTree[i]);

	}

	cout << "The Tree has " << tree.size() << " nodes!\n";
	cout << "The Tree has " << tree.height() << " levels! (+1 if you count the root.)\n";


	cout << "The misspelled words are as follows: \n" << endl;
	//Read in the letter and check the words
	while (letter >> temp) {

		//A regular expression, followed by transform. My life is complete.
		temp = regex_replace(temp, xkcd, "");
		transform(temp.begin(), temp.end(), temp.begin(), tolower);
		if (!tree.search(temp)) cout << temp << " ";

	}

	cout << endl << endl;

	letter.close();

	//Fun with Binary Trees!
	cout << "Now let's play with trees!" << endl;
	cout << "Creating a new tree with the copy constructor ..." << endl;

	BinaryTree cutting(tree);

	cout << "Created a new tree!" <<endl;
	cout << "Adding the word \"I\" to the dictionary ..." << endl;

	//I have to add i because all the words are in lower case.
	cutting.Insert("i");
	cutting.Insert("I");

	cout << "Added \"I\" to the dictionary!" << endl;
	cout << "Is \"I\" in the dictionary? ";

	if (cutting.Find("I")) cout << "Yes, yes it is." << endl;
	else cout << "No it is not!" << endl;

	//Find and Height are demonstrated above

	cout << "Finally, here's a breadth-first tree, just for you!" << endl << endl;
	cutting.~BinaryTree();

	BinaryTree shrub;

	shrub.insert("M - top level");
	shrub.insert("F - second level");
	shrub.insert("O - second level");
	shrub.insert("I - third level");
	shrub.insert("W - third level");
	shrub.insert("A - third level");
	shrub.insert("J - third level");
	shrub.Traverse();
	
	cout << endl << "Enjoy your words!" << endl;

	system("pause");
	return 0;
}