/***************************************************************************//**
 * @file node.h
 ******************************************************************************/
#ifndef __NODE_H
#define __NODE_H

/// brief the tree node structure
struct Node
{
   int data;
   Node *left;
   Node *right;
   int ht;

   Node(int d, Node* l=nullptr, Node* r=nullptr, int h=0): data(d), left(l), right(r), ht(h) {}
};
#endif
