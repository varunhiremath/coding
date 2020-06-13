// Author: Varun Hiremath
// License: BSD 3-Clause

#include <iostream>
#include <vector>

#include "LinkedList.h"

namespace recursive
{
  template <typename T>
  bool
  isPalindrome(Node<T>* &start, Node<T>* &end, bool &result, bool &done)
  {
    if (!end) return false;
    isPalindrome(start, end->next(), result, done);

    if (done || !result)
      return result;

    if (start->data() != end->data())
    {
      result = false;
      return result;
    }
    else
    {
      if (start == end || start->next() == end)
        done = true;
      start = start->next();
    }
    return result;
  }

  template <typename T>
  bool
  isPalindrome(LinkedList<T> &list)
  {
    bool result = true;
    bool done = false;
    auto head = list.head();
    isPalindrome(head, head, result, done);
    return result;
  }
}


int
main()
{
  std::vector<int> const data{1,2,0,1, 2,1};
  LinkedList<int> list;
  for (auto const& i : data)
    list.insert(i);

  std::cout<<"Linked List = " << list << std::endl;

  std::cout<<"Is the linked list a palindrome = " << std::boolalpha << recursive::isPalindrome(list) << std::endl;
}
