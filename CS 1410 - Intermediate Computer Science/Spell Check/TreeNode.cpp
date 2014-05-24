// Jonathan Petersen
// A01236750
// Spell Check
// Binary Tree Node Implementation

#include <string>

#include "TreeNode.h"

//Default Constructor
TreeNode::TreeNode() {

	data = "";
	left = NULL;
	rght = NULL;

	return;
}

//Constructor with Parameter
TreeNode::TreeNode(string data) {

	this->data = data;
	left = NULL;
	rght = NULL;

	return;
}