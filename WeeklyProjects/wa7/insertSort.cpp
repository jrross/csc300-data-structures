#include "insertSort.h"

void InsertSort::addVal(int i)
{
   values.push_back(i);
}

void InsertSort::sort()
{
    for (unsigned i = 1; i < values.size(); i++)
    {
        int j = i;
        while ( j > 0 && values[j - 1] > values[j] )
        {
            std::swap(values[j], values[j-1]);
            j--;
        }
    }
}
