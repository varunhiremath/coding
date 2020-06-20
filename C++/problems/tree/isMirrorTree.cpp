#include <iostream>
#include <climits>

#include "BinaryTree.h"

template <typename T>
bool
areMirrorNodes(Node<T>* const& node1,
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
    return areMirrorNodes(node1->left(), node2->right()) &&
      areMirrorNodes(node1->right(), node2->left());
  }
}

template <typename T>
bool
isMirror(BinaryTree<T> const &bt)
{
  return areMirrorNodes(bt.head()->left(), bt.head()->right());
}

int
main()
{
  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(1);
    bt.head()->left() = bt.newNode(2);
    bt.head()->right() = bt.newNode(2);
    bt.head()->left()->left() = bt.newNode(4);
    bt.head()->left()->right() = bt.newNode(6);
    bt.head()->right()->left() = bt.newNode(6);
    bt.head()->right()->right() = bt.newNode(4);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a mirror image of itself (symmetric)? = " << std::boolalpha << isMirror(bt) << std::endl;
  }

  std::cout<<std::endl;

  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(1);
    bt.head()->left() = bt.newNode(2);
    bt.head()->right() = bt.newNode(2);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a mirror image of itself (symmetric)? = " << std::boolalpha << isMirror(bt) << std::endl;
  }

  std::cout<<std::endl;

  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(2);
    bt.head()->left() = bt.newNode(1);
    bt.head()->right() = bt.newNode(3);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a mirror image of itself (symmetric)? = " << std::boolalpha << isMirror(bt) << std::endl;
  }

  std::cout<<std::endl;

  {
    BinaryTree<int> bt;
    bt.head() = bt.newNode(3);
    bt.head()->left() = bt.newNode(2);
    bt.head()->left()->right() = bt.newNode(5);
    bt.head()->right() = bt.newNode(4);

    std::cout<<"Binary Tree = " << bt << std::endl;

    std::cout<<"Is a mirror image of itself (symmetric)? = " << std::boolalpha << isMirror(bt) << std::endl;
  }

  return 0;
}
