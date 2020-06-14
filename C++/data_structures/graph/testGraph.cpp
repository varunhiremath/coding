#include "Graph.h"

int
main()
{
  Graph graph(10);
  graph.addEdge(0,1,10);
  graph.addEdge(1,2,10);
  graph.addEdge(0,3);
  graph.addDirectedEdge(0,9);

  std::cout<<"Graph = " << std::endl << graph << std::endl;

  return 0;
}
