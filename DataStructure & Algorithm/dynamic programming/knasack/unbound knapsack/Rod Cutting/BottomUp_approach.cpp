/* This code has error, need to fix */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int cutRod(int price[], int n)
  {
    vector<int> lengthArr(n);

    for (int i = 0; i < n; i++)
      lengthArr[i] = i + 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 1; j < n + 1; j++)
      {
        if (lengthArr[i - 1] <= j)
          dp[i][j] = max(price[i - 1] + dp[i][j - lengthArr[i - 1]], dp[i - 1][j]);

        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    return dp[n][n];
  }
};

int main(void)
{
  Solution obj;
  int arr[] = {1, 1, 1, 3, 4, 4, 5, 5, 5, 6, 6, 7};
  cout << obj.cutRod(arr, 12);
  return 0;
}