/*
    This solution will give, "Time Limit Exceeded"
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

        int lcs_of_palindrome = DFS(n, str, n, revStr);

        return (n - lcs_of_palindrome);
    }

private:
    int DFS(int n, string str, int m, string str2)
    {
        if (n <= 0 || m <= 0)
            return 0;

        if (str[n - 1] == str2[m - 1])
            return 1 + DFS(n - 1, str, m - 1, str2);

        else
            return max(DFS(n - 1, str, m, str2), DFS(n, str, m - 1, str2));
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