/*
  This solution also give us "Time Limit Exceeded".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int LongestRepeatingSubsequence(string str)
  {
    int n = str.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return DFS(str, n, str, n, dp);
  }

private:
  int DFS(string str1, int i, string str2, int j, vector<vector<int>> &dp)
  {
    // handle the base case
    if (i <= 0 || j <= 0)
      return 0;

    // return from the cache
    if (dp[i][j] != -1)
      return dp[i][j];

    if (str1[i - 1] == str2[j - 1] && i != j)
      dp[i][j] = 1 + DFS(str1, i - 1, str2, j - 1, dp);

    else
      dp[i][j] = max(DFS(str1, i - 1, str2, j, dp), DFS(str1, i, str2, j - 1, dp));

    return dp[i][j];
  }
};

int main(void)
{
  Solution obj;
  string s = "axxzxy";
  cout << obj.LongestRepeatingSubsequence(s) << endl;
  return 0;
}