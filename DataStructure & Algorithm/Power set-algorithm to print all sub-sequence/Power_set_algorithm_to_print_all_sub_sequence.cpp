#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Power_Sub_Seq(vector<int> &arr)
    {
        int len = arr.size(), Power_len = pow(2, arr.size());
        for (int i = 0; i < Power_len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i & (1 << j))
                    cout << arr[j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    Solution obj;
    vector<int> arr = {3, 1, 2};
    obj.Power_Sub_Seq(arr);
    return 0;
}