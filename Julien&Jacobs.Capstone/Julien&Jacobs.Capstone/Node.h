#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
private:
	string word;
	int count;
	Node* nextNode;

public:
	Node(string value);
	string getWord();
	int getCount();
	void incrementCount();
	void setNextNode(Node* node);
	Node* getNextNode();
};

#endif