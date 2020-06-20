// Author: Varun Hiremath
// License: BSD 3-Clause

#pragma once

#include <vector>
#include <iomanip>
#include <cmath>

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

  void prettyPrintTree(std::vector<Node<T>*> const &nodes,
                       size_t const level, size_t const height, size_t const numwidth) const
  {
    if (level == height)
      return;

    size_t bumpUp = 0;
    int innerBranchSpace = 0;
    do
    {
      ++bumpUp;
      size_t const leadingSpace = (1 << bumpUp);
      size_t const midSpace = 2*leadingSpace - 1;
      innerBranchSpace = midSpace - (2*(numwidth-1));
    }
    while (innerBranchSpace < 1);

    int spacingLevel = level - (bumpUp - 1);
    size_t const indentSpace = 1;
    size_t const leadingSpace = (1 << (height - spacingLevel));
    size_t const midSpace = 2*leadingSpace - 1;
    size_t const branchSpace = midSpace - (2*(numwidth-1));

    std::cout<<std::endl<<std::string(indentSpace+leadingSpace-numwidth, ' ');

    std::vector<Node<T>*> nextNodes;
    bool leftNode = true;

    std::string blankSpace = "";
    for (auto const& node : nodes)
    {
      std::cout<<blankSpace;
      if (node)
      {
        auto align = leftNode? std::right : std::left;
        std::cout<<align<<std::setw(numwidth)<<node->data();

        nextNodes.push_back(node->left());
        nextNodes.push_back(node->right());
      }
      else
      {
        std::cout<<std::string(numwidth,' ');
        nextNodes.push_back(nullptr);
        nextNodes.push_back(nullptr);
      }

      blankSpace = leftNode? std::string(midSpace, ' ') : std::string(branchSpace, ' ');
      leftNode = !leftNode;
    }

    if (level+1 == height)
    {
      std::cout<<std::endl;
      return;
    }

    size_t const nextLevel = level+1;
    int const nextSpacingLevel = spacingLevel + 1;
    size_t const nextLeadingSpace = 1 << (height - nextSpacingLevel);
    size_t nextMidSpace = 2*nextLeadingSpace-1;

    std::cout<<std::endl<<std::string(indentSpace+nextLeadingSpace, ' ');

    blankSpace = "";
    for (size_t k = 0; k < (1 << nextLevel); k += 2)
    {
      std::cout<<blankSpace;
      if (nextNodes[k] && nextNodes[k+1])
      {
        std::cout<<" ";
        std::cout<<std::string(nextMidSpace/2-1, '_');
        std::cout<<"|";
        std::cout<<std::string(nextMidSpace/2-1, '_');
        std::cout<<" ";
      }
      else if (nextNodes[k])
      {
        std::cout<<" ";
        std::cout<<std::string(nextMidSpace/2-1, '_');
        std::cout<<"|";
        std::cout<<std::string(nextMidSpace/2-1, ' ');
        std::cout<<" ";
      }
      else if (nextNodes[k+1])
      {
        std::cout<<" ";
        std::cout<<std::string(nextMidSpace/2-1, ' ');
        std::cout<<"|";
        std::cout<<std::string(nextMidSpace/2-1, '_');
        std::cout<<" ";
      }
      else
      {
        std::cout<<std::string(nextMidSpace, ' ');
      }

      blankSpace = std::string(nextMidSpace+2, ' ');
    }

    std::cout<<std::endl<<std::string(indentSpace+nextLeadingSpace, ' ');

    leftNode = true;
    blankSpace = "";
    for (auto const& node : nextNodes)
    {
      std::cout<<blankSpace;

      std::string const slash = (leftNode)? "/":"\\";
      if (node)
        std::cout<<slash;
      else
        std::cout<<" ";

      blankSpace = leftNode? std::string(nextMidSpace-2, ' ') : std::string(nextMidSpace+2, ' ');
      leftNode = !leftNode;
    }

    prettyPrintTree(nextNodes, level+1, height, numwidth);
  }

  friend std::ostream &operator<<(std::ostream &out, BinaryTreeBase<T> const &bt)
  {
    size_t const height = bt.height(bt._head);
    T const maxVal = bt.max(bt._head);
    size_t const digits = std::min(4, 1 + static_cast<int>(std::floor(std::log10(maxVal))));
    std::vector<Node<T>*> nodes{bt._head};
    bt.prettyPrintTree(nodes, 0, height, digits);
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

  T const max(Node<T>* const &head) const
  {
    if (!head) return 0;
    Node<T>* node = head;
    while (node->right())
    {
      node = node->right();
    }
    return node->data();
  }

  Node<T>* _head;
};
