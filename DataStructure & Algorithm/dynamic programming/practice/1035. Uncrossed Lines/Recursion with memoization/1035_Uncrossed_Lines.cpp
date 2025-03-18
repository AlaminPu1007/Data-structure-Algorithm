#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return Solved(0, 0, nums1, nums2, dp);
    }

private:
    int Solved(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (i >= nums1.size() || j >= nums2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (nums1[i] == nums2[j])
        {
            return 1 + Solved(i + 1, j + 1, nums1, nums2, dp);
        }

        return dp[i][j] = max(Solved(i + 1, j, nums1, nums2, dp), Solved(i, j + 1, nums1, nums2, dp));
    }
};

int main(void)
{
    Solution obj;
    vector<int> nums1 = {2, 5, 1, 2, 5}, nums2 = {10, 5, 2, 1, 5, 2};

    cout << obj.maxUncrossedLines(nums1, nums2) << endl;

    return 0;
}