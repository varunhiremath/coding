// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

#include "BinaryTreeBase.h"

template <typename T>
class BalancedBinarySearchTree: public BinarySearchTree<T>
{
protected:
  void balanceNode(Node<T>* &node) override
  {
    int const imbalance = nodeHeightImbalance(node);

    if (abs(imbalance) > 1)
    {
      if (imbalance < 0)
      {
        if (nodeHeightImbalance(node->left()) > 0)
          rotateLeft(node->left());
        rotateRight(node);
      }
      else
      {
        if (nodeHeightImbalance(node->right()) < 0)
          rotateRight(node->right());
        rotateLeft(node);
      }
    }
  }

  int nodeHeightImbalance(Node<T>* const &node) const
  {
    if (!node) return 0;
    size_t const leftHeight = BinaryTreeBase<T>::height(node->left());
    size_t const rightHeight = BinaryTreeBase<T>::height(node->right());
    return rightHeight - leftHeight;
  }

  void rotateRight(Node<T>* &head)
  {
    Node<T>* node = head;
    Node<T>* left = head->left();
    Node<T>* leftRight = left->right();
    Node<T>* right = head->right();
    head = left;
    head->right() = node;
    head->right()->left() = leftRight;
  }

  void rotateLeft(Node<T>* &head)
  {
    Node<T>* node = head;
    Node<T>* left = head->left();
    Node<T>* right = head->right();
    Node<T>* rightLeft = right->left();
    head = right;
    head->left() = node;
    head->left()->right() = rightLeft;
  }

};
