#include "Node.h"

Node::Node(string value)
{
	word = value;
	count = 1;
	nextNode = nullptr;
}

string Node::getWord()
{
	return word;
}

int Node::getCount()
{
	return count;
}

void Node::incrementCount()
{
	count++;
}

void Node::setNextNode(Node* node)
{
	nextNode = node;
}

Node* Node::getNextNode()
{
	return nextNode;
}