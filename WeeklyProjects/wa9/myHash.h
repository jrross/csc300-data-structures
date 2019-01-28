#ifndef __MYHASH_H_
#define __MYHASH_H_
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Entry
{
   string key;
   string value;
   Entry(string k, string v) : key(k), value(v){}
};

#define REHASH_LIMIT 1.0

class Hash
{
   vector<list<Entry> > hashTable;
   unsigned int hashSize;
   unsigned int hashItems;

public:
   Hash(int size=10);

   void insert(const string k, const string v);
   void insert(const Entry& entry);
   void remove(const string k);
   list<Entry>::iterator search(const string& key);

private:
   unsigned int hashCode(const string&) const;
   double loadFactor() const;
   void rehash();
   unsigned int size() const;
};

#endif
