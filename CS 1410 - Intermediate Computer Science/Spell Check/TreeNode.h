// Jonathan Petersen
// A01236750
// Spell Check
// Binary Tree Node Header

#ifndef NODE_H
#define NODE_H


#include <string>

using namespace std;

class TreeNode {

public:
	//Data Members
	string 		data;
	TreeNode* 	left;
	TreeNode* 	rght;

	//Constructors
	TreeNode();
	TreeNode(string);
	//TreeNode(const& TreeNode); //Default should suffice, I just want pointers.

};


#endif