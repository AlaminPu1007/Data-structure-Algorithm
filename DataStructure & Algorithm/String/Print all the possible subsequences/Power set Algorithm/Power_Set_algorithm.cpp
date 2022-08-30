#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void PrintAllSubSequence(string s)
    {
        int len = s.size(), Pow_len = pow(2, s.size());
        for (int i = 0; i < Pow_len; i++)
        {
            for (int j = 0; j < len; j++)

                if (i & (1 << j))
                    cout << s[j] << " ";

            cout << endl;
        }
    }
};

int main(void)
{
    Solution obj;
    string s = "abc";

    obj.PrintAllSubSequence(s);
    return 0;
}