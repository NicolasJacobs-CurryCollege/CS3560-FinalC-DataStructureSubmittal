#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
using namespace std;

class LinkedList
{
private:
	Node* headNode;

public:
	LinkedList();
	~LinkedList();
	void addWord(string value);
	void removeWord(string value);
	void displayList();
	Node* getHeadNode();
};

#endif