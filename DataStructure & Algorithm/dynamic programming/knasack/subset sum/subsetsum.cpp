#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool subsetSum(vector<int> &arr, int sum)
  {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i < n + 1; i++)
      dp[0][i] = false;

    for (int i = 0; i < n + 1; i++)
      dp[i][0] = true;

    for (int i = 1; i < n + 1; i++)
    {
      // j will point sum from 1 to sum+1
      for (int j = 1; j < sum + 1; j++)
      {
        if (arr[i - 1] <= j)
        {
          // update current context with any of truthy value
          dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
        }
        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    for (auto item : dp)
    {
      for (auto it : item)
        cout << it << " ";
      cout << endl;
    }

    return dp[n][sum];

    // recursion approach
    // return DFS(arr, arr.size() - 1, sum);
  }

private:
  bool DFS(vector<int> &arr, int idx, int sum)
  {
    if (sum == 0)
      return true;

    else if (idx < 0 || sum < 0)
      return false;

    if (arr[idx] <= sum)
      return DFS(arr, idx - 1, sum - arr[idx]) || DFS(arr, idx - 1, sum);

    else
      return DFS(arr, idx - 1, sum);
  }
};

int main(void)
{
  Solution obj;
  vector<int> arr = {2, 3, 6};
  int sum = 5;
  cout << obj.subsetSum(arr, sum) << endl;
  return 0;
};