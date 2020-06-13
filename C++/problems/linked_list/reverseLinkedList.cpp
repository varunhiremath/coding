// Author: Varun Hiremath
// License: BSD 3-Clause

#include <iostream>
#include <vector>

#include "LinkedList.h"

namespace recursive
{
  template <typename T>
  void
  reverseNodes(Node<T>* &node)
  {
    if (!node->next()) return;
    reverseNodes(node->next());
    node->next()->next() = node;
  }


  template <typename T>
  void
  reverse(LinkedList<T> &list)
  {
    auto head = list.head();
    reverseNodes(head);
    list.head() = list.tail();
    head->next() = nullptr;
    list.tail() = head;
  }
}

namespace iterative
{
  template <typename T>
  void
  reverse(LinkedList<T> &list)
  {
    // 1 2 3
    Node<T>* previous = nullptr;
    Node<T>* current = list.head();
    Node<T>* next = current->next();

    while (current)
    {
      next = current->next();
      current->next() = previous;
      previous = current;
      current = next;
    }

    list.tail() = list.head();
    list.head() = previous;
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

  iterative::reverse(list);

  std::cout<<"Reversed once Linked List = " << list << std::endl;

  recursive::reverse(list);

  std::cout<<"Reversed twice Linked List = " << list << std::endl;
  return 0;
}
