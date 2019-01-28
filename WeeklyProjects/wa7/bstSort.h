#ifndef _BSTSORT_H
#define _BSTSORT_H
#include "sort.h"
#include <iostream>
using namespace std;
struct Node
{
   int data;
   Node* left;
   Node* right;
   Node* parent;
   int ht;

   Node(int d, Node* l=nullptr, Node* r=nullptr, Node* p=nullptr, int h=0): data(d), left(l), right(r), parent(p), ht(h) {}
};


class BstSort : public Sort
{
public:
   BstSort();
   ~BstSort();
   void addVal(int val);
   void sort();
   void recurse (Node *temp);
private:
   Node *root;
};

void swap(Node* &a, Node* &b);
void rotate(Node* &large, Node* &mid, Node* &small);

#endif
