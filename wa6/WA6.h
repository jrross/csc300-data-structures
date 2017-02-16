#ifndef WA6_H
#define WA6_H
#include "node.h"

Node *insert(Node* root, int val);
void swap(Node* &a, Node* &b);
void rotate(Node* &large, Node* &mid, Node* &small, bool r);

#endif
