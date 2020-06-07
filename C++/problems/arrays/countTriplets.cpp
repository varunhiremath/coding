https://practice.geeksforgeeks.org/problems/count-the-triplets/0

#include <iostream>
#include <vector>
#include <algorithm>

// function counts all triplets a+b=c found in the given array
int
countTriplets(std::vector<int> const &array)
{
  size_t count = 0;
  size_t const size = array.size();
  std::vector<int> sorted_array(array);
  std::sort(sorted_array.begin(), sorted_array.end());

  for (size_t i = size-1; i >= 2; --i)
  {
    int const sum = sorted_array[i];
    int left = 0;
    int right = i-1;
    while (left < right)
    {
      int const sum = sorted_array[left] + sorted_array[right];
      if (sum == sorted_array[i])
      {
        ++count;
        ++left;
      }
      else if (sum < sorted_array[i])
        ++left;
      else
        --right;
    }
  }
  return count;
}

int
main()
{
  std::vector<int> array{1,5,3,2};
  size_t const triplets = countTriplets(array);
  std::cout<<"No. of triplets found = " << triplets << std::endl;

  return 0;
}
