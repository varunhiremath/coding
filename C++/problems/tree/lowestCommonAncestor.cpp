#include <iostream>

#include "BinarySearchTree.h"

template <typename T>
T
findLCA(Node<T>* const& node, T const node1, T const node2)
{
  if (node->data() >= node1 && node->data() <= node2)
    return node->data();
  else if (node->data() <= node1)
    return findLCA(node->right(), node1, node2);
  else
    return findLCA(node->left(), node1, node2);
}

template <typename T>
T
findLCAinBST(BinarySearchTree<T> const &bst,
             T const node1,
             T const node2)
{
  if (node1 < node2)
    return findLCA(bst.head(), node1, node2);
  else
    return findLCA(bst.head(), node2, node1);
}

int
main()
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(9);
  bst.insert(1);
  bst.insert(7);
  bst.insert(11);
  bst.insert(2);
  bst.insert(8);
  bst.insert(4);
  bst.insert(10);
  bst.insert(0);
  bst.insert(3);
  bst.insert(6);

  std::cout<<"Binary Search Tree = " << bst << std::endl;
  int const node1 = 0;
  int const node2 = 11;

  std::cout<<"Lowest Common Ancestor of " << node1 << " and " << node2 << " is " << findLCAinBST(bst, node1, node2) << std::endl;
}
