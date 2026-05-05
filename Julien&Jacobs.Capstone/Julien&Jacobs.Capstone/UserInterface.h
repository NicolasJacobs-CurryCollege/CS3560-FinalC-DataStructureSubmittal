#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "HashTable.h"
#include "BalanceHashTable.h"

class UserInterface
{
private:
	HashTable* hashTable;

public:
	UserInterface();
	~UserInterface();
	void displayMenu();
	void searchWord();
	void addWord();
	void removeWord();
	void displayHashTable();
	void displayBalancedHashTable();
};

#endif