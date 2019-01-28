#include <iostream>
#include <fstream>
#include "graph.h"
#include "dfsPaths.h"

using namespace std;

int main()
{
   Graph *G = new Graph(cin);

   cout << "Graph has " << G->V() << " vertices " << endl;
   cout << "          " << G->E() << " edges" << endl;

   DFSPaths paths(G, "1");

   cout << "Path from 1 -> 7\n";
   for(string w : paths.pathTo("7"))
      cout << w << endl;

   cout << endl;
}
