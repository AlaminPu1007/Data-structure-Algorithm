/*
    This problem is about update tree with children sum property
    https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int _v)
    {
        val = _v;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    TreeNode *changeTree(TreeNode *root)
    {
        reorder(root);
        return root;
    }

private:
    void reorder(TreeNode *root)
    {
        if (root == NULL || !root->left || !root->right)
            return;

        if (root->val > (root->left->val + root->right->val))
        {
            if (root->left)
                root->left->val = root->val;

            if (root->right)
                root->right->val = root->val;
        }
        else
            root->val = (root->left->val + root->right->val);

        // traverse in left tree
        reorder(root->left);

        // traverse in right tree
        reorder(root->right);

        // update root value whenever completed traverse both left & right tree
        int total = 0;

        if (root->left)
            total += root->left->val;

        if (root->right)
            total += root->right->val;

        // any of child is present
        if (root->left || root->right)
            root->val = total;
    }

public:
    // print list
    void printListOfNode(TreeNode *root)
    {
        if (root == NULL)
            return;

        printListOfNode(root->left);

        cout << root->val << " ";

        printListOfNode(root->right);
    }
};

int main(void)
{
    // https://www.techiedelight.com/wp-content/uploads/Children-Sum-Property-Binary-Tree.png
    TreeNode *root = new TreeNode(25);
    root->left = new TreeNode(12);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    TreeNode *res = obj.changeTree(root);

    obj.printListOfNode(res);

    return 0;
}
