#include "graph.h"

using namespace std;

class Digraph : public Graph
{
public: 
   /// Default constructor
   Digraph();
   /// Stream constructor
   Digraph(istream&)

   virtual void addEdge(string, string);
};

