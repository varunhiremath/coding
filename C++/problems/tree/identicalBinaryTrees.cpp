#include <iostream>
#include <climits>

#include "BinaryTree.h"

template <typename T>
bool
areNodesIdentical(Node<T>* const& node1,
                  Node<T>* const& node2)
{
  if (!node1 && !node2)
    return true;
  else if (!node1 || !node2)
    return false;
  else if (node1->data() != node2->data())
    return false;
  else
  {
    return areNodesIdentical(node1->left(), node2->left()) &&
      areNodesIdentical(node1->right(), node2->right());
  }
}

template <typename T>
bool
areIdentical(BinaryTree<T> const &bt1,
             BinaryTree<T> const &bt2)
{
  return areNodesIdentical(bt1.head(), bt2.head());
}

int
main()
{
  {
    BinaryTree<int> bt1;
    bt1.head() = bt1.newNode(1);
    bt1.head()->left() = bt1.newNode(2);
    bt1.head()->right() = bt1.newNode(3);
    bt1.head()->right()->left() = bt1.newNode(4);
    bt1.head()->right()->right() = bt1.newNode(6);
    bt1.head()->right()->left()->right() = bt1.newNode(5);
    bt1.head()->right()->left()->right()->left() = bt1.newNode(7);

    std::cout<<"Binary Tree 1 = " << bt1 << std::endl;

    BinaryTree<int> bt2;
    bt2.head() = bt2.newNode(1);
    bt2.head()->left() = bt2.newNode(2);
    bt2.head()->right() = bt2.newNode(3);
    bt2.head()->right()->left() = bt2.newNode(4);
    //bt2.head()->right()->right() = bt2.newNode(6);
    bt2.head()->right()->left()->right() = bt2.newNode(5);
    bt2.head()->right()->left()->right()->left() = bt2.newNode(7);

    std::cout<<"Binary Tree 2 = " << bt2 << std::endl;

    std::cout<<"Are identical? = " << std::boolalpha << areIdentical(bt1, bt2) << std::endl;
  }

  return 0;
}
