#include <iostream>
#include "graph.h"

Graph::Graph() { } // for the derived types
/***************************************************************************//**
 * @brief Constructor
 *
 * @param[in] fin - The input stream from which to build the graph
 ******************************************************************************/
Graph::Graph(istream& fin)
{
   while (!fin.eof())
   {
      string line;
      getline(fin, line);
      string v = line.substr(0, line.find('|'));
      string w = line.substr(line.find('|')+1);
      if (v.length() < 1 || w.length() < 1) continue;
      addEdge(v, w);
   }

   numVertices = vertices.size();
   numEdges = 0;
   for (map_t::iterator it = vertices.begin() ;
        it != vertices.end() ; it++)
      numEdges += (*it).second.size();
}

/***************************************************************************//**
 * @brief Return the number of vertices in the graph
 *
 * @return integer representing the number of vertices in the graph
 ******************************************************************************/
int Graph::V() const { return numVertices ; }

/***************************************************************************//**
 * @brief Return the number of edges in the graph
 *
 * @return integer representing the number of edges in the graph
 ******************************************************************************/
int Graph::E() const { return numEdges ; }

/***************************************************************************//**
 * @brief Return the list of vertex names
 *
 * @return a list of strings representing the vertex names in the graph
 ******************************************************************************/
list<string> Graph::Vertices() const
{
   list <string> retList;
   for (pair<string, set<string>> item : vertices)
      retList.push_back(item.first);
   return retList;
}

/***************************************************************************//**
 * @brief Return the set of vertices adjacent to vertix v
 *
 * @param[in] v - The vertex to which the adjacency list belongs
 * @return a list of strings representing the vertices adjacent to v
 ******************************************************************************/
set<string> Graph::adj(string v)
{
   return vertices[v];
}

/***************************************************************************//**
 * @brief Add an edge to the graph
 *
 * @par Description
 *    This is the default addEdge method which implements the addition of an
 * undirected edge.
 *
 * @param[in] v - The vertex at the origin of the edge
 * @param[in] w - The vertex at the destination of the edge
 ******************************************************************************/
void Graph::addEdge(string v, string w)
{
   vertices[v].insert(w);
   vertices[w].insert(v);
}
