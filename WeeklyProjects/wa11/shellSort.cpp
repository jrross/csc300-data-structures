#include <algorithm>
#include "shellSort.h"

using namespace std;

ShellSort::ShellSort(std::string n) : Sort(n, false) {}

ShellSort::ShellSort(std::string n, std::vector<int> v) : Sort(n, false, v) {}

// You need to implement the sort method for ShellSort.  See the InsertSort
// implementation for an example
void ShellSort::sort() 
{
	unsigned gap = 1;
	while(gap < values.size()/3)
		gap = gap*3 + 1;
	
	while(gap >= 1)
	{	
		for(unsigned i = 1; i < values.size(); i++)
		{
			unsigned j = i;
       		while ( j >= gap && values[j - gap] > values[j] )
       		{
           		std::swap(values[j], values[j-gap]);
           		j = j - gap;
			}
		}
		gap = gap/3;	
	}

}
