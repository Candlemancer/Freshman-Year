#include "Recursive_LL.h"
#include <iostream>
using namespace std;

ListNode::ListNode()
{
	name = " " ;
	next = NULL ;
}

ListNode::ListNode(string s)
{   
	name = s ;
	next = NULL ;
}

LList::LList()
{	
	head = new ListNode("AAAA");
	head->next = new ListNode("zzzz");
}

// The following four functions are just wrappers!
// They will call their respective recursive function to accomplish the task
LList::~LList()
{	
	RDestroy(head);
}

void LList::Insert(string s)		
{	
	RInsert(head, s);
}

void LList::Delete (string s)
{	
	RDelete(head, s);
}

void LList::Display()
{	
	RDisplay(head->next);
}

void LList::RDestroy(Nodeptr p)
{	
	Nodeptr after = p->next;
	delete p;
	if (after != NULL)  // recursive case
		RDestroy(after);
}

void LList::RInsert (Nodeptr& p, string s)
{	
	if (s < p->name)  // base case
	{	
		Nodeptr here = new ListNode(s);
		here->next = p;
		p = here;
	}
	
	else // recursive case
	{
		RInsert(p->next, s);
	}
}

void LList::RDelete (Nodeptr& p, string s)
{	
	if (p == NULL) return ;  // reach the end of the linked list

	else if (s == p->name)  // found the node which contains the value of s
	{	
		Nodeptr here = p;
		p = p->next;
		delete here;
	}
	else RDelete(p->next, s);
}

void LList::RDisplay (Nodeptr p)
{	
	if (p->next != NULL)
	{	
		cout << p->name << endl;
		RDisplay (p->next);
	}
}
