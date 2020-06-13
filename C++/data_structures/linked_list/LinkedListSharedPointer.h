// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

#include <memory>

template <typename T>
class Node
{
public:
  Node(T const& data)
    : _data(data)
    , _next(nullptr)
  {}

  T const& data() const { return _data; }
  std::shared_ptr<Node<T>> &next() { return _next; }

private:
  T const _data;
  std::shared_ptr<Node<T>> _next;
};


template <typename T>
class LinkedList
{
public:
  LinkedList()
    : _head(nullptr)
    , _tail(nullptr)
  {}

  void insert(T const& data)
  {
    std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(data);
    if (!_head)
    {
      _head = node;
      _tail = _head;
    }
    else
    {
      _tail->next() = node;
      _tail = node;
    }
  }

  friend std::ostream& operator<<(std::ostream &out, LinkedList<T> const &list)
  {
    auto node = list._head;
    while (node)
    {
      out << node->data() <<" ";
      node = node->next();
    }
    return out;
  }

private:
  std::shared_ptr<Node<T>> _head;
  std::shared_ptr<Node<T>> _tail;
};
