#include <iostream>
#include <climits>

#include "BinaryTree.h"

template <typename T>
bool
isNodeInBST(Node<T>* const& node, T const min, T const max)
{
  if (!node)
    return true;
  else if (node->data() <= min || node->data() >= max)
    return false;
  else
  {
    return isNodeInBST(node->left(), min, node->data()) &&
      isNodeInBST(node->right(), node->data(), max);
  }
}

template <typename T>
bool
isBST(BinaryTree<T> const &bt)
{
  return isNodeInBST(bt.head(), INT_MIN, INT_MAX);
}

int
main()
{
  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(1);
    bt.head()->left() = bt.newNode(2);
    bt.head()->right() = bt.newNode(3);
    bt.head()->right()->left() = bt.newNode(4);
    bt.head()->right()->right() = bt.newNode(6);
    bt.head()->right()->left()->right() = bt.newNode(5);
    bt.head()->right()->left()->right()->left() = bt.newNode(7);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a BST? = " << std::boolalpha << isBST(bt) << std::endl;
  }

  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(1);
    bt.head()->left() = bt.newNode(2);
    bt.head()->right() = bt.newNode(3);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a BST? = " << std::boolalpha << isBST(bt) << std::endl;
  }

  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(2);
    bt.head()->left() = bt.newNode(1);
    bt.head()->right() = bt.newNode(3);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a BST? = " << std::boolalpha << isBST(bt) << std::endl;
  }

  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(3);
    bt.head()->left() = bt.newNode(2);
    bt.head()->left()->right() = bt.newNode(5);
    bt.head()->right() = bt.newNode(4);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a BST? = " << std::boolalpha << isBST(bt) << std::endl;
  }



  return 0;
}
