#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string &str, int k)
    {
        unordered_map<char, int> Map;
        int res = -1, n = str.size(), left = 0;

        for (int i = 0; i < n; i++)
        {
            Map[str[i]]++;

            while (Map.size() > k)
            {
                Map[str[left]]--;

                if (Map[str[left]] == 0)
                    Map.erase(str[left]);

                left++;
            }

            if (Map.size() == k)
                res = max(res, i - left + 1);
        }

        return res;
    }
};

int main(void)
{
    Solution obj;
    string str = "aabacbebebe";
    int k = 3;

    cout << obj.longestKSubstr(str, k) << endl;

    return 0;
}