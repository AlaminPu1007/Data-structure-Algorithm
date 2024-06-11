/**
 * This is only accepted solution
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string str, int n)
    {
        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (str[i - 1] == revStr[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return (n - dp[n][n]);
    }
};

int main(void)
{
    Solution obj;
    int n = 7;
    string str = "aebcbda";
    cout << obj.minDeletions(str, n) << endl;
    return 0;
}