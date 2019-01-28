#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <algorithm>
#include "avlSort.h"
#include "bstSort.h"
#include "insertSort.h"
#include "selectionSort.h"
#include "shellSort.h"

using namespace std;

const int VECTOR_SIZE = 10000;

// Here is an example main that uses the derived sort objects.
//
// The sorts vector is a vector of pointers to Sort objects
//
// This will not work from the startup code.  You will be required to 
// populate derived classes for the InsertSort, SelectionSort, ShellSort,
// BSTSort, and AVLSort.
//
// You should already have the code necessary for Insert and AVL with some
// simple refactoring.  Note that the Sort base class is slightly expanded
// from that used in the WA7 and WA8 assignments.
//
int main(int argc, char **argv)
{
   using namespace std::chrono;

   vector<Sort*> sorts;
   vector<int> sortedValues;

   sorts.push_back(new InsertSort("Insert Sort"));
   sorts.push_back(new SelectionSort("Selection Sort"));
   sorts.push_back(new ShellSort("Shell Sort"));
   sorts.push_back(new BSTSort("BST Sort"));
   sorts.push_back(new AVLSort("AVL Sort"));

   unsigned vectorLen = VECTOR_SIZE;

   // If there is a command line argument, try to use that as the vector length
   if (argc > 1)
      vectorLen = atoi(argv[1]);

   // Start the timer to see how long initialization takes
   high_resolution_clock::time_point t1 = high_resolution_clock::now();
   for (unsigned i = 0 ; i < vectorLen ; i++)
   {
      int randVal = rand();
      sortedValues.push_back(randVal);
      for (Sort *s : sorts)
         s->addVal(randVal);
   }

   high_resolution_clock::time_point t2 = high_resolution_clock::now();
   duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
   std::cout << "Initialization time: "
             << time_span.count() << std::endl;

   // Use the STL sort to create a sorted list to compare all the other sorts
   t1 = high_resolution_clock::now();
   std::sort(sortedValues.begin(), sortedValues.end());
   t2 = high_resolution_clock::now();

   time_span = duration_cast<duration<double>>(t2 - t1);

   std::cout << "STL Sort " << time_span.count() << std::endl;

   // Loop over all the sort objects in the sorts vector.  Run the individual
   // sorts and time them.
   for (Sort *s : sorts)
   {
      if (vectorLen >= 100000 && s->isQuadratic())
         std::cout << "Skipping " << s->Name() << " due to size\n";
      else
      {
         t1 = high_resolution_clock::now();
         s->sort();
         t2 = high_resolution_clock::now();

         time_span = duration_cast<duration<double>>(t2 - t1);
         std::cout << s->Name() << ":" << time_span.count() << std::endl;   

         // Compare the result of each sort object with the expected values
         if (!compareVectors(sortedValues, s->getValues()))
            std::cout << s->Name() << " sort failed!\n";
      }
   }

   // Call each of the sort object's destructors
   for (Sort *s : sorts)
     delete s;
      
   return 0;
}
