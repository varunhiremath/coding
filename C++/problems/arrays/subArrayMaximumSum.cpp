// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// Find sub array with maximum sum

#include <iostream>
#include <vector>


// Kaden's Algorithm. This function computes the start and end indices
// of subarray with maximum sum. The return values is the maximum sum.

int
findMaxSumSubArray(std::vector<int> const &array,
                   size_t &start, size_t &end)
{
  size_t const size = array.size();
  start = 0;
  end = 0;
  int maxsum = array[0];
  int sum = maxsum;
  int lstart = 0;
  for (size_t i = 1; i < size; ++i)
  {
    if (array[i] > sum + array[i])
    {
      lstart = i;
      sum = array[i];
    }
    else
    {
      sum += array[i];
    }

    if (sum > maxsum)
    {
      maxsum = sum;
      start = lstart;
      end = i;
    }
  }

  return maxsum;
}

int
main()
{
  std::vector<int> array{-2, -3, 4, -1, -2, 1, 5, -3};
  size_t start;
  size_t end;

  int const sum = findMaxSumSubArray(array, start, end);
  std::cout<<"Sub array with maximum sum of " << sum << " found starting at " << start+1 << " and ending at " << end+1 << std::endl;

  return 0;
}
