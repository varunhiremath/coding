#include <iostream>

#include "BinarySearchTree.h"
#include <algorithm>

template <typename T>
T
maxRootPathSumNode(Node<T>* const &node, std::vector<T> &path)
{
  if (!node)
    return T(0);
  else if (!node->left() && !node->right())
  {
    path.push_back(node->data());
    return node->data();
  }
  else
  {
    std::vector<T> path_left, path_right;
    T const left = maxRootPathSumNode(node->left(), path_left);
    T const right = maxRootPathSumNode(node->right(), path_right);
    if (left > right)
      path = path_left;
    else
      path = path_right;

    path.push_back(node->data());
    return node->data() + std::max(left, right);
  }
}

template <typename T>
T
maxRootPathSum(BinarySearchTree<T> const &bst, std::vector<T> &path)
{
  Node<T>* head = bst.head();
  T const maxsum = maxRootPathSumNode(head, path);
  std::reverse(path.begin(), path.end());
  return maxsum;
}

int
main()
{
  BinarySearchTree<int> bst;
  std::vector<int> values{9,1,5,7,11,2,8,4,10,0,3,6};
  for (auto const& value: values)
    bst.insert(value);

  std::cout<<"Binary Search Tree = " << bst << std::endl;

  std::vector<int> path;
  std::cout<<"Maximum root path value = " << maxRootPathSum(bst, path) << " using path [";
  std::string separator = "";
  for (auto const& p : path)
  {
    std::cout<<separator<<p;
    separator = " => ";
  }
  std::cout<<"]"<<std::endl;
  return 0;
}
