/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

/***************************************************************************//**
 * @class
 ******************************************************************************/
class LinkedList
{
   /// Head pointer for the list
   Node *head;
   /// Tail pointer for the list
   Node *tail;

public:
   /// Constructor
   LinkedList();

   /// Destructor
   ~LinkedList();

   /// Append a node to the list (push_back)
   void append(Node *);

   /// Prepend a node to the list (push front)
   void prepend(Node *);

   /// Insert a node into the list after a given node
   void insertAfter(Node*, Node*);

   /// Remove a node that follows a given node in the list
   void removeAfter(Node*);

   /// Print the list
   void print() const;

   /// Find a node by its data item
   Node *find(int d);
};
#endif
