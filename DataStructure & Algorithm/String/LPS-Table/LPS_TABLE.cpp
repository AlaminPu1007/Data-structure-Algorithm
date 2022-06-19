#include <iostream>
#include <string>
using namespace std;

class Solution{
    public: 
    void sum (string pattern)
    {
     int lps[10];
     int i = 1, j = 0, len = 0, c = 0;
     lps[0] = 0;
     len = pattern.length();

     while(i <= len)
     {
        if(pattern[j] == pattern[i])
        {
            lps[++c] = j + 1;
            j++;
            i++;
        }
        else {
            if(j == 0)
            {
                lps[++c] = 0;
                i++;
            }
            else {
                j = lps[j - 1];
            }
        }
     }

     for(i = 0; i < c; i++)
     cout<<lps[i]<<" ";
    }
};

int main(void)
{
    Solution obj;
    string str = "abcdbaa";
    obj.sum(str);
    return 0;
}
