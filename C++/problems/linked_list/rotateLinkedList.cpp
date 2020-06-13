// Author: Varun Hiremath
// License: BSD 3-Clause

#include <iostream>
#include <vector>

#include "LinkedList.h"

namespace iterative
{
  template <typename T>
  void
  rotate(LinkedList<T> &list, size_t N)
  {
    Node<T>* currentHead = list.head();
    Node<T>* currentTail = list.tail();
    Node<T>* newHead = currentHead;
    Node<T>* newTail = nullptr;

    for (size_t i = 0; i < N; ++i)
    {
      if (!newHead) return;
      newTail = newHead;
      newHead = newHead->next();
    }

    list.head() = newHead;
    currentTail->next() = currentHead;
    newTail->next() = nullptr;
    list.tail() = newTail;
  }
}

int
main()
{
  std::vector<int> const data{1,2,3,4,5};
  LinkedList<int> list;
  for (auto const& i : data)
    list.insert(i);

  std::cout<<"Original Linked List = " << list << std::endl;

  size_t const num = 3;
  iterative::rotate(list, num);

  std::cout<<"Rotated by " << num << " Linked List = " << list << std::endl;

  return 0;
}
