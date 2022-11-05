// https://www.hackerrank.com/challenges/common-child/problem?isFullScreen=false
// get timelimit execution error
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int commonChild(string s1, string s2)
    {
        // called an recursive method
        int res = LCS(0, 0, s1, s2);
        return res;
    }

private:
    int LCS(int i, int j, string &s1, string &s2)
    {
        if (s1[i] == '\0' || s2[j] == '\0')
            return 0;

        else if (s1[i] == s2[j])
            return 1 + LCS(i + 1, j + 1, s1, s2);

        else
            return max(LCS(i + 1, j, s1, s2), LCS(i, j + 1, s1, s2));
    }
};

int main(void)
{
    Solution obj;
    string str1 = "SHINCHAN", str2 = "NOHARAAA";
    int res = obj.commonChild(str1, str2);

    cout << res << endl;
    return 0;
}