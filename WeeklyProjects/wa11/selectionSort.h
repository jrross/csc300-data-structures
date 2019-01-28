#ifndef _SELECTIONSORT_H
#define _SELECTIONSORT_H
#include "sort.h"

class SelectionSort : public Sort
{
public:
   SelectionSort(std::string);
   SelectionSort(std::string, std::vector<int>);
   void sort();
};

#endif
