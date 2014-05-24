#include <string>
using namespace std;

class ListNode
{  
public:	
	string name;
	ListNode *next;

	ListNode() ;
	ListNode(string s) ;
}; 

typedef ListNode* Nodeptr;

class LList
{
private:
	Nodeptr head;

public:	// These public functions are the same as the ones provided in the linked list example (Chapter 17)
	LList();	
	~LList();
	void Insert (string s);	// insert a new name in order
	void Delete (string s);	// delete a name
	void Display ();		// display list in order

// Two of the recursive functions require the functions' arguments to be references to the pointer
private: // recursive versions
	void RDestroy(Nodeptr p);
	void RInsert (Nodeptr& p, string s);	
	void RDelete (Nodeptr& p, string s);
	void RDisplay (Nodeptr p);
};

