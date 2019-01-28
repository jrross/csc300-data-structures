/***************************************************************************//**
 * @file dfsPaths.h
 ******************************************************************************/
#ifndef __DFSPATHS_H
#define __DFSPATHS_H
#include <list>
#include <map>
#include <vector>
#include "graph.h"

/***************************************************************************//**
 * @class DFSPaths
 ******************************************************************************/
class DFSPaths
{
   /// Has this vertex been marked (visited/discovered)
   map<string, bool> marked;
   /// From whence was the vertex visited/marked/discovered
   map<string, string> prev;
   /// The start node in the Graph G
   string s;

public:
   /// Constructor
   DFSPaths(Graph *G, string s);

   /// Breadth-first search
   void dfs(Graph *G, string s);
   /// Answers the question, is there a path from the start to vertex 'v'
   bool hasPathTo(string v);
   /// Returns the path (from start node to v) of the path if it exists
   std::list<string> pathTo(string v);
};
#endif
