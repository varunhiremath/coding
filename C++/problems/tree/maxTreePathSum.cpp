#include <iostream>

#include "BinaryTree.h"
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
maxTreePathSumNode(Node<T>* const &node, std::vector<T> &path)
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
    T const data = node->data();
    std::vector<T> leftRootPath, rightRootPath;
    T const leftRoot = maxRootPathSumNode(node->left(), leftRootPath);
    T const rightRoot = maxRootPathSumNode(node->right(), rightRootPath);
    std::vector<T> leftTreePath, rightTreePath;
    T const leftTree = maxTreePathSumNode(node->left(), leftTreePath);
    T const rightTree = maxTreePathSumNode(node->right(), rightTreePath);

    std::vector<T> const paths{data, leftTree, rightTree, leftRoot + data, data + rightRoot, leftRoot + data + rightRoot};
    auto const &it = std::max_element(paths.begin(), paths.end());
    auto const index = std::distance(paths.begin(), it);

    switch (index)
    {
    case 0:
      path.clear();
      path.push_back(data);
      break;
    case 1:
      path = leftTreePath;
      break;
    case 2:
      path = rightTreePath;
      break;
    case 3:
      path = leftRootPath;
      path.push_back(data);
      break;
    case 4:
      path = rightRootPath;
      path.push_back(data);
      break;
    case 5:
      path = leftRootPath;
      path.push_back(data);
      std::reverse(rightRootPath.begin(), rightRootPath.end());
      path.insert(path.end(), rightRootPath.begin(), rightRootPath.end());
      break;
    }
    return paths[index];
  }
}

template <typename T>
T
maxTreePathSum(BinaryTreeBase<T> const &bt, std::vector<T> &path)
{
  Node<T>* head = bt.head();
  T const maxsum = maxTreePathSumNode(head, path);
  return maxsum;
}

int
main()
{
  {
    BinarySearchTree<int> bst;
    std::vector<int> values{9,1,5,7,11,2,8,4,10,0,3,6};
    for (auto const& value: values)
      bst.insert(value);

    std::cout<<"Binary Search Tree = " << bst << std::endl;

    std::vector<int> path;
    std::cout<<"Maximum tree path value = " << maxTreePathSum(bst, path) << " using path [";
    std::string separator = "";
    for (auto const& p : path)
    {
      std::cout<<separator<<p;
      separator = " => ";
    }
    std::cout<<"]"<<std::endl;
  }
  std::cout<<std::string(50,'-')<<std::endl;
  {
    BinaryTree<int> bt;

    bt.head() = bt.newNode(10);
    bt.head()->left() = bt.newNode(2);
    bt.head()->right() = bt.newNode(10);
    bt.head()->left()->left() = bt.newNode(20);
    bt.head()->left()->right() = bt.newNode(1);
    bt.head()->right()->right() = bt.newNode(-25);
    bt.head()->right()->right()->left() = bt.newNode(3);
    bt.head()->right()->right()->right() = bt.newNode(4);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::vector<int> path;
    std::cout<<"Maximum tree path value = " << maxTreePathSum(bt, path) << " using path [";
    std::string separator = "";
    for (auto const& p : path)
    {
      std::cout<<separator<<p;
      separator = " => ";
    }
    std::cout<<"]"<<std::endl;
  }
  std::cout<<std::string(50,'-')<<std::endl;
  {
    BinaryTree<int> bt;

    bt.head() = bt.newNode(-10);
    bt.head()->left() = bt.newNode(9);
    bt.head()->right() = bt.newNode(20);
    bt.head()->right()->right() = bt.newNode(7);
    bt.head()->right()->left() = bt.newNode(15);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::vector<int> path;
    std::cout<<"Maximum tree path value = " << maxTreePathSum(bt, path) << " using path [";
    std::string separator = "";
    for (auto const& p : path)
    {
      std::cout<<separator<<p;
      separator = " => ";
    }
    std::cout<<"]"<<std::endl;
  }


  return 0;
}
