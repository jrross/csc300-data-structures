#include "sort.h"

Sort::Sort(std::string n, bool q, std::vector<int> v) : name(n), quadratic(q), values(v) {}

Sort::Sort(std::string n, bool q) : name(n), quadratic(q) {}

std::string Sort::Name() { return name ; }

void Sort::addVal(int val) { values.push_back(val); }

std::vector<int>& Sort::getValues() { return values ; }

bool Sort::isQuadratic() { return quadratic ; }

void Sort::printValues()
{
   for (auto x : values)
      std::cout << x << " ";

   std::cout << std::endl;
}
