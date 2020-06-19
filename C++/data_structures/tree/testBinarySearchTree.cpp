#include <iostream>
#include "BinarySearchTree.h"

int
main()
{
  BinarySearchTree<int> bst;
  bst.insert(25);
  bst.insert(20);
  bst.insert(36);
  bst.insert(10);
  bst.insert(22);
  bst.insert(30);
  bst.insert(40);
  bst.insert(5);
  bst.insert(12);
  bst.insert(28);
  bst.insert(38);
  bst.insert(48);
  bst.insert(1);
  bst.insert(8);
  bst.insert(15);
  bst.insert(45);
  bst.insert(50);
  bst.insert(23);
  bst.insert(11);

  std::cout<<"BST = " << bst << std::endl;

  return 0;
}
