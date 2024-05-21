/**
 * This approach only work for positive sum
 * accepted on -> https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumDifference(vector<int> &nums)
  {
    int sum = 0;

    for (int i = 0; i < n; i++)
      sum += nums[i];

    int mid = (sum / 2);

    // Initialize DP table
    vector<vector<bool>> dp(n + 1, vector<bool>(mid + 1, false));

    // Initialize the dp array for sum 0 to true
    for (int i = 0; i < n + 1; i++)
      dp[i][0] = true;

    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 1; j < mid + 1; j++)
      {
        if (nums[i - 1] <= j)
          dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];

        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    // Collect valid sums from the last row of the dp table
    vector<int> validNums;

    for (int j = 0; j < mid + 1; j++)
      if (dp[n][j])
        validNums.push_back(j);

    int res = INT_MAX;

    for (auto item : validNums)
      res = min(res, abs(sum - 2 * item));

    return res;
  }
};

int main(void)

{
  Solution obj;
  vector<int> arr = {1, 2, 7};
  cout << obj.minimumDifference(arr) << endl;
  return 0;
}