/**************************************************************************//**
 * @file main.cpp
 *****************************************************************************/
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "bstSort.h"
#include "insertSort.h"

const int VECTOR_SIZE = 100000;

/**************************************************************************//**
 * @brief compareVectors - Verify the two sorted vectors are the same
 *
 * @param[in] lhs - one of the vectors of integers to compare
 * @param[in] hhs - one of the vectors of integers to compare
 *
 * @return bool - true iff both vectors have the same contents
 *****************************************************************************/
bool compareVectors(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
      for (unsigned int i = 0 ; i < lhs.size() ; i++)
      if (lhs[i] != rhs[i])
         return false; 

   return true;
}

/**************************************************************************//**
 * @brief main
 *****************************************************************************/
int main(int argc, char *argv[])
{
   using namespace std::chrono;

   InsertSort *insert = new InsertSort();
   BstSort *bst = new BstSort();
   unsigned vectorLen = VECTOR_SIZE;

   if (argc > 1)
      vectorLen = atoi(argv[1]);

   // Initialize the sort objects by adding random values. Time the process
   high_resolution_clock::time_point t1 = high_resolution_clock::now();
   for (unsigned i = 0 ; i < vectorLen ; i++)
   {
      int randVal = rand();
      bst->addVal(randVal);
      insert->addVal(randVal);
   }
   high_resolution_clock::time_point t2 = high_resolution_clock::now();
   // Stop the timer and report the results
   duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
   std::cout << "Initialization time: "
             << time_span.count() << std::endl;

   // Call the sort method in the insert object and time the operation
   t1 = high_resolution_clock::now();
   insert->sort();
   t2 = high_resolution_clock::now();

   // Report the results of the timing 
   time_span = duration_cast<duration<double>>(t2 - t1);
   std::cout << "Insert Sort: "
             << time_span.count() << std::endl;

   // Call the sort method in the bst object and time the operation
   t1 = high_resolution_clock::now();
   bst->sort();
   t2 = high_resolution_clock::now();

   // Report the results of the timing
   time_span = duration_cast<duration<double>>(t2 - t1);
   std::cout << "BST Sort:    "
             << time_span.count() << std::endl;

   if (compareVectors(bst->getValues(), insert->getValues()))
      std::cout << "Sorted vectors match!\n";
   else
      std::cout << "Sorted vectors DO NOT match!\n";
   return 0;
}
