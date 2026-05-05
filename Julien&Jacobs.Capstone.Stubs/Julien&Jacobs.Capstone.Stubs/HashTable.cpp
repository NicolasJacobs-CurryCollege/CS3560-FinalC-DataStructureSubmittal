#include <iostream>
using namespace std;

class HashTable
{
private:
	LinkedList* buckets[26];

	int getBucketIndex()
	{
	}

	string convertToLowercase()
	{
		// Convert word to lowercase and remove non-alphabetic characters
	}

public:
	HashTable()
	{
		// Initialize 26 empty buckets
	}

	~HashTable()
	{
		// Delete all buckets to prevent memory leaks
	}

	void loadFromFile()
	{
		// Read words from file and populate hash table
	}

	void displayTable()
	{
		// Display all buckets with their contents
	}

	void addWord()
	{
		// Add word to appropriate bucket
	}

	void removeWord()
	{
		// Remove word from appropriate bucket
	}

	void searchWord()
	{
		// Search for word and display count
	}
};