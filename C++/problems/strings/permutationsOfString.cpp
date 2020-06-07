// https://practice.geeksforgeeks.org/problems/count-the-triplets/0
#include<iostream>
#include<string>

// permutations of a string
// print leaves of the permutation tree
void
permutationsOfString(std::string &name, int i, int j)
{
  if (i == j)
    std::cout<<name<<std::endl;

  for (size_t k = i; k <= j; ++k)
  {
    std::swap(name[i], name[k]);
    permutationsOfString(name, i+1, j);
    std::swap(name[i], name[k]);
  }
}


int
main()
{
  std::string name("ABC");
  permutationsOfString(name, 0, name.size()-1);
  return 0;
}
