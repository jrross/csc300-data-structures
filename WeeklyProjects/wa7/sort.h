#ifndef _SORT_H
#define _SORT_H
#include <iostream>
#include <vector>

class Sort
{
protected:
   std::vector<int> values;
public:
   virtual void addVal(int val) = 0;
   virtual void sort() = 0;
   std::vector<int>& getValues();
};

#endif
