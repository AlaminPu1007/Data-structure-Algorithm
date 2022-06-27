#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int Naive_String_Pattern_Search(string str, string pattern)
    {
        int i, j, str_len = str.length(), pattern_len = pattern.length();

        // Iteration for root string or search pattern of this string
        for (i = 0; i < str_len; i++)
        {
            // search pattern inside this string
            for (j = 0; j < pattern_len; j++)
            {
                // The idea behind of naive algorithm is that,
                //  whenever we get any miss-matching character along str[i] != pattern[i]
                //  we break our iteration, and check with i next iteration,
                if (str[i + j] != pattern[j])
                    break;
            }
            // if j -> length is equal to pattern_len,
            // thats means we found our desire sub string inside of root string
            if (j == pattern_len)
            {
                // we get out put i = {0, 5}, from this position, our pattern is starting position
                cout << i << " " << endl;
            }
        }

        return 0;
    }
};

int main(void)
{
    Solution obj;
    string str = "ABCDEABC";
    string pattern = "ABC";

    obj.Naive_String_Pattern_Search(str, pattern);
}