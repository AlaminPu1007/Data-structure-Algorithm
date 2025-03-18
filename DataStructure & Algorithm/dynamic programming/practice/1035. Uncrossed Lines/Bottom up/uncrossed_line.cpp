#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // fill first row with 0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        // initial value of first column
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};

int main(void)
{
    Solution obj;
    vector<int> nums1 = {2, 5, 1, 2, 5}, nums2 = {10, 5, 2, 1, 5, 2};

    cout << obj.maxUncrossedLines(nums1, nums2) << endl;

    return 0;
}