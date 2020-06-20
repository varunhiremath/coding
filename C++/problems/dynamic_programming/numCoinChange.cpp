// Author: Varun Hiremath
// License: BSD 3-Clause

#include <iostream>
#include <vector>

namespace recursive
{
  size_t
  numCoinChangeCompute(size_t const amount,
                       std::vector<size_t> const &coins,
                       size_t i)
  {
    if (amount == 0)
      return 1;

    if (i >= coins.size())
      return 0;

    if (coins[i] <= amount)
    {
      return numCoinChangeCompute(amount-coins[i], coins, i) + numCoinChangeCompute(amount, coins, i+1);
    }
    else
    {
      return numCoinChangeCompute(amount, coins, i+1);
    }
  }


  size_t
  numCoinChange(size_t const amount,
                std::vector<size_t> const &coins)
  {
    return numCoinChangeCompute(amount, coins, 0);
  }
}

namespace tabulated
{
  size_t
  numCoinChangeCompute(size_t const amount,
                       std::vector<size_t> const &coins,
                       std::vector<size_t> &ways)
  {
    ways[0] = 1;

    for (size_t i = 0; i < coins.size(); ++i)
    {
      for (size_t m = coins[i]; m <= amount; ++m)
      {
        ways[m] += ways[m - coins[i]];
      }
    }

    return ways[amount];
  }


  size_t
  numCoinChange(size_t const amount,
                std::vector<size_t> const &coins)
  {
    std::vector<size_t> ways(amount+1,0);
    return numCoinChangeCompute(amount, coins, ways);
  }
}

int
main()
{
  std::vector<size_t> const coins{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}; //{2, 5, 3, 6};
  size_t const amount = 43;
  std::cout<<"Number of ways to make change (recursive) = " << recursive::numCoinChange(amount, coins) << std::endl;
  std::cout<<"Number of ways to make change (tabulated) = " << tabulated::numCoinChange(amount, coins) << std::endl;
}
