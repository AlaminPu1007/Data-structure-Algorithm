#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    Trie *list[26];

    bool containsKey(char ch)
    {
        return list[ch - 'a'] != NULL;
    }

    void insertIntoList(char ch, Trie *node)
    {
        list[ch - 'a'] = node;
    }

    Trie *get(char ch)
    {
        return list[ch - 'a'];
    }
};

class Solution
{
public:
    int countDistinctSubstrings(string &s)
    {
        int n = s.length();
        int count = 0;

        Trie *root = new Trie();

        for (int i = 0; i < n; i++)
        {
            Trie *node = root;

            for (int j = i; j < n; j++)
            {
                if (!node->containsKey(s[j]))
                {
                    node->insertIntoList(s[j], new Trie());
                    count++;
                }
                node = node->get(s[j]);
            }
        }

        return count + 1;
    }
};

int main(void)
{
    Solution obj;
    string s = "ccfdf";
    cout << obj.countDistinctSubstrings(s) << endl;
    return 0;
}