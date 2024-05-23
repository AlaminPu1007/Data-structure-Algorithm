
/**
 * Tabulation approach(Bottom up approach)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSubsetsEqualSum(vector<int> &nums, int sum)
  {
    int res = 0;
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    for (int i = 0; i < sum + 1; i++)
      dp[0][i] = 0;

    // for empty sum
    for (int i = 0; i < n + 1; i++)
      dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 1; j < sum + 1; j++)
      {
        if (nums[i - 1] <= j)
          dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];

        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    return dp[n][sum];
  }
};

int main(void)
{
  Solution obj;
  vector<int> nums = {5, 2, 3, 10, 6, 8};
  int sum = 10;
  cout << obj.countSubsetsEqualSum(nums, sum) << endl;
  return 0;
}