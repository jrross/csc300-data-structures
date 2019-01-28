/***************************************************************************//**
 * @file dfsPaths.cpp
 ******************************************************************************/
#include "dfsPaths.h"

/***************************************************************************//**
 * @brief Constructor
 *
 * @par Description
 *    Takes a Graph object (G) and the name of a starting node (s) and 
 * constructs a DFSPaths object.  During construction the Graph is traversed
 * with a depth-first-search algorithm and data are collected so that certain
 * questions about the graph can be answered.
 *
 * @param[in] Graph - G - The graph used to construct the DFSPaths object
 * @param[in] string - s - The name of the starting vertex from which to
 *   perform the dfs
 ******************************************************************************/
DFSPaths::DFSPaths(Graph *G, string v) : s(v)
{
   dfs(G, s); 
}

/***************************************************************************//**
 * @brief Answers the question, "Is there a path from the start node to node v"
 *
 * @par Complexity
 *    Answers the question in constant O(1) time
 *
 * @param[in] string s : Is there a path from the start vertex to vertex v
 * 
 * @returns true iff there is a path from vertex v to the start vertex
 ******************************************************************************/
bool DFSPaths::hasPathTo(string v)
{
   return marked[v];
}

/***************************************************************************//**
 * @brief If a path exists, return the nodes on the path
 *
 * @par Complexity
 *    O(l) where 'l' is the number of vertices on the path
 *
 * @param[in] string v - The destination vertex on the expected path
 * 
 * @return list<string> - The list of the vertices on the path
 ******************************************************************************/
std::list<string> DFSPaths::pathTo(string v)
{
   std::list<string> path;
   if (!hasPathTo(v)) return path;
   for (string x = v ; x != s ; x = prev[x])
      path.push_front(x);
   path.push_front(s);
   return path;
}

/***************************************************************************//**
 * @brief Perform a depth first search on Graph G starting at node v
 *
 * @par Complexity:
 *    O(V + E) where V is the number of vertices and E is the number of edges
 *
 * @param[in] Graph G - Graph object upon which to operate
 * @param[in] string v - vertex from which to do the depth first search
 ******************************************************************************/
void DFSPaths::dfs(Graph *G, string v)
{
   marked[v] = true;
   for (string w : G->adj(v))
   {
      if (!marked[w])
      {
         dfs(G, w);
         prev[w] = v;
      }
   }
}
