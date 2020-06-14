#include <iostream>
#include <queue>
#include <set>

#include "Graph.h"

namespace recursive
{
  void
  visitDFS(Graph const& graph,
           size_t const vertex,
           std::set<size_t> &visited)
  {
    std::cout<<vertex<<" ";
    visited.insert(vertex);
    for (auto const& v : graph.getNeighbors(vertex))
    {
      if (!visited.count(v))
        visitDFS(graph, v, visited);
    }
  }

  void
  DFS(Graph const& graph, size_t const source)
  {
    std::set<size_t> visited;
    std::cout<<"DFS: ";
    visitDFS(graph, source, visited);
    std::cout<<std::endl;
  }
}


int
main()
{
  Graph graph(5);
  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(0,3);
  graph.addEdge(2,4);

  std::cout<<"Graph" << graph << std::endl;

  recursive::DFS(graph, 0);
}
