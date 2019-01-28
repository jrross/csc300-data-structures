/***************************************************************************//**
 * @file disjoint.h
 ******************************************************************************/
#ifndef __DISJOINT_H_
#define __DISJOINT_H_
#include <map>
using namespace std;

/// The node structure used to represent an item in the set. Note the rank
/// field which implies we're doing union-by-rank
struct Node
{
   /// The identifying value for this item
   long int data;
   /// The rank of this item (if it's the representative item else undefined)
   int rank;
   /// The parent of this item (self-reference indicates this is representative)
   Node *parent;

   /// Constructor
   Node(long int d, int r) : data(d), rank(r), parent(this){}
      friend class Observer; 
};

/***************************************************************************//**
 * @class
 *
 * @par Description
 *    A union-find class that supports some simple operations
 *
 *    * makeSet : Create a set in the universe
 *    * Union   : Perform the union-by-rank operation on two disjoint sets
 *    * findSet : Find to which set an item belongs
 ******************************************************************************/
class DisjointSet
{
   /// A map containing the items in the universe
   map<long int, Node*> nodes;

public:
   /// Constructor
   DisjointSet();

   /// make a set from an item
   void makeSet(long int d);
   
   /// Perform a union-by-rank on two items
   void Union(long int first, long int second);

   /// Return the representative member of the set in which 'node' resides
   long int findSet(long int node);

private:
   /// Internal function used to do a findSet operation
   Node* findSet(Node*); 
      friend class Observer; 
};
#endif
