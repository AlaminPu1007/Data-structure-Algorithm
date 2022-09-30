#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Recursion_Subsequence(int i, vector<int> &arr, vector<int> &ds)
    {
        // This is base case
        if (i >= arr.size())
        {
            for (int j = 0; j < ds.size(); j++)
                cout << ds[j] << " ";
            cout << endl;
            return;
        }
        // store each subsequence
        ds.push_back(arr[i]);

        Recursion_Subsequence(i + 1, arr, ds);
        // after complete first recursion tree completely
        //  we need to pop last value
        ds.pop_back();

        // get sub-sequecy after pop last element
        Recursion_Subsequence(i + 1, arr, ds);
    }
};

int main(void)
{
    Solution obj;

    // string str = "312", result = "";
    vector<int> str = {3, 1, 2}, result;
    obj.Recursion_Subsequence(0, str, result);

    return 0;
}