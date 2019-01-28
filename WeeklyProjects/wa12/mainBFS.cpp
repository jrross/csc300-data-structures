#include <iostream>
#include <fstream>
#include "graph.h"
#include "bfsPaths.h"

using namespace std;

int main()
{
   Graph *G = new Graph(cin);

   BFSPaths paths(G, "1");

   cout << "Graph has " << G->V() << " vertices " << endl;
   cout << "          " << G->E() << " edges" << endl;
   cout << "Path from 1 -> 7\n";
   for(string w : paths.pathTo("7"))
      cout << w << endl;
   
   cout << "Distance: " << paths.Distance("7") << endl;
}
