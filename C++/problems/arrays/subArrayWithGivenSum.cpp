// Author: Varun Hiremath
// License: BSD 3-Clause

// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

#include <iostream>
#include <vector>

// finds a sub-array with sum matching the given sum
bool
findSubArray(std::vector<unsigned int> const &array, size_t const sum,
             size_t &start, size_t &end)
{
  size_t const size = array.size();
  if (size == 0) return false;

  start = 0;
  end = 0;
  size_t lsum = array[0];
  while (lsum != sum && start < size && end < size)
  {
    if (lsum < sum)
    {
      ++end;
      lsum += array[end];
    }
    else if (lsum > sum)
    {
      lsum -= array[start];
      ++start;
    }
  }

  if (start < size && end < size)
    return true;
  else
    return false;
}


int
main()
{
  std::vector<unsigned int> array{4, 2, 3, 7, 5};
  size_t const sum = 10;
  size_t start;
  size_t end;

  bool const success = findSubArray(array, sum, start, end);
  if (success)
    std::cout<<"Found matching sub array starting " << start+1 << " and ending " << end+1 << std::endl;
  else
    std::cout<<"No sub array found!" << std::endl;

  return 0;
}
