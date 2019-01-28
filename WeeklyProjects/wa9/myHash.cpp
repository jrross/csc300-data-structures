#include <iostream>
#include <algorithm>
#include "myHash.h"
#include <iostream>

using namespace std;

Hash::Hash(int size) : hashSize(size) 
{
	hashTable.resize(hashSize);
}

// Calculate the load factor
double Hash::loadFactor() const
{
   return static_cast<double>(hashItems) / static_cast<double>(hashSize);
}

// Return the hash table size
unsigned int Hash::size() const { return hashSize; }

// Create a hash function.  Consider the issues we discussed in class
// We'll do some analysis of the different hash codes people come up
// with along with a visualization
unsigned int Hash::hashCode(const string& str) const
{
	unsigned int temp = 0;
	for (int i = 0; i < (int)str.length() ; i++)
	{
		temp = temp + (unsigned int)str[i];
	}
	temp = temp % hashSize;
   return temp;
}

// Consider how to insert something into the right list
// Also, consider what to do if the item already exists in the list
void Hash::insert(const string key, const string value)
{
	hashTable[this->hashCode(key)].push_back(Entry(key, value));
	hashItems++;
	if(this->loadFactor() > 0.5)
		this->rehash();
}


void Hash::insert(const Entry& entry)
{
	hashTable[this->hashCode(entry.key)].push_back(entry);
	hashItems++;
	if(this->loadFactor() > 0.5)
		this->rehash();

}
// Remove an item from the hash table.
// Consider what to do if the item isn't in the hash table
void Hash::remove(const string key)
{
	list<Entry>::iterator it;
	it = this->search(key);
	int val = hashCode(key);
	if ( it->key == key)
		hashTable[val].erase(it);
}

// Find an item in the hash table.
// Consider what to return if the item isn't found in the hash table
list<Entry>::iterator Hash::search(const string& key)
{
	list<Entry>::iterator it;
	unsigned int val = this->hashCode(key);
	for( it = hashTable[val].begin(); it != hashTable[val].end(); it++ )
		if ( it->key == key)
			return it;
	return hashTable[val].end(); 
}

// Rehash the hash table
// Remember the steps required to complete a rehash
// 1. Save off the existing entries in the hash table
// 2. Increase the size of the hash table by roughly 2x
// 3. Rehash each of the existing elements into the new hash table
void Hash::rehash()
{ 
	vector<Entry> temp;
	for( int i = 0 ; i < (int)hashSize ; i++ )
	{
		while(!hashTable[i].empty()) //check if the list is empty
		{
			temp.push_back(hashTable[i].front());
			hashTable[i].pop_front();
		}
	}
	hashSize = hashSize * 2 + 1;
	hashTable.resize(hashSize);
	hashItems = 0;
	for (int i = 0 ; i < (int)temp.size() ; i ++)	
		this->insert( temp[i].key , temp[i].value );
	temp.clear();
}
