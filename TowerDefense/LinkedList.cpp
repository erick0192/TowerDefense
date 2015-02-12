#include "stdafx.h"
#include "LinkedList.h"


Node::Node(void)
{
}


Node::~Node(void)
{
}


LinkedList::LinkedList(void)
{
	head = NULL; 
	tail = NULL; 
}


LinkedList::~LinkedList(void)
{
}


void LinkedList::addValue(int x, int y)
{
	Node *n = new Node();   
	n->x = x;             
	n->y = y;            
	n->next = head;        				
	head = n;
	if(n->next == NULL)
		tail = n;
}

void LinkedList::addToEnd(int x, int y)
{
	Node *n = new Node();  
	n->x = x;             
	n->y = y;

	if(head == NULL)
	{
		tail = n;
		head = n;
		tail->next = NULL;
	}
	else
	{
		tail->next = n;        				
		tail = n;
	}

}