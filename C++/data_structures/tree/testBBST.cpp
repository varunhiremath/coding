#include <iostream>
#include "BinarySearchTree.h"
#include "BalancedBinarySearchTree.h"

int
main()
{
  {
    std::vector<int> const data{4,1,0,2,3,5,6,7,8};
    BinarySearchTree<int> bst;
    BalancedBinarySearchTree<int> bbst;

    for (auto const& d : data)
    {
      bst.insert(d);
      bbst.insert(d);
    }

    std::cout<<"BST = " << bst << std::endl;
    std::cout<<"Balanced BST = " << bbst << std::endl;

    std::vector<int> const remove{5,7};
    for (auto const& d : remove)
    {
      std::cout<<"Removing node "<< d <<std::endl;
      bst.erase(d);
      bbst.erase(d);
    }
    std::cout<<std::endl;

    std::cout<<"BST = " << bst << std::endl;
    std::cout<<"Balanced BST = " << bbst << std::endl;
  }

  std::cout<<std::string(100,'-')<<std::endl;

  {
    std::vector<int> const data{5,1,2,3,4,7,6,8,9};
    BinarySearchTree<int> bst;
    BalancedBinarySearchTree<int> bbst;

    for (auto const& d : data)
    {
      bst.insert(d);
      bbst.insert(d);
    }

    std::cout<<"BST = " << bst << std::endl;
    std::cout<<"Balanced BST = " << bbst << std::endl;

    std::vector<int> const remove{1,2};
    for (auto const& d : remove)
    {
      std::cout<<"Removing node "<< d <<std::endl;
      bst.erase(d);
      bbst.erase(d);
    }
    std::cout<<std::endl;

    std::cout<<"BST = " << bst << std::endl;
    std::cout<<"Balanced BST = " << bbst << std::endl;
  }

  return 0;
}
