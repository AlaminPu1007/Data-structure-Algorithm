#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int cutRod(int price[], int n)
  {
    int lengthArr[n];

    for (int i = 0; i < n; i++)
      lengthArr[i] = i + 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return DFS(price, lengthArr, n - 1, n, dp);
  }

private:
  int DFS(int price[], int lengthArr[], int n, int maxLen, vector<vector<int>> &dp)
  {
    if (n < 0 || maxLen < 0)
      return 0;

    if (dp[n][maxLen] != -1)
      return dp[n][maxLen];

    if (lengthArr[n] <= maxLen)
      return dp[n][maxLen] = max(price[n] + DFS(price, lengthArr, n, maxLen - lengthArr[n], dp), DFS(price, lengthArr, n - 1, maxLen, dp));

    else
      return dp[n][maxLen] = DFS(price, lengthArr, n - 1, maxLen, dp);
  }
};

int main(void)
{
  Solution obj;
  int arr[] = {1, 1, 1, 3, 4, 4, 5, 5, 5, 6, 6, 7};
  cout << obj.cutRod(arr, 12);
  return 0;
}