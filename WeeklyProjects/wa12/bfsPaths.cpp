/***************************************************************************//**
 * @file bfsPaths.cpp
 ******************************************************************************/
#include "bfsPaths.h"

/***************************************************************************//**
 * @brief Breadth-first Search Path client
 *
 * @par Description
 *    A class which will take a Graph object and perform a graph-linear time
 *    breadth-first search from a starting node to collect path data.
 * 
 * @param[in] G - The graph in question
 * @param[in] s - The starting node (vertex)
 *
 ******************************************************************************/
BFSPaths::BFSPaths(Graph *G, string v) : s(v) 
{
   bfs(G, s);
}

/***************************************************************************//**
 * @brief Is there a path from the start node 's' to the target 'v'?
 *
 * @par Description
 *    Constant time function to answer the question of whether or not a path
 * exists from the start node to node 'v'
 *
 * @param[in] v - The vertex in question
 ******************************************************************************/
bool BFSPaths::hasPath(string v) 
{ 
   return info[v].marked;
}

/***************************************************************************//**
 * @brief What is the distance (length) of the path from the start 's' to 'v'
 *
 * @par Description
 *    Constant time function to answer the question of the length of the path
 * from the start node to node 'v'
 *
 * @param[in] v - The vertex in question
 ******************************************************************************/
int BFSPaths::Distance(string v)
{
   return info[v].dist;
}

/***************************************************************************//**
 * @brief What is the path from the start 's' to 'v'
 *
 * @par Description
 *    Return the path from the start node (s) to the target node (v) in time
 * proportional to the length of the path.
 *
 * @param[in] v - The vertex in question
 *
 * @returns a list of the nodes from the start node to the target node
 ******************************************************************************/
std::list<string> BFSPaths::pathTo(string v)
{     
   std::list<string> path;
   if(!hasPath(v))
      return path;
   path.push_front(v);
   while(v != s)
   {
      v = info[v].prev;
      path.push_front(v);
   }
   return path;
}
/***************************************************************************//**
 * @brief Perform a breadth-first search on Graph G
 *
 * @par Description
 *    In graph-linear time, perform a breadth first search on the graph and
 * discover the connected components and their distance to the start node.
 *
 * @param[in] G - Graph to be searched
 * @param[in] s - The node from which the search should start
 ******************************************************************************/
void BFSPaths::bfs(Graph *G, string s)
{
   queue<string> q;
   q.push(s);
   info[s].marked = true;
   info[s].dist = 0;
   info[s].prev = "";
   while(!q.empty())
   {
      string y = q.front();
      q.pop();
      for (string x : G->adj(y))
      {
         if(!info[x].marked)
         {
            info[x].dist = info[y].dist + 1;
            info[x].prev = y;
            info[x].marked = true;
            q.push(x);
         }
      }
   }
}
