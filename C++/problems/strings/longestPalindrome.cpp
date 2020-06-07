#include<iostream>
#include<string>
#include<vector>

bool
isPalindrome(std::string const &word)
{
  size_t const size = word.size();

  for (size_t i = 0; i < size/2; ++i)
  {
    if (word[i] != word[size-1-i])
      return false;
  }
  return true;
}


void
longestPalindromeDP(std::string word)
{
  size_t const size = word.size();
  std::vector<std::vector<bool>> isPalindrome(size, std::vector<bool>(size, false));

  size_t maxPalindromeSize = 1;
  size_t startIndex = 0;

  for (size_t i = 0; i < size; ++i)
    isPalindrome[i][i] = true;

  for (size_t i = 0; i < size-1; ++i)
  {
    if (word[i] == word[i+1])
    {
      isPalindrome[i][i+1] = true;
      if (maxPalindromeSize < 2)
      {
        maxPalindromeSize = 2;
        startIndex = i;
      }
    }
  }

  for (size_t len = 3; len < size; ++len)
  {
    for (size_t i = 0; i < size-len+1; ++i)
    {
      size_t const j = i + len - 1;
      if (word[i] == word[j] && isPalindrome[i+1][j-1])
      {
        isPalindrome[i][j] = true;

        if (maxPalindromeSize < len)
        {
          maxPalindromeSize = len;
          startIndex = i;
        }
      }
    }
  }

  std::cout<<"Longest Palindrome = " << word.substr(startIndex, maxPalindromeSize) << std::endl;
}

// O(n^3) - check all words of size n to 1
void
longestPalindrome(std::string &word)
{
  for (size_t subsize = word.size(); subsize > 1; --subsize)
  {
    for (size_t i = 0; i < word.size()-subsize+1; ++i)
    {
      std::string const subword = word.substr(i, subsize);
      if (isPalindrome(subword))
      {
        std::cout<<"Longest Palindrome = " << subword <<std::endl;
        return;
      }
    }
  }
}


int
main()
{
  std::string word("forgeeksskeegfor");//("aaaabbaa");
  longestPalindrome(word);
  longestPalindromeDP(word);
  return 0;
}
