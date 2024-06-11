/**
 * This solution also give up "Timelimit exceed"
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
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int lcs_of_palindrome = DFS(n, str, n, revStr, dp);

        return (n - lcs_of_palindrome);
    }

private:
    int DFS(int n, string str, int m, string str2, vector<vector<int>> &dp)
    {
        if (n <= 0 || m <= 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (str[n - 1] == str2[m - 1])
            dp[n][m] = 1 + DFS(n - 1, str, m - 1, str2, dp);

        else
            dp[n][m] = max(DFS(n - 1, str, m, str2, dp), DFS(n, str, m - 1, str2, dp));

        return dp[n][m];
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