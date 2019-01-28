#include "node.h"

std::ostream& operator<<(std::ostream &os, const Node *node)
{
   std::cout << node->data;
   return os;
}
