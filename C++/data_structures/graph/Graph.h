#pragma once


#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

class Edge
{
public:
  Edge(size_t const v1, size_t const v2)
    : _id(std::to_string(v1)+"=>"+std::to_string(v2))
  {}

  std::string const id() const { return _id; }

private:
  std::string _id;
};

class Graph
{
public:
  Graph(size_t const vertexCount)
    : _vertexCount(vertexCount)
    , _vertexConnections(vertexCount)
  {}

  size_t const getVertexCount() const { return _vertexCount; }

  void addEdge(size_t const v1, size_t const v2)
  {
    _vertexConnections[v1].insert(v2);
    _vertexConnections[v2].insert(v1);
  }

  void addEdge(size_t const v1, size_t const v2, double const weight)
  {
    _vertexConnections[v1].insert(v2);
    _vertexConnections[v2].insert(v1);
    _edgeWeight[Edge(v1,v2).id()] = weight;
    _edgeWeight[Edge(v2,v1).id()] = weight;
  }

  void addDirectedEdge(size_t const v1, size_t const v2)
  {
    _vertexConnections[v1].insert(v2);
  }

  void addDirectedEdge(size_t const v1, size_t const v2, double const weight)
  {
    _vertexConnections[v1].insert(v2);
    _edgeWeight[Edge(v1,v2).id()] = weight;
  }

  std::set<size_t> const &getNeighbors(size_t const v) const { return _vertexConnections[v]; }

  friend std::ostream& operator<<(std::ostream& out, Graph const &graph)
  {
    out << "\nVertex Connectivity:" << std::endl;
    for (size_t i = 0; i < graph.getVertexCount(); ++i)
    {
      out << i << " => [";
      std::string separator;
      for (auto const &n : graph.getNeighbors(i))
      {
        out << separator << n;
        separator = ",";
      }
      out<<"]" << std::endl;
    }
    return out;
  }

private:
  size_t const _vertexCount;
  std::vector<std::set<size_t>> _vertexConnections;
  std::unordered_map<std::string, double> _edgeWeight;
};
