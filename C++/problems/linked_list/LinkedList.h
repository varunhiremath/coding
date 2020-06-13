// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

template <typename T>
class Node
{
public:
  Node(T const& data)
    : _data(data)
    , _next(nullptr)
  {}

  T const &data() const { return _data; }
  Node<T>* &next() { return _next; }

private:
  T const _data;
  Node<T>* _next;
};

template <typename T>
class LinkedList
{
public:
  LinkedList()
    : _head(nullptr)
    , _tail(nullptr)
  {}

  Node<T>* const &head() const { return _head; }
  Node<T>* &head() { return _head; }
  Node<T>* &tail() { return _tail; }

  void insert(T const &data)
  {
    Node<T>* node = new Node<T>(data);
    if (!_head)
    {
      _head = node;
      _tail = node;
    }
    else
    {
      _tail->next() = node;
      _tail = node;
    }
  }

  friend std::ostream& operator<<(std::ostream &out, LinkedList<T> const &list)
  {
    Node<T>* current = list._head;

    while (current)
    {
      out << current->data() << " ";
      current = current->next();
    }
    return out;
  }

private:
  Node<T>* _head;
  Node<T>* _tail;
};
