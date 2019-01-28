#ifndef _INSERTSORT_H
#define _INSERTSORT_H
#include "sort.h"

class InsertSort : public Sort
{
public:
   InsertSort(std::string);
   InsertSort(std::string, std::vector<int>);
   void sort();
};

#endif
