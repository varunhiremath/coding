#include <iostream>
#include <climits>
#include <unordered_set>
#include <algorithm>

#include "Graph.h"

// should use a priority-queue kind of data structure here
size_t
minDistVertex(std::vector<double> const &distance,
              std::unordered_set<size_t> visited)
{
  double min = INT_MAX;
  size_t index = 0;

  for (size_t i = 0; i < distance.size(); ++i)
  {
    if (!visited.count(i) && distance[i] < min)
    {
      min = distance[i];
      index = i;
    }
  }

  return index;
}

void
dijkstra(Graph const &graph, size_t const source)
{
  size_t const N = graph.getVertexCount();
  std::vector<double> distance(N, INT_MAX);
  std::unordered_set<size_t> visited;

  distance[source] = 0;

  while (visited.size() != N)
  {
    size_t const vertex = minDistVertex(distance, visited);
    visited.insert(vertex);
    for (auto const& nv : graph.getNeighbors(vertex))
    {
      double const path = distance[vertex] + graph.getEdgeWeight(vertex, nv);
      distance[nv] = std::min(distance[nv], path);
    }
  }

  std::cout<<"Minimum Distance:"<<std::endl;
  for (size_t i = 0; i < N; ++i)
  {
    std::cout<< i << " " << distance[i] << std::endl;
  }
}

int
main()
{
  Graph graph(9);
  graph.addEdge(0,1,4);
  graph.addEdge(0,7,8);
  graph.addEdge(1,7,11);
  graph.addEdge(1,2,8);
  graph.addEdge(7,6,1);
  graph.addEdge(7,8,7);
  graph.addEdge(6,8,6);
  graph.addEdge(2,8,2);
  graph.addEdge(2,3,7);
  graph.addEdge(2,5,4);
  graph.addEdge(6,5,2);
  graph.addEdge(3,5,14);
  graph.addEdge(3,4,9);
  graph.addEdge(4,5,10);

  std::cout<<"Graph" << graph << std::endl;

  dijkstra(graph, 0);

  return 0;
}
