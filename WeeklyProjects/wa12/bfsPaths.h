/***************************************************************************//**
 * @file bfsPaths.h
 ******************************************************************************/
#ifndef __BFSPATHS_H
#define __BFSPATHS_H
#include <list>
#include <map>
#include <queue>
#include <vector>
#include "graph.h"

struct Info
{
   /// Has the vertex been marked
   bool marked;
   /// What is the distance from the start to this vertex
   int dist;
   /// From which vertex was this vertex discovered
   string prev;
};

/***************************************************************************//**
 * @class BFSPaths
 ******************************************************************************/
class BFSPaths
{
   /// A boolean vector to indicate a vertex was visited during the BFS
   map<string, Info> info;
   /// The start node in the Graph G
   string s;

public:
   /// Constructor
   BFSPaths(Graph *G, string s);

   /// Breadth-first search
   void bfs(Graph *G, string s);
   /// Answers the question, is there a path from the start to vertex 'v'
   bool hasPath(string v);
   /// Returns the path (from start node to v) of the path if it exists
   std::list<string> pathTo(string v);
   /// Return the distance from the source to vertex 'v'
   int Distance(string v);
};
#endif
