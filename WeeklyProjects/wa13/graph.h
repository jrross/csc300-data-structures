#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <map>
#include <list>
#include <set>
#include <string>
#include <fstream>

using namespace std;

/// Convenience typedef
typedef map<string, set<string> > map_t;

/******************//*
 * @class Graph 
 ********************/
class Graph
{
   /// The adjacency lists
   map_t vertices;

protected:
   /// The number of vertices in the graph
   int numVertices;
   /// The number of edges
   int numEdges;

public:
   /// Default constructor
   Graph();
   /// Stream constructor
   Graph(istream&);

   /// Return the list of vertices in the graph
   list<string> Vertices() const;
   /// Accessor for adjacency list
   set<string> adj(string v);
   /// Add an edge to the graph
   virtual void addEdge(string, string);
   /// Accessor for the number of vertices
   int V() const;
   /// Accessor for the number of edges
   int E() const;
};

#endif
