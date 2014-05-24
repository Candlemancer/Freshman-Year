// Jonathan Petersen
// A01236750
// Spell Check
// Binary Tree Implementation

#include <queue>
#include <sstream>
#include <iostream>
#include "BinaryTree.h"

//Default Constructor
BinaryTree::BinaryTree() { root = NULL; return; }

//Copy Constructor
BinaryTree::BinaryTree(const BinaryTree& other) { 

	root = NULL;
	deepCpy(other.root);

	return;
}

//Destructor
BinaryTree::~BinaryTree() { destroy(root); return; }

//Wrapper functions for assingment. DELETE WHEN DONE.
void BinaryTree::Insert(string s) 	{ insert(s); return; }
bool BinaryTree::Find(string s) 	{ return search(s); }
int  BinaryTree::Size() 			{ return size(); }
int  BinaryTree::Height() 			{ return height(); }
void BinaryTree::Traverse() 		{ cout << travel() << endl; return; }

//Insert data into the Tree
void BinaryTree::insert(string s) 	{ rInsert(s, root); return; }

//Remove data from the Tree
void BinaryTree::remove(string s) 	{ rRemove(s, root); return; }

//Search for data in the Tree
bool BinaryTree::search(string s) 	{ return rSearch(s, root); }

//Traverse the Tree for its data
string BinaryTree::travel() /*const*/ { 

	//Error Handling
	if(this == NULL) { return "Tree is NULL!\n"; }

	//Data Members
	string result = "";
	queue <TreeNode*> q;
	q.push(root);

	//Data Processing
	while (!q.empty()) {

		TreeNode* temp = q.front();
		q.pop();

		if(temp->left != NULL) q.push(temp->left);
		if(temp->rght != NULL) q.push(temp->rght);

		result.append(temp->data);
		result.append(" ");
	}

	//Recursive Traversal
	//return rTraverse( root); 

	return result;
}

//Recursively Insert data into the Tree
void BinaryTree::rInsert(string s, TreeNode*& that) {

	//Base Case
	if (that == NULL) { that = new TreeNode(s); return; }

	//Alternative Case
	if (s <= that->data) { rInsert(s, that->left); return; }
	if (s >  that->data) { rInsert(s, that->rght); return; }

	cout << "Recursive Insert has Failed" << endl;
	return;
}

//Recursively Remove data from the Tree
void BinaryTree::rRemove(string s, TreeNode*& that) {

	//Error Handling
	if (that == NULL) return;

	//Base Case
	if (s == that->data) { remNode(that);			return; }
	if (s <= that->data) { rRemove(s, that->left);	return; }
	if (s >  that->data) { rRemove(s, that->rght);	return; }

	cout << "Recursive Delete has Failed" << endl;
	return;
}

//Recursively Search for data in the Tree
bool BinaryTree::rSearch(string s, TreeNode*& that) {

	//Base Cases
	if(that == NULL) 	{ return false; }
	if(s == that->data)	{ return true;  }

	//Alternative Cases
	if(s <= that->data) { return rSearch(s, that->left); }
	if(s >  that->data) { return rSearch(s, that->rght); }

	cout << "Recursive Search has Failed" << endl;
	return false;
}

/*
//Recursively Traverse the Tree
string BinaryTree::rTraverse(TreeNode*& that) {

	//Data Members
	string l, r;

	//Base Cases
	if(that == NULL)	{ return ""; }

	//Alternative cases
	l = rTraverse(that->left);
	r = rTraverse(that->rght);

	return (l + that->data + " " + r);
}
*/

//Remove a node from the Tree
void BinaryTree::remNode(TreeNode*& that) {

	//No Children
	if (that->left == NULL && that->rght == NULL) { 
	
		delete that; 
		that = NULL; 

		return; 
	}

	//Right Hand Child
	if (that->left == NULL) { 
	
		//Create second reference
		TreeNode* temp = that;

		//Burn your bridges after you
		that = that->rght; 
		delete temp; 
	
		return; 
	}	

	//Left Hand Child
	if (that->rght == NULL) {

		//Create second reference
		TreeNode* temp = that;

		//Burn your bridges behind you
		that = that->left;
		delete temp;

		return;
	}

	//Two Children
	if (that->left != NULL && that->rght != NULL) {

		string successor;

		//Sort out the succession crisis
		mvChild(that, successor);
		that->data = successor;

		return;
	}

	cout << "Removing a node has failed." << endl;
	return;
}

//Move a child to the current node and properly attach its subtree
void BinaryTree::mvChild(TreeNode*& that, string& s) {

	//Data Members
	TreeNode* parent = that;
	int count = 0;

	//Find a bigger number
	that = that->rght;

	//Then the smallest number larger than the originial
	while (that->left != NULL) {

		count++;
		parent = that;
		that = that->left;

	}

	//And set the node equal to that
	s = that->data;

	//If the right side has no left nodes
	if (count == 0) {

		parent->rght = that->rght;
		delete that;
		that = NULL;

		return;
	}

	if (count != 0) {

		parent->left = that->rght;
		delete that;
		that = NULL;

		return;
	}

	cout << "Succession has failed." << endl;
	return;
}

//Count the number of nodes in a tree
int BinaryTree::size() { return rSize(root); }

//Recursively Count the number of nodes in a tree
int BinaryTree::rSize(TreeNode*& that) {

	//Base Case
	if (that == NULL) return 0;

	//Alternative case
	return (rSize(that->left) + rSize(that->rght) + 1);
}

//Find the height of the tree (# of levels - 1?)
int BinaryTree::height() { return rHeight(root); }

//Recursively find the Height of the tree. 
int BinaryTree::rHeight(TreeNode*& that) {

	int l, r;

	//Base Case
	if (that == NULL) { return -1; }

	//Alternative Cases
	l = 1 + rHeight(that->left);
	r = 1 + rHeight(that->rght);

	if (l >= r) return l;
	if (r >  l) return r;

	cout << "Recursive Height has Failed." << endl;
	return -2;
}

//Recursively destroy this tree
void BinaryTree::destroy(TreeNode*& that) {

	//Base Case
	if (that == NULL) { return; }

	//Alternative Cases
	if (that->left != NULL) destroy(that->left);
	if (that->rght != NULL) destroy(that->rght);

	if (that->left == NULL &&
		that->rght == NULL) {

		delete that;
		that = NULL;

		return;
	}

	cout << "Recursive Destruction has Failed." << endl;
	return;
}

//Recursively add nodes from another tree to this Tree.
void BinaryTree::deepCpy(TreeNode* const& that){

	//Base Case
	if (that == NULL) return;

	//Alternative Cases
	insert(that->data);

	deepCpy(that->left);
	deepCpy(that->rght);

	return;
}

//Assignment operator calls the copy constructor.
BinaryTree& BinaryTree::operator= (const BinaryTree& rhs) { 

	root = NULL;
	deepCpy(rhs.root);

	return *this; 
}
