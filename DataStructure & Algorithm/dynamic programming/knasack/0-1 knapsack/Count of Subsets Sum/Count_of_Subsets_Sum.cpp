
/**
 * Brute force approach
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

    return DFS(nums, n - 1, sum);
  }

private:
  int DFS(vector<int> &nums, int n, int sum)
  {
    if (sum == 0)
      return 1;

    if (n < 0 || sum < 0)
      return 0;

    if (nums[n] <= sum)
      return DFS(nums, n - 1, sum - nums[n]) + DFS(nums, n - 1, sum);

    else
      DFS(nums, n - 1, sum);
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