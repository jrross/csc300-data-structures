#ifndef _SHELLSORT_H
#define _SHELLSORT_H
#include "sort.h"

class ShellSort : public Sort
{
public:
   ShellSort(std::string);
   ShellSort(std::string, std::vector<int>);
   void sort();
};

#endif
