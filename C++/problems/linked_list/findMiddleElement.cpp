// Author: Varun Hiremath
// License: BSD 3-Clause

#include <iostream>
#include <vector>

#include "LinkedList.h"

template <typename T>
T
findMiddleElement(LinkedList<T> const& list)
{
  auto current = list.head();
  auto middle = current;

  while (current && current->next())
  {
    current = current->next()->next();
    middle = middle->next();
  }

  return middle->data();
}

int
main()
{
  std::vector<int> const data{1,2,3,4,5};
  LinkedList<int> list;
  for (auto const& i : data)
    list.insert(i);

  std::cout<<"Linked List = " << list << std::endl;
  std::cout<<"The middle element in the list = " << findMiddleElement(list) << std::endl;
  return 0;
}
