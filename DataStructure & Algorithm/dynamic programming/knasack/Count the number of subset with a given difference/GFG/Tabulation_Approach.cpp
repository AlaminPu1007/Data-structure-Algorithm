/*
     Simplified problem with this equation

     s1 - s2 = diff     ------- (i)
     s1 + s2 = arraySum ------- (ii)
     ----------------------------------
     2s1       = diff + arraySum
     => s1 = (diff + arraySum) / 2

     Now we have to just find out `s1` subset sum
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

    for (int i = 0; i < reqSum + 1; i++)
      dp[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
      dp[i][0] = 1;

    /*
      We are initialising first column to 1, assuming there is only 1 way to make subset sum equal to 0,
      i.e. null subset, BUT this fails if we have 0's as elements of array.
      If we have a single 0 present in the array, then the subsets will be '{}, {0}'
      whose sum will be 0. Hence, there can be more than 1 way to make sum==0.
    */

    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 0; j < reqSum + 1; j++)
      {
        if (arr[i - 1] <= j)
          dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;

        else
          dp[i][j] = dp[i - 1][j] % mod;
      }
    }

    return dp[n][reqSum];
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