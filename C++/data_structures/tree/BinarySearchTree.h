// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

#include "BinaryTreeBase.h"

template <typename T>
class BinarySearchTree: public BinaryTreeBase<T>
{
public:
  using BinaryTreeBase<T>::_head;

  void insert(T const &data)
  {
    Node<T>* node = new Node<T>(data);
    if (!_head)
    {
      _head = node;
    }
    else
    {
      insertNode(node, _head);
    }
  }

protected:
  void insertNode(Node<T>* &node, Node<T>* &current)
  {
    if (!current)
      current = node;
    else if (node->data() < current->data())
      insertNode(node, current->left());
    else
      insertNode(node, current->right());
  }
};
