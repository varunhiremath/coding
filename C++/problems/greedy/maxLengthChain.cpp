#include<iostream>
#include<vector>
#include<algorithm>

bool
compare(std::pair<int,int> const& a, std::pair<int,int> const& b)
{
  return a.second < b.second;
}

int
maxLengthChain(std::vector<std::pair<int,int>> &pairs)
{
  std::sort(pairs.begin(), pairs.end(), compare);
  int maxLength = 1;
  int chainEnd = pairs[0].second;
  std::cout<<"Max Chain: " << pairs[0].first << " " << pairs[0].second << " ";
  for (size_t i = 0; i < pairs.size(); ++i)
  {
    if (pairs[i].first > chainEnd)
    {
      ++maxLength;
      chainEnd = pairs[i].second;
      std::cout << pairs[i].first << " " << pairs[i].second << " ";
    }
  }
  std::cout<<std::endl;
  std::cout<<"Length of Max Chain = " << maxLength << std::endl;
  return maxLength;
}

int
main()
{
  std::vector<int> nums = {594,858,313,628,215,887,356,513,91,413,480,611,190,970,275,356,621,642,434,988,339,889,567,771,285,857,418,607,261,850,206,238,60,218,519,946,784,874,459,874,290,638,484,608,479,758,315,472,101,730,460,619,26,439,75,389,158,234,494,682,271,359,418,700};
  std::vector<std::pair<int,int>> pairs;

  for (size_t i = 0; i < nums.size(); i+=2)
  {
    pairs.emplace_back(nums[i], nums[i+1]);
  }

  maxLengthChain(pairs);
}
