#include "HashTable.h"
#include <iostream>
#include <fstream>
using namespace std;

HashTable::HashTable() // creates 26 buckets (a–z)
{
	for (int n = 0; n < 26; n++)
	{
		buckets[n] = new LinkedList();
	}
}

HashTable::~HashTable() // deletes all buckets to free memory
{
	for (int n = 0; n < 26; n++)
	{
		delete buckets[n];
	}
}

void HashTable::loadFromFile(string inputFile) // reads file and inserts words into correct buckets
{
	ifstream file(inputFile);

	if (!file.is_open())
	{
		cout << "ERROR: Cannot open file: " << inputFile << endl;
		return;
	}

	string word;

	while (file >> word)
	{
		string lower = convertToLowercase(word);

		if (lower != "")
		{
			int bucket = getBucketIndex(lower);
			buckets[bucket]->addWord(lower);
		}
	}

	file.close();
}

void HashTable::displayTable() // displays all non-empty alphabet buckets
{
	cout << "\nHash Table (26 buckets)\n" << endl;

	for (int n = 0; n < 26; n++)
	{
		Node* head = buckets[n]->getHeadNode();
		if (head != nullptr)
		{
			char letter = 'a' + n;
			cout << "Bucket [" << letter << "]: ";
			buckets[n]->displayList();
			cout << endl;
		}
	}
}

void HashTable::addWord(string word) // adds a word to its correct bucket
{
	string lower = convertToLowercase(word);
	int bucket = getBucketIndex(lower);
	buckets[bucket]->addWord(lower);
}

void HashTable::removeWord(string word) // removes a word from its bucket
{
	string lower = convertToLowercase(word);
	int bucket = getBucketIndex(lower);
	buckets[bucket]->removeWord(lower);
}

void HashTable::searchWord(string word) // searches for a word in its bucket and prints count
{
	string lower = convertToLowercase(word);
	int bucket = getBucketIndex(lower);
	Node* current = buckets[bucket]->getHeadNode();

	while (current != nullptr)
	{
		if (current->getWord() == lower)
		{
			cout << "Word \"" << lower << "\" appeared " << current->getCount() << " time(s)" << endl;
			return;
		}
		current = current->getNextNode();
	}

	cout << "Word \"" << lower << "\" did not appear in the address" << endl;
}

string HashTable::convertToLowercase(string word) // removes non-letters and converts all characters to lowercase
{
	string lower = "";

	for (int n = 0; n < word.length(); n++)
	{
		if ((word[n] >= 'A' && word[n] <= 'Z') || (word[n] >= 'a' && word[n] <= 'z'))
		{
			if (word[n] >= 'A' && word[n] <= 'Z')
			{
				lower += word[n] + 32;
			}
			else
			{
				lower += word[n];
			}
		}
	}

	return lower;
}

int HashTable::getBucketIndex(string word) // maps first letter to index 0–25 (a=0, ..., z=25)
{
	return (int)word[0] - (int)'a';
}

// A simple direct-address hash based on the first character
// Take the first letter of the word
// Convert that letter to its ASCII number
// Subtract the ASCII number of 'a' from that number to get the bucket index

LinkedList** HashTable::getBuckets() // returns the original 26 buckets
{
	return buckets;
}