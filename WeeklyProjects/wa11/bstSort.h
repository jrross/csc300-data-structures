#ifndef __BSTSORT_H
#define __BSTSORT_H
#include "sort.h"
#include "function.h"

class BSTSort : public Sort
{
public:
   BSTSort(std::string n);
   BSTSort(std::string n, std::vector<int> v);
   void sort();
   void addVal(int val);
   void recurse (Node *temp);
   void recurseDelete(Node *temp);
private:
   Node *root;
};

#endif
