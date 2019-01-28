#ifndef __AVLSORT_H
#define __AVLSORT_H
#include "sort.h"
#include "function.h"

class AVLSort : public Sort
{
public:
   AVLSort(std::string n);
   AVLSort(std::string n, std::vector<int> v);
   void addVal(int val);
   void sort();
   void recurse (Node *temp);
   void recurseDelete (Node *temp);
private:
   Node *root;
};
void rotate(Node* large, Node* mid, Node* small);
void rotateRight(Node* upper, Node* lower, bool twoRotations);
void rotateLeft(Node* upper, Node* lower, bool twoRotations);
#endif
