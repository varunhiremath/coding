// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

#include "BinaryTreeBase.h"

template <typename T>
class BinaryTree : public BinaryTreeBase<T>
{
public:
  using BinaryTreeBase<T>::_head;

  Node<T>* &head() { return _head; }
  Node<T>* const &head() const { return _head; }

  Node<T>* newNode(T const data)
  {
    Node<T>* node = new Node<T>(data);
    return node;
  }
};
