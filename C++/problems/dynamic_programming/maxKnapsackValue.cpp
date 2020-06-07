// Author: Varun Hiremath
// License: BSD 3-Clause

#include<iostream>
#include<vector>

namespace recursive
{
  size_t
  maxKnapsackValueHelper(size_t const capacity,
                         std::vector<size_t> const &weights,
                         std::vector<size_t> const &values,
                         size_t const i)
  {
    if (i >= weights.size())
      return 0;

    if (weights[i] <= capacity)
    {
      return std::max(values[i] + maxKnapsackValueHelper(capacity - weights[i], weights, values, i+1),
                      maxKnapsackValueHelper(capacity, weights, values, i+1));
    }
    else
    {
      return maxKnapsackValueHelper(capacity, weights, values, i+1);
    }
  }

  size_t
  maxKnapsackValue(size_t const capacity,
                   std::vector<size_t> const &weights,
                   std::vector<size_t> const &values)
  {
    return maxKnapsackValueHelper(capacity, weights, values, 0);
  }
};

namespace memoized
{
  size_t
  maxKnapsackValueHelper(size_t const capacity,
                         std::vector<size_t> const &weights,
                         std::vector<size_t> const &values,
                         size_t const i,
                         std::vector<std::vector<int>> &maxValue)
  {
    if (i >= weights.size())
      return 0;

    if (maxValue[capacity][i] != -1)
      return maxValue[capacity][i];

    if (weights[i] <= capacity)
    {
      maxValue[capacity][i] = std::max(values[i] + maxKnapsackValueHelper(capacity - weights[i], weights, values, i+1, maxValue),
                                       maxKnapsackValueHelper(capacity, weights, values, i+1, maxValue));
      return maxValue[capacity][i];
    }
    else
    {
      maxValue[capacity][i] =  maxKnapsackValueHelper(capacity, weights, values, i+1, maxValue);
      return maxValue[capacity][i];
    }
  }

  int
  maxKnapsackValue(size_t const capacity,
                   std::vector<size_t> const &weights,
                   std::vector<size_t> const &values)
  {
    std::vector<std::vector<int>> maxValue(capacity+1, std::vector<int>(weights.size(), -1));
    return maxKnapsackValueHelper(capacity, weights, values, 0, maxValue);
  }
}

int
main()
{
  std::vector<size_t> weights{4,5,1};
  std::vector<size_t> values{1,2,3};
  size_t const capacity = 4;

  std::cout<<"Max Knapsack Value = " << recursive::maxKnapsackValue(capacity, weights, values) << std::endl;
  std::cout<<"Max Knapsack Value = " << memoized::maxKnapsackValue(capacity, weights, values) << std::endl;
}
