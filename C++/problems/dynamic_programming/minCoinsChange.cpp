// Author: Varun Hiremath
// Date: Sun, 7 Jun 2020
// License: BSD 3-Clause

#include<iostream>
#include<vector>
#include<climits>

namespace recursive
{
  size_t
  minCoinsChangeCompute(size_t const amount,
                        std::vector<size_t> const &coins,
                        size_t i)
  {
    if (amount == 0)
      return 0;

    if (i >= coins.size())
      return INT_MAX;

    if (coins[i] <= amount)
    {
      return std::min(1 + minCoinsChangeCompute(amount-coins[i], coins, i), minCoinsChangeCompute(amount, coins, i+1));
    }
    else
    {
      return minCoinsChangeCompute(amount, coins, i+1);
    }
  }


  size_t
  minCoinsChange(size_t const amount,
                 std::vector<size_t> const &coins)
  {
    return minCoinsChangeCompute(amount, coins, 0);
  }
}

namespace memoized
{
  size_t
  minCoinsChangeCompute(size_t const amount,
                        std::vector<size_t> const &coins,
                        size_t i,
                        std::vector<std::vector<size_t>> &minCoins)
  {
    if (amount == 0)
      return 0;

    if (i >= coins.size())
      return INT_MAX;

    if (minCoins[amount][i] > 0)
    {
      return minCoins[amount][i];
    }

    if (coins[i] <= amount)
    {
      minCoins[amount][i] = std::min(1 + minCoinsChangeCompute(amount-coins[i], coins, i, minCoins), minCoinsChangeCompute(amount, coins, i+1, minCoins));
      return minCoins[amount][i];
    }
    else
    {
      minCoins[amount][i] = minCoinsChangeCompute(amount, coins, i+1, minCoins);
      return minCoins[amount][i];
    }
  }


  size_t
  minCoinsChange(size_t const amount,
                 std::vector<size_t> const &coins)
  {
    std::vector<std::vector<size_t>> minCoins(amount+1, std::vector<size_t>(coins.size(), 0));
    return minCoinsChangeCompute(amount, coins, 0, minCoins);
  }
}


namespace tabulated
{
  void
  minCoinsChangeTabulated(size_t const amount,
                          std::vector<size_t> const &coins,
                          std::vector<size_t> &minCoins,
                          std::vector<size_t> &chosenCoin)
  {
    minCoins[0] = 0;
    chosenCoin[0] = 0;

    for (size_t money = 1; money <= amount; ++money)
    {
      for (size_t i = 0; i < coins.size(); ++i)
      {
        if (coins[i] <= money)
        {
          size_t const min = 1 + minCoins[money-coins[i]];
          if (min < minCoins[money])
          {
            chosenCoin[money] = coins[i];
            minCoins[money] = min;
          }
        }
      }
    }
  }


  size_t
  minCoinsChange(size_t const amount,
                 std::vector<size_t> const &coins)
  {
    std::vector<size_t> minCoins(amount+1, amount);
    std::vector<size_t> chosenCoin(amount+1);
    minCoinsChangeTabulated(amount, coins, minCoins, chosenCoin);

    std::cout<<"Use Coins [ ";
    size_t money = amount;
    while (money)
    {
      size_t const coin = chosenCoin[money];
      std::cout<<coin<<" ";
      money -= coin;
    }
    std::cout<<"] to make amount = " << amount << std::endl;
    return minCoins[amount];
  }
}

int
main()
{
  std::vector<size_t> const coins{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
  size_t const amount = 43;
  size_t const minCoins = tabulated::minCoinsChange(amount, coins);
  std::cout<<"Minimum number of coins needed = " << minCoins << std::endl;
}
