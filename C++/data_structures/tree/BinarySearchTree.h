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
    insertNode(node, _head);
  }

  void erase(T const &data)
  {
    eraseNode(_head, data);
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

  void eraseNode(Node<T>* &node, T const &data)
  {
    if (!node)
      return;
    else if (node->data() == data)
    {
      if (!node->right())
      {
        Node<T>* tmp = node;
        node = node->left();
        delete tmp;
      }
      else
      {
        node->data() = extractMinNode(node->right());
      }
    }
    else
    {
      if (data < node->data())
        eraseNode(node->left(), data);
      else
        eraseNode(node->right(), data);
    }

    balanceNode(node);
  }

  T const extractMinNode(Node<T>* &node)
  {
    if (!node->left())
    {
      T const min = node->data();
      Node<T>* tmp = node;
      if (node->right())
        node = node->right();
      else
        node = nullptr;
      delete tmp;
      return min;
    }
    else
    {
      return extractMinNode(node->left());
    }
  }

  virtual void balanceNode(Node<T>* &node) {}
};
