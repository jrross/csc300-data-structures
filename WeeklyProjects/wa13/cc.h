#include <iostream>
#include <unordered_map>
#include "graph.h"
using namespace std;

class CC
{
   unordered_map<string, bool> marked;
   unordered_map<string, int> cc;
   int ccount;
public:
   CC(Graph *G);

   bool areConnected(string v, string w);
   int count();
   int id(string v);
private:
   void discover(Graph *G, string start);
};
