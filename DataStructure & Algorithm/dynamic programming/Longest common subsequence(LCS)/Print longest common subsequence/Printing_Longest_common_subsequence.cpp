#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestCommonSubsequence(string text1, string text2)
  {
    int n = text1.size(), m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    string ans = "";

    /* with properly considering the valid path we will able to find out the valid string  */

    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 1; j < m + 1; j++)
      {
        if (text1[i - 1] == text2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }

        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    int i = text1.size(), j = text2.size();

    // we traverse from the backward with the valid path from dp array
    while (i > 0 && j > 0)
    {
      // if both have the equal character
      if (text1[i - 1] == text2[j - 1])
      {
        ans = ans + text1[i - 1];
        i--;
        j--;
      }
      else if (dp[i][j - 1] > dp[i - 1][j])
        j--;

      else
        i--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main(void)
{
  Solution obj;
  // string text1 = "abcde", text2 = "aabe";
  string text1 = "abcde", text2 = "ace";
  cout << obj.longestCommonSubsequence(text1, text2) << endl;
  return 0;
}