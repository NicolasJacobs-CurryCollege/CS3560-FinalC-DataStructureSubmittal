#include "UserInterface.h"
#include <iostream>
using namespace std;

UserInterface::UserInterface()
{
	hashTable = new HashTable();
	hashTable->loadFromFile("C:\\Users\\Administrator\\OneDrive - students.curry.edu\\Desktop\\CS3560-DataStructures&Algorithms2\\Julien&Jacobs.Capstone\\ARM64\\Debug\\WashingtonsFarewellAddress.txt");
}

UserInterface::~UserInterface()
{
	delete hashTable;
}

void UserInterface::displayMenu()
{
	string menu = "Washington's Farwell Address Word Counter:\n0. Exit\n1. Search for Word\n2. Add Word\n3. Remove Word\n4. Display Hash Table\n5. Display Balanced Hash Table";

	while (true)
	{
		cout << endl << menu << endl;
		cout << "Enter choice: ";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Exiting program" << endl;
			return;
		case 1:
			searchWord();
			break;
		case 2:
			addWord();
			break;
		case 3:
			removeWord();
			break;
		case 4:
			displayHashTable();
			break;
		case 5:
			displayBalancedHashTable();
			break;
		default:
			cout << "Invalid selection" << endl;
			break;
		}
	}
}

void UserInterface::searchWord()
{
	cout << "Enter word to search: ";
	string word;
	cin >> word;

	hashTable->searchWord(word);
}

void UserInterface::addWord()
{
	cout << "Enter word to add: ";
	string word;
	cin >> word;

	hashTable->addWord(word);
	cout << "Word \"" << word << "\" added to hash table" << endl;
}

void UserInterface::removeWord()
{
	cout << "Enter word to remove: ";
	string word;
	cin >> word;

	hashTable->removeWord(word);
	cout << "Word \"" << word << "\" removed from hash table" << endl;
}

void UserInterface::displayHashTable()
{
	hashTable->displayTable();
}

void UserInterface::displayBalancedHashTable()
{
	BalanceHashTable balanced(hashTable->getBuckets());
	balanced.displayBalancedTable();
}