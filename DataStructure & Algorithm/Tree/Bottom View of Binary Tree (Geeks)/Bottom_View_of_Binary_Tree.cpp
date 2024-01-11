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
    vector<int> bottomView(Node *root)
    {
        vector<int> res;

        map<int, int> Map;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto item = q.front();
            q.pop();

            Node *node = item.first;

            int x = item.second;

            Map[x] = node->data;

            if (node->left)
                q.push({node->left, x - 1});

            if (node->right)
                q.push({node->right, x + 1});
        }

        for (auto item : Map)
            res.push_back(item.second);

        return res;
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

    vector<int> res = obj.bottomView(root);

    for (auto item : res)
        cout << item << " ";

    return 0;
}
