#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <string>
using namespace std;

class HashTable
{
private:
	LinkedList* buckets[26];
	int getBucketIndex(string word);
	string convertToLowercase(string word);

public:
	HashTable();
	~HashTable();
	void loadFromFile(string inputFile);
	void displayTable();
	void addWord(string word);
	void removeWord(string word);
	void searchWord(string word);
	LinkedList** getBuckets();
};

#endif