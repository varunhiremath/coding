#include <iostream>

#include "BinarySearchTree.h"

template <typename T>
T
nextBiggest(BinarySearchTree<T> const &bst,
            T const &value)
{
  Node<T>* head = bst.head();
  Node<T>* parent = nullptr;
  Node<T>* node = head;
  while (node && node->data() != value)
  {
    if (value < node->data())
    {
      parent = node;
      node = node->left();
    }
    else
    {
      node = node->right();
    }
  }

  if (!node)
    throw "Error: given value not found in tree: " + std::to_string(value);

  if (node->right())
  {
    Node<T>* smallest = node->right();
    while (smallest->left())
      smallest = smallest->left();
    return smallest->data();
  }
  else
  {
    if (parent)
      return parent->data();
    else
      throw "Error: given value is the biggest in tree: " + std::to_string(value);
  }
}

int
main()
{
  BinarySearchTree<int> bst;
  std::vector<int> values{5,9,1,7,11,2,8,4,10,0,3,6};
  for (auto const& value: values)
    bst.insert(value);

  std::cout<<"Binary Search Tree = " << bst << std::endl;

  values.push_back(12);
  for (auto const& value: values)
  {
    try
    {
      int const nextBig = nextBiggest(bst, value);
      std::cout<<"Next biggest value after " << value << " is " << nextBig << std::endl;
    }
    catch(std::string const msg)
    {
      std::cerr<<msg<<std::endl;
    }
    catch(std::exception &e)
    {
      std::cerr<<e.what() << std::endl;
    }
  }

  return 0;
}
