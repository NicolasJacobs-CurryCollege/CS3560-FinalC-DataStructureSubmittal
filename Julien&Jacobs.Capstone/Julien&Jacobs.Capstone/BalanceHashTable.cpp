#include "BalanceHashTable.h"
#include <iostream>
using namespace std;

BalanceHashTable::BalanceHashTable(LinkedList** originalBuckets) // builds balanced table from original 26 buckets
{
	bool used[26];

	createBuckets();
	setUsedBuckets(used);
	loadBuckets(originalBuckets, used);
}

BalanceHashTable::~BalanceHashTable() // frees memory for created buckets
{
	for (int n = 0; n < 10; n++)
	{
		delete buckets[n];
	}
}

void BalanceHashTable::createBuckets() // creates 10 empty buckets and initializes tracking arrays
{
	for (int n = 0; n < 10; n++)
	{
		buckets[n] = new LinkedList();
		counts[n] = 0;
		letters[n] = "";
	}
}

void BalanceHashTable::setUsedBuckets(bool used[]) // sets all original alphabet buckets to unused
{
	for (int n = 0; n < 26; n++)
	{
		used[n] = false;
	}
}

void BalanceHashTable::loadBuckets(LinkedList** originalBuckets, bool used[]) // distributes original buckets into balanced buckets
{
	for (int n = 0; n < 26; n++)
	{
		int bucket = getNextBucket(originalBuckets, used); // find largest unused original bucket
		char letter = 'a' + bucket;

		addBucket(originalBuckets[bucket], letter);
		used[bucket] = true; // mark this alphabet bucket as already used
	}
}

void BalanceHashTable::addBucket(LinkedList* list, char letter) // adds one alphabet bucket into the smallest balanced bucket
{
	int bucket = getBucketIndex(); // find smallest current combined bucket
	Node* current = list->getHeadNode();

	while (current != nullptr)
	{
		for (int n = 0; n < current->getCount(); n++) // insert word multiple times based on its frequency
		{
			buckets[bucket]->addWord(current->getWord());
		}

		current = current->getNextNode();
	}

	counts[bucket] += getBucketCount(list); // update total words in this bucket
	letters[bucket] += letter; // record which letter group was added
}

void BalanceHashTable::displayBalancedTable() // prints all balanced buckets with contents and counts
{
	cout << "\nBalanced Hash Table (10 buckets)\n" << endl;

	for (int n = 0; n < 10; n++)
	{
		cout << "Bucket [" << letters[n] << "]: ";
		cout << "Total Words: " << counts[n] << endl;
		buckets[n]->displayList();
		cout << endl;
	}
}

int BalanceHashTable::getBucketIndex() // finds index of bucket with smallest word count
{
	int bucket = 0;

	for (int n = 0; n < 10; n++)
	{
		if (counts[n] < counts[bucket]) // choose bucket with least words to keep balance
		{
			bucket = n;
		}
	}

	return bucket;
}

int BalanceHashTable::getBucketCount(LinkedList* list) // calculates total words (including duplicates) in a bucket
{
	int count = 0;
	Node* current = list->getHeadNode();

	while (current != nullptr)
	{
		count += current->getCount(); // adds frequency, not just unique nodes
		current = current->getNextNode();
	}

	return count;
}

int BalanceHashTable::getNextBucket(LinkedList** originalBuckets, bool used[]) // finds largest unused original bucket
{
	int bucket = -1;

	for (int n = 0; n < 26; n++)
	{
		if (used[n] == false)
		{
			if (bucket == -1 || getBucketCount(originalBuckets[n]) > getBucketCount(originalBuckets[bucket]))
				// first condition initializes, second selects bucket with highest word count
			{
				bucket = n;
			}
		}
	}

	return bucket;
}