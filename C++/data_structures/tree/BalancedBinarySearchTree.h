// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

#include "BinaryTreeBase.h"

template <typename T>
class BalancedBinarySearchTree: public BinaryTreeBase<T>
{
public:
  using BinaryTreeBase<T>::_head;

  void insert(T const &data)
  {
    Node<T>* node = new Node<T>(data);
    insertNode(node, _head);
  }

protected:
  void insertNode(Node<T>* const &node, Node<T>* &current)
  {
    if (!current)
      current = node;
    else if (node->data() < current->data())
      insertNode(node, current->left());
    else
      insertNode(node, current->right());

    balanceNode(current);
  }

  int nodeHeightImbalance(Node<T>* const &node) const
  {
    size_t const leftHeight = BinaryTreeBase<T>::height(node->left());
    size_t const rightHeight = BinaryTreeBase<T>::height(node->right());
    return rightHeight - leftHeight;
  }

  void balanceNode(Node<T>* &node)
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
