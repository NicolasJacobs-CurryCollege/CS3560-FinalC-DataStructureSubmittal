#include <iostream>
using namespace std;

class UserInterface
{
private:
	HashTable* hashTable;

public:
	UserInterface()
	{
		// Create HashTable and load Washington's Farewell Address
	}

	~UserInterface()
	{
		// Delete HashTable to free memory
	}

	void displayMenu()
	{
		// Display menu with options: Exit, Search, Add, Remove, Display Hash Table
	}

	void searchWord()
	{
		// Prompt user for word to search
	}

	void addWord()
	{
		// Prompt user for word to add
	}

	void removeWord()
	{
		// Prompt user for word to remove
	}

	void displayHashTable()
	{
		// Display entire hash table
	}
};