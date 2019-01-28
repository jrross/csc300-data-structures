/***************************************************************************//**
 * @file disjoint.cpp
 ******************************************************************************/
#include <iostream>
#include "disjoint.h"
using namespace std;

/***************************************************************************//**
 * @brief Constructor
 ******************************************************************************/
DisjointSet::DisjointSet() {}

/***************************************************************************//**
 * @brief Implementation of the makeSet member function
 *
 * @param[in] d - The name / item from which to build the set
 ******************************************************************************/
void DisjointSet::makeSet(long d) 
{
	Node *set= new Node(d, 0);
	nodes.emplace(d,set);
}

/***************************************************************************//**
 * @brief Implementation of the union-by-rank member function
 *
 * @par Description
 *    This function will combine two disjoint sets into a single set using the
 * union-by-rank method:
 *
 *    * If one set has a higher rank then another, the smaller ranked set points
 *      to the larger.
 *    * If both sets are the same rank, the set identifed as the second 
 *      parameter is chosen as the representative of the new, combined set and
 *      the rank of the new set is increased by one.
 *    * If the two items are already in the same set, nothing is done.
 *
 * @param[in] first : First set
 * @param[in] second : Second set
 ******************************************************************************/
void DisjointSet::Union(long first, long second) 
{ 
	long int u1 = this->findSet(first);
	long int u2 = this->findSet(second);
	//already in same set
	if(u1 == u2)		
		return;
	map<long int, Node*>::iterator it1;
	map<long int, Node*>::iterator it2;
	it1 = nodes.find(u1);
    it2 = nodes.find(u2);

	if(it1->second->rank >= it2->second->rank)
	{
	it2->second->parent = it1->second;
	it1->second->rank = it1->second->rank + it2->second->rank;
	}
	if(it2->second->rank > it1->second->rank)
	{
	it1->second->parent = it2->second;
	it2->second->rank = it1->second->rank + it2->second->rank;
	}
}

/***************************************************************************//**
 * @brief Implementation of the findSet member function
 *
 * @par Description
 *    Finds the representative member of the set to which data belongs
 *
 * @param[in] data : The data item of interest
 *
 * @return Returns the representative member of the set which contains the
 *    data parameter
 ******************************************************************************/
long DisjointSet::findSet(long data) 
{
	map<long int, Node*>::iterator it;
    it = nodes.find(data);
	if(it == nodes.end())
	{
		this->makeSet(data);
		return data;	
	}
	Node *temp;
	temp = it->second;
	while(temp->parent->data != temp->data)
		temp = temp->parent;
	cout << data << " -> " << temp->data << endl;
	return temp->data;
}

/***************************************************************************//**
 * @brief Helper function for findSet
 *
 * @param[in] node : The node representing the item to be found
 *
 * @return A pointer to a node which is the representative of the set in which
 *    the input parameter 'node' was found
 ******************************************************************************/
Node* DisjointSet::findSet(Node* node) 
{
	while(node->parent->data != node->data)
		node = node->parent;
	return node;
}
