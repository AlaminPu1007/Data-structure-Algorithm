/*
     Simplified problem with this equation

     s1 - s2 = diff     ------- (i)
     s1 + s2 = arraySum ------- (ii)
     ----------------------------------
     2s1       = diff + arraySum
     => s1 = (diff + arraySum) / 2

     Now we have to just find out `s1` subset sum

     NOTE: This solution give us Time-Limited exceed
   */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  long long mod = 1e9 + 7;

public:
  int countPartitions(int n, int d, vector<int> &arr)
  {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if ((sum - d) < 0 || (sum - d) % 2 == 1)
      return 0;

    int reqSum = (d + sum) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(reqSum + 1, -1));

    return DFS(arr, n - 1, reqSum, dp);
  }

private:
  int DFS(vector<int> arr, int n, int sum, vector<vector<int>> &dp)
  {
    if (n < 0)
    {
      if (sum == 0)
        return 1;

      return 0;
    }

    if (dp[n][sum] != -1)
      return dp[n][sum];

    if (arr[n] <= sum)
      return dp[n][sum] = DFS(arr, n - 1, sum - arr[n], dp) + DFS(arr, n - 1, sum, dp);

    return dp[n][sum] = DFS(arr, n - 1, sum, dp);
  }
};

int main(void)
{
  Solution obj;
  vector<int> arr = {0, 1, 2, 2, 2, 3, 0, 3, 0, 1};
  int n = arr.size();
  cout << obj.countPartitions(n, 12, arr) << endl;
  return 0;
}