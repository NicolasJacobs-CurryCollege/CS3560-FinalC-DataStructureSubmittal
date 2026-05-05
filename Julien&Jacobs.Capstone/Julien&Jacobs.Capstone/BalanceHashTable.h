#ifndef BALANCEHASHTABLE_H
#define BALANCEHASHTABLE_H

#include "LinkedList.h"
#include <string>
using namespace std;

class BalanceHashTable
{
private:
	LinkedList* buckets[10];
	int counts[10];
	string letters[10];

	void createBuckets();
	void setUsedBuckets(bool used[]);
	void loadBuckets(LinkedList** originalBuckets, bool used[]);
	void addBucket(LinkedList* list, char letter);

	int getBucketIndex();
	int getBucketCount(LinkedList* list);
	int getNextBucket(LinkedList** originalBuckets, bool used[]);

public:
	BalanceHashTable(LinkedList** originalBuckets);
	~BalanceHashTable();
	void displayBalancedTable();
};

#endif