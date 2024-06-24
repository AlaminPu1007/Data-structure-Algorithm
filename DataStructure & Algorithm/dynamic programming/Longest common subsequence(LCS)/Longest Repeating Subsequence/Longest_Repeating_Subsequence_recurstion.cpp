/**
 * This solution will give us "Time Limit Exceeded";
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int LongestRepeatingSubsequence(string str)
  {
    int n = str.size();

    return DFS(str, n, str, n);
  }

private:
  int DFS(string str1, int i, string str2, int j)
  {
    // handle the base case
    if (i <= 0 || j <= 0)
      return 0;

    if (str1[i - 1] == str2[j - 1] && i != j)
      return 1 + DFS(str1, i - 1, str2, j - 1);

    else
      return max(DFS(str1, i - 1, str2, j), DFS(str1, i, str2, j - 1));
  }
};

int main(void)
{
  Solution obj;
  string s = "axxzxy";
  cout << obj.LongestRepeatingSubsequence(s) << endl;
  return 0;
}