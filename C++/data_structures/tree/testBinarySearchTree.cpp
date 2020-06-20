#include <iostream>
#include "BinarySearchTree.h"

int
main()
{
  BinarySearchTree<int> bst;
  bst.insert(250);
  bst.insert(200);
  bst.insert(360);
  bst.insert(100);
  bst.insert(220);
  bst.insert(300);
  bst.insert(400);
  bst.insert(50);
  bst.insert(120);
  bst.insert(280);
  bst.insert(380);
  bst.insert(480);
  bst.insert(10);
  bst.insert(80);
  bst.insert(150);
  bst.insert(450);
  bst.insert(500);
  bst.insert(230);

  std::cout<<"BST = " << bst << std::endl;

  return 0;
}
