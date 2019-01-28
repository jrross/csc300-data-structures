#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node
{
   int data;
   Node *next;
   
   Node(int d=-1, Node *n=nullptr) : data(d), next(n) {}

   friend std::ostream& operator<<(std::ostream &, const Node*);
};

#endif
