#include <algorithm>
#include "selectionSort.h"

SelectionSort::SelectionSort(std::string n) : Sort(n, true) {}

SelectionSort::SelectionSort(std::string n, std::vector<int> v) : Sort(n, true, v){}

// You need to implement the sort method for SelectionSort.  See the InsertSort
// implementation for an example
void SelectionSort::sort() 
{
	int small = 0;
	for(int i = 0; i < (int)values.size(); i++)
	{
		small = i;
		for(int j = i + 1; j < (int)values.size(); j++)
		{
			if(values[j] < values[small])
				small = j;
		}
		int temp = values[i];
		values[i] = values[small];
		values[small] = temp;

	}
}
