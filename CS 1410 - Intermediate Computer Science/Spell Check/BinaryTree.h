// Jonathan Petersen
// A01236750
// Spell Check 
// Binary Tree Header

#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

using namespace std;

class BinaryTree {

public:

	//Constructors
	 BinaryTree();
	 BinaryTree(const BinaryTree&);
	~BinaryTree();

	//Functions with the same name as the assignment!
	void	Insert(string);
	bool	Find(string);
	int 	Size();
	int 	Height();
	void 	Traverse();

	//Top-Level Functions
	void 	insert(string);
	void 	remove(string);
	bool 	search(string);
	string 	travel() /*const*/;

	//Tree Statistics
	int 	height();
	int 	size();

private:

	//Data Members
	TreeNode* root;
	
	//Low-Level Functions
	void 	rInsert(string, TreeNode*&);
	void 	rRemove(string, TreeNode*&);
	bool 	rSearch(string, TreeNode*&);
	void	mvChild(TreeNode*&, string&);
	void	remNode(TreeNode*&);
	void	destroy(TreeNode*&);
	void	deepCpy(TreeNode* const&);
	int 	rHeight(TreeNode*&);
	int 	rSize(TreeNode*&);
	//string 	rTraverse(TreeNode*&);
	BinaryTree& operator= (const BinaryTree& rhs);

};


#endif