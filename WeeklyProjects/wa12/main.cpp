#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

/***************************************************************************//**
 * @brief Main function
 *
 * @par Description
 *    A simple driver for the Graph Class to verify that the Graph object is
 * being correctly constructed.
 ******************************************************************************/
int main()
{
   Graph *G = new Graph(cin);

   cout << "Number of Vertices: " << G->V() << endl;
   cout << "Number of Edges   : " << G->E() << endl;

   cout << "Adjacency List:" << endl;
   cout << "Vertex   AdjList" << endl;
   for(string v : G->Vertices())
   {
      cout << setw(4) << v << "     ";
      for (string value : G->adj(v))
         cout << " " << value; 
      cout << endl;
   }
}
