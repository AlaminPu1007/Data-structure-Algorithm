// unsolved
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _v)
    {
        data = _v;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<int> boundary(Node *root)
    {
        vector<int> res;

        if (root == NULL)
            return res;

        if (!(root->left == NULL && root->right == NULL))
            res.push_back(root->data);

        // check for left boundary of given tree
        addLeftBoundaries(root->left, res);

        // get all leaf nodes only
        addLeavesNode(root, res);

        // check for left boundary of given tree
        addRightBoundaries(root->right, res);

        return res;
    }

private:
    void addLeftBoundaries(Node *node, vector<int> &res)
    {
        if ((node == NULL) || (node->left == NULL && node->right == NULL))
            return;

        res.push_back(node->data);

        if (node->left)
            addLeftBoundaries(node->left, res);
        else
            addLeftBoundaries(node->right, res);
    }

    void addLeavesNode(Node *node, vector<int> &res)
    {
        if (node == NULL)
            return;

        if (node->left == NULL && node->right == NULL)
        {
            res.push_back(node->data);
            return;
        }

        addLeavesNode(node->left, res);
        addLeavesNode(node->right, res);
    }

    void addRightBoundaries(Node *node, vector<int> &res)
    {
        if ((node == NULL) || (node->left == NULL && node->right == NULL))
            return;

        if (node->right)
            addRightBoundaries(node->right, res);
        else
            addRightBoundaries(node->left, res);

        res.push_back(node->data);
    }
};

int main(void)
{
    // https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> res = obj.boundary(root);

    for (auto item : res)
    {
        cout << item << " ";
    }

    return 0;
}
