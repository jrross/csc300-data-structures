/***************************************************************************//**
 * @file function.cpp
 ******************************************************************************/
#include "function.h"

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
      if (lhs.size() != rhs.size()) return false;
      for (unsigned int i = 0 ; i < lhs.size() ; i++)
      if (lhs[i] != rhs[i])
      {
         std::cout << "At index[" << i << "] Expected : " << lhs[i] << "\n";
         std::cout << "             Got      : " << rhs[i] << "\n";
         return false;
      }

   return true;
}
