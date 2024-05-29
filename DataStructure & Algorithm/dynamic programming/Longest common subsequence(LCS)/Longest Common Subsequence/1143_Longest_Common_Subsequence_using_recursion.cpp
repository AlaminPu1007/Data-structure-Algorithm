/*
  This solution will give us Time Limit Exceeded
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int n = text1.size(), m = text2.size();

    // ex:(in recursive base case would be `if (n < 0 || m < 0))`
    // return DFS(n - 1, text1, m - 1, text2);

    // another ex:(in recursive base case would be `if (n == 0 || m == 0))`
    return DFS(n, text1, m, text2);
  }

private:
  // this method will help us to get the max length of lcs
  int DFS(int n, string text1, int m, string text2)
  {
    // handle the base case

    // if (n < 0 || m < 0)
    if (n == 0 || m == 0)
      return 0;

    // if both has the same character
    if (text1[n] == text2[m])
      return 1 + DFS(n - 1, text1, m - 1, text2);

    // for miss match the character
    else
      return max(
          // check, after remain text2 length, same and update text1 length
          DFS(n - 1, text1, m, text2),

          // check, after remain text1 length, same and update text2 length
          DFS(n, text1, m - 1, text2));
  }
};

int main(void)
{
  Solution obj;
  string text1 = "abcde", text2 = "ace";
  cout << obj.longestCommonSubsequence(text1, text2) << endl;
  return 0;
}