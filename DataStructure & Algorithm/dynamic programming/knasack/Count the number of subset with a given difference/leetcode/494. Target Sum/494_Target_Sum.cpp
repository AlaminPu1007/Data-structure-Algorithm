#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum < abs(target) || (sum - target) < 0 || (sum - target) % 2 == 1)
      return 0;

    int targetSum = (target + sum) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));

    for (int i = 0; i < targetSum + 1; i++)
      dp[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
      dp[i][0] = 1;

    /*
       If all the elements are 0 and we want a sum 0, for that we need j from 0.
       So that 0 can also be considered as sum of previous subset of i elements.
       ex: arr = {0, 0, 0, 0, 0, 0, 0, 0, 1}, target = 1, ans = 256
    */

    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= targetSum; j++)
      {
        if (nums[i - 1] <= j)
          dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];

        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    return dp[n][targetSum];
  }
};

int main(void)
{
  Solution obj;
  vector<int> arr = {100};
  int target = -200;
  cout << obj.findTargetSumWays(arr, target) << endl;
  return 0;
}