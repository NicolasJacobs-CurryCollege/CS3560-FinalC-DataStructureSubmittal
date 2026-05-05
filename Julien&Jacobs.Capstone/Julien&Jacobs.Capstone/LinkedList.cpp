#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	headNode = nullptr;
}

LinkedList::~LinkedList()
{
	Node* current = headNode;

	while (current != nullptr)
	{
		Node* nextNodeToDelete = current->getNextNode();
		delete current;
		current = nextNodeToDelete;
	}

	headNode = nullptr;
}

void LinkedList::addWord(string value)
{
	if (headNode == nullptr)
	{
		headNode = new Node(value);
		return;
	}

	Node* current = headNode;

	while (current != nullptr)
	{
		if (current->getWord() == value)
		{
			current->incrementCount();
			return;
		}
		current = current->getNextNode();
	}

	Node* newNode = new Node(value);

	if (value < headNode->getWord())
	{
		newNode->setNextNode(headNode);
		headNode = newNode;
		return;
	}

	current = headNode;

	while (current->getNextNode() != nullptr && current->getNextNode()->getWord() < value)
	{
		current = current->getNextNode();
	}

	newNode->setNextNode(current->getNextNode());
	current->setNextNode(newNode);
}

void LinkedList::removeWord(string value)
{
	if (headNode == nullptr)
	{
		return;
	}

	if (headNode->getWord() == value)
	{
		Node* nodeToDelete = headNode;
		headNode = headNode->getNextNode();
		delete nodeToDelete;
		return;
	}

	Node* current = headNode;

	while (current->getNextNode() != nullptr)
	{
		if (current->getNextNode()->getWord() == value)
		{
			Node* nodeToDelete = current->getNextNode();
			current->setNextNode(nodeToDelete->getNextNode());
			delete nodeToDelete;
			return;
		}
		current = current->getNextNode();
	}
}

void LinkedList::displayList()
{
	if (headNode == nullptr)
	{
		cout << "List is empty" << endl;
		return;
	}

	Node* current = headNode;

	cout << "List contents: ";

	while (current != nullptr)
	{
		cout << current->getWord() << " (" << current->getCount() << ")";

		if (current->getNextNode() != nullptr)
		{
			cout << ", ";
		}

		current = current->getNextNode();
	}

	cout << endl;
}

Node* LinkedList::getHeadNode()
{
	return headNode;
}