/**
 * Need to submit this in Geek-for-geeks
 * https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCeil(struct node *root, int input)
    {
        int ceil = -1;

        while (root != NULL)
        {
            if (input == root->data)
            {
                ceil = root->data;
                return ceil;
            }

            if (input > root->data)
                root = root->right;

            else
            {
                ceil = root->data;
                root = root->left;
            }
        }

        return ceil;
    }
};

