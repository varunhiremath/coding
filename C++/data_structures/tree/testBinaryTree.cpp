#include <iostream>
#include "BinaryTree.h"

int
main()
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

  return 0;
}
