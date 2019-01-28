#ifndef WA6_H
#define WA6_H
#include "node.h"

Node *insert(Node* root, int val);
void rotate(Node* large, Node* mid, Node* small);
void rotateRight(Node* upper, Node* lower, bool twoRotations);
void rotateLeft(Node* upper, Node* lower, bool twoRotations);

#endif
