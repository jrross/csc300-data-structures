Digraph::Digraph() { }

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

virtual void addEdge(string v, string w)
{
	vertices[v].insert(w);
}
