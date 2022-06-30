#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
public:
    int KMP_STRING_MATCH(string str, string ptrn)
    {
        int str_len = 0, ptrn_len = 0;

        str_len = str.length(), ptrn_len = ptrn.length();
        // define Longest prefix suffix table array with pattern size
        int lps[ptrn_len];

        // making of lps table
        LPS_TABLE(ptrn, lps, ptrn_len);

        // print lps table value
        //  for(int i = 0; i < ptrn_len; i++)
        //  cout<<lps[i]<<" ";

        // Making of KMP string search login with helps of lps table
        int i = 0, j = 0, count = 0;
        while (i < str_len)
        {
            if (str[i] == ptrn[j])
            {
                i++;
                j++;
            }
            // check if any sub string matching occur or not
            // if j value is equal to pattern length, thats means we get an matching string
            if (j == ptrn_len)
            {
                cout << "Matching at position " << i - j << endl;
                //  there is possible to sub string can be present more times, instead of one
                //  set j value from lps[j - 1]
                j = lps[j - 1];
                i++;
            }
            // if any mis-matching occur, we need to check two thing,
            if ((i < str_len) && (str[i] != ptrn[j]))
            {
                // j == 0, means, j already at initial point, so we should increase i value
                if (j == 0)
                {
                    i++;
                }
                // set j value from lps[j - 1] table
                else
                {
                    j = lps[j - 1];
                }
            }
        }

        return 0;
    };

    void LPS_TABLE(string ptrn, int *lps, int n)
    {
        // i = 1 --> root visited value, staring from 1 position
        // j = 0 --> always compare j == i,
        int i = 1, j = 0, c = 0;
        // lps[0] = 0, is always 0, because for length of string 1, always, prefix & suffix is 0
        lps[0] = 0;

        // procedure of making LPS table
        while (i <= n) // n = pattern length
        {
            // if i == j, we need to put lps[] = j + 1;
            if (ptrn[j] == ptrn[i])
            {
                lps[++c] = j + 1;
                i++;
                j++;
            }
            // if j == 0, we need to put lps[] = 0, and increment i = i + 1,
            // because there is not possible way to matching character
            else if (j == 0)
            {
                lps[++c] = 0;
                i++;
            }
            // we have to get back lps last matching index
            // ex : lps[j - 1] has 0, 0 --> means its start from begin
            else
            {
                j = lps[j - 1]; // set j value from lps table value
            }
        }
    };
};

int main(void)
{
    Solution obj;
    string str = "abadfeabaegaba", ptrn = "aba";

    obj.KMP_STRING_MATCH(str, ptrn);
    return 0;
}