
/**
 * DFS with memoization approach
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

    return DFS(nums, n - 1, sum, dp);
  }

private:
  int DFS(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
  {
    if (sum == 0)
      return 1;

    if (n < 0 || sum < 0)
      return 0;

    if (dp[n][sum] != -1)
      return dp[n][sum];

    if (nums[n] <= sum)
      return dp[n][sum] = DFS(nums, n - 1, sum - nums[n], dp) + DFS(nums, n - 1, sum, dp);

    else
      return dp[n][sum] = DFS(nums, n - 1, sum, dp);
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