#include <iostream>
#include <queue>
#include <set>

#include "Graph.h"

namespace queue
{
  void
  visitBFS(Graph const& graph,
           std::queue<size_t> &toVisit,
           std::set<size_t> &visited)
  {
    while (!toVisit.empty())
    {
      size_t const vertex = toVisit.front();
      std::cout<<vertex<<" ";
      visited.insert(vertex);
      toVisit.pop();
      for (auto const& v : graph.getNeighbors(vertex))
      {
        if (!visited.count(v))
          toVisit.push(v);
      }
    }
  }

  void
  BFS(Graph const& graph, size_t const source)
  {
    std::set<size_t> visited;
    std::queue<size_t> toVisit;
    toVisit.push(source);
    std::cout<<"BFS: ";
    visitBFS(graph, toVisit, visited);
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

  queue::BFS(graph, 0);
}
