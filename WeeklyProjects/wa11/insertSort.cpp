#include "insertSort.h"

InsertSort::InsertSort(std::string n) : Sort(n, true) {}

InsertSort::InsertSort(std::string n, std::vector<int> v) : Sort(n, true, v) {}

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
