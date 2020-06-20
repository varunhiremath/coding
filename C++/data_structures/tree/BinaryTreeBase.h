// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

#include <vector>
#include <iomanip>

template <typename T>
class Node
{
public:
  Node(T const &data)
    : _data(data)
    , _left(nullptr)
    , _right(nullptr)
  {}

  T const &data() const { return _data; }
  Node<T>* &left() { return _left; }
  Node<T>* &right() { return _right; }

private:
  T const _data;
  Node<T>* _left;
  Node<T>* _right;
};

template <typename T>
class BinaryTreeBase
{
public:
  BinaryTreeBase()
    : _head(nullptr)
  {}

  Node<T>* const &head() const { return _head; }

  void printInOrder(Node<T>* const &node,
                    std::ostream &out) const
  {
    if (!node) return;
    printLeftView(node->left(), out);
    out<<node->data()<<" ";
    printLeftView(node->right(), out);
  }

  void prettyPrintTree(std::vector<Node<T>*> const &nodes, size_t const level, size_t const height, size_t const numwidth) const
  {
    if (level == height)
      return;

    size_t const indentSpace = 10;
    size_t const leadingSpace = 1 << (height - level);
    size_t const midSpace = 2*leadingSpace - 1;
    size_t const branchSpace = midSpace - (2*(numwidth-1));

    std::cout<<std::endl<<std::string(indentSpace+leadingSpace-numwidth, ' ');

    std::vector<Node<T>*> nextNodes;
    bool leftSide = true;
    for (auto const& node : nodes)
    {
      if (node)
      {
        if (leftSide)
          std::cout<<std::right<<std::setw(numwidth)<<node->data();
        else
          std::cout<<std::left<<std::setw(numwidth)<<node->data();

        nextNodes.push_back(node->left());
        nextNodes.push_back(node->right());
      }
      else
      {
        std::cout<<std::string(numwidth,' ');
        nextNodes.push_back(nullptr);
        nextNodes.push_back(nullptr);
      }

      if (leftSide)
        std::cout<<std::string(midSpace, ' ');
      else
        std::cout<<std::string(branchSpace, ' ');

      leftSide = !leftSide;
    }

    if (level+1 == height)
    {
      std::cout<<std::endl;
      return;
    }

    std::cout<<std::endl<<std::string(indentSpace+leadingSpace-numwidth, ' ');
    leftSide = true;
    for (auto const& node : nodes)
    {
      if (node && (node->left() || node->right()))
      {
        if (leftSide)
          std::cout<<std::right<<std::setw(numwidth)<<"|";
        else
          std::cout<<std::left<<std::setw(numwidth)<<"|";
      }
      else
      {
        std::cout<<std::string(numwidth,' ');
      }

      if (leftSide)
        std::cout<<std::string(midSpace, ' ');
      else
        std::cout<<std::string(branchSpace, ' ');

      leftSide = !leftSide;
    }

    size_t const nextLevel = level+1;
    size_t const nextLeadingSpace = 1 << (height - nextLevel);
    size_t nextMidSpace = 2*nextLeadingSpace-1;

    std::cout<<std::endl<<std::string(indentSpace+nextLeadingSpace, ' ');

    for (size_t k = 0; k < (1 << nextLevel); k += 2)
    {
      if (nextNodes[k] && nextNodes[k+1])
      {
        std::cout<<" ";
        std::cout<<std::string(nextMidSpace-2, '-');
        std::cout<<" ";
      }
      else if (nextNodes[k])
      {
        std::cout<<" ";
        std::cout<<std::string(nextMidSpace/2, '-');
        std::cout<<std::string(nextMidSpace/2-1, ' ');
        std::cout<<" ";
      }
      else if (nextNodes[k+1])
      {
        std::cout<<" ";
        std::cout<<std::string(nextMidSpace/2-1, ' ');
        std::cout<<std::string(nextMidSpace/2, '-');
        std::cout<<" ";
      }
      else
      {
        std::cout<<std::string(nextMidSpace, ' ');
      }

      std::cout<<std::string(nextMidSpace+2, ' ');
    }

    std::cout<<std::endl<<std::string(indentSpace+nextLeadingSpace, ' ');

    leftSide = true;
    for (auto const& node : nextNodes)
    {
      std::string const line = (leftSide)? "/":"\\";
      if (node)
      {
        std::cout<<line;
      }
      else
      {
        std::cout<<" ";
      }

      if (leftSide)
        std::cout<<std::string(nextMidSpace-2, ' ');
      else
        std::cout<<std::string(nextMidSpace+2, ' ');
      leftSide = !leftSide;
    }

    prettyPrintTree(nextNodes, level+1, height, numwidth);
  }

  friend std::ostream &operator<<(std::ostream &out, BinaryTreeBase<T> const &bt)
  {
    size_t const height = bt.height(bt._head);
    std::vector<Node<T>*> nodes{bt._head};
    bt.prettyPrintTree(nodes, 0, height, 2);
    return out;
  }

protected:
  size_t const height(Node<T>* const &node) const
  {
    if (!node)
      return 0;
    else
      return 1 + std::max(height(node->left()), height(node->right()));
  }

  Node<T>* _head;
};
