/**
 * Need to submit this in Geek-for-geeks
 * https://www.geeksforgeeks.org/problems/floor-in-bst/1
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFloor(struct node *root, int x)
    {
        int floor = -1;

        while (root != NULL)
        {
            if (x == root->data)
            {
                floor = root->data;
                return floor;
            }

            if (x < root->data)
            {
                root = root->left;
            }
            else
            {
                floor = root->data;
                root = root->right;
            }
        }

        return floor;
    }
};

