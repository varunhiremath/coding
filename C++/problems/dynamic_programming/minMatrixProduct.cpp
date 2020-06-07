// Author: Varun Hiremath
// License: BSD 3-Clause

#include<iostream>
#include<vector>
#include<climits>

namespace recursive
{
  size_t
  minMatrixProductCompute(std::vector<size_t> const &dimensions,
                          size_t start, size_t end)
  {
    if (start == end)
      return 0;

    size_t minOps = INT_MAX;
    for (size_t i = start; i < end; ++i)
    {
      size_t const nOps = minMatrixProductCompute(dimensions, start, i) +
        minMatrixProductCompute(dimensions, i+1, end) +
        dimensions[start-1]*dimensions[i]*dimensions[end];

      if (nOps < minOps)
        minOps = nOps;
    }

    return minOps;
  }

  size_t
  minMatrixProduct(std::vector<size_t> const &dimensions)
  {
    return minMatrixProductCompute(dimensions, 1, dimensions.size()-1);
  }
}


namespace memoized
{
  size_t
  minMatrixProductCompute(std::vector<size_t> const &dimensions,
                          size_t start, size_t end,
                          std::vector<std::vector<size_t>> &ops)
  {
    if (start == end)
      return 0;

    if (ops[start][end] > 0)
      return ops[start][end];

    size_t minOps = INT_MAX;
    for (size_t i = start; i < end; ++i)
    {
      ops[start][end] = minMatrixProductCompute(dimensions, start, i, ops) +
        minMatrixProductCompute(dimensions, i+1, end, ops) +
        dimensions[start-1]*dimensions[i]*dimensions[end];

      if (ops[start][end] < minOps)
        minOps = ops[start][end];
    }

    return minOps;
  }

  size_t
  minMatrixProduct(std::vector<size_t> const &dimensions)
  {
    std::vector<std::vector<size_t>> ops(dimensions.size(), std::vector<size_t>(dimensions.size(), 0));
    return minMatrixProductCompute(dimensions, 1, dimensions.size()-1, ops);
  }
}

int
main()
{
  std::vector<size_t> dimensions{10, 20, 30, 40, 30};
  std::cout<<"Minimum number of computations = " << recursive::minMatrixProduct(dimensions) << std::endl;
  std::cout<<"Minimum number of computations = " << memoized::minMatrixProduct(dimensions) << std::endl;
  return 0;
}
