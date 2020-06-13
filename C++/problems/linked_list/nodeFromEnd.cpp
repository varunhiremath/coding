// Author: Varun Hiremath
// License: BSD 3-Clause

#include <iostream>
#include <vector>

#include "LinkedList.h"

namespace recursive
{
  template <typename T>
  void
  nthNodeFromEnd(Node<T>* &node, size_t const n, size_t &i, T &nth)
  {
    if (!node) return;
    nthNodeFromEnd(node->next(), n, i, nth);
    ++i;
    if (i == n)
      nth = node->data();
  }

  template <typename T>
  T const
  nthFromEnd(LinkedList<T> &list, size_t const n)
  {
    T data = -1;
    size_t i = 0;
    auto head = list.head();
    nthNodeFromEnd(head, n, i, data);
    return data;
  }
}


int
main()
{
  std::vector<int> const data{1,2,3,4,5};
  LinkedList<int> list;
  for (auto const& i : data)
    list.insert(i);

  std::cout<<"Linked List = " << list << std::endl;

  size_t const n = 2;
  int const nth = recursive::nthFromEnd(list, n);

  std::cout<<"The "<<n<<"'th number from the end = " << nth << std::endl;
  return 0;
}
