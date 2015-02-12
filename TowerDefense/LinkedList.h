#pragma once

class Node
{
public:
	Node(void);
	~Node(void);
	int x;
	int y;
	Node *next;
};

class LinkedList
{
public:
	LinkedList(void);
	~LinkedList(void);
public:

    void addValue(int x, int y);
	void addToEnd(int x, int y);
	bool hasNext();

public:
    Node* head;
	Node* tail;
};

