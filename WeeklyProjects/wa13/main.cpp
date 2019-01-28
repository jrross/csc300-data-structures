#include <iostream>
#include <fstream>
#include <string>
#include "digraph.h"
#include "bipartite.h"
#include "cc.h"
#include "toposort.h"

using namespace std;

int main(int argc, char **argv)
{
   Digraph *G = new Digraph(cin);
   CC cc(G);
   TopoSort topo(G);

   if (isBipartite(G, "3"))
      cout << "Graph is Bipartite" << endl;
   else
      cout << "Graph is NOT Bipartite" << endl;

   cout << "Number of connected components in the graph is " << cc.count() << endl;

   cout << "Graph has " << G->V() << " vertices " << endl;
   cout << "          " << G->E() << " edges" << endl;
   cout << "Topological ordering:" << endl;

   stack<string> reverse = topo.reversePostOrder();
   while (!reverse.empty())
   {
      cout << reverse.top() << " ";
      reverse.pop();
   }
   cout << endl;

   delete G;   
   return 0;
}
