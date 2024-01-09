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
    vector<int> topView(Node *root)
    {
        vector<int> res;
        // store vertical(x axis) line wise single node
        map<int, int> Map;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            Node *tempNode = node.first;

            int x = node.second;

            if (!Map[x])
                Map[x] = tempNode->data;

            if (tempNode->left)
                q.push({tempNode->left, x - 1});

            if (tempNode->right)
                q.push({tempNode->right, x + 1});
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
    vector<int> res = obj.topView(root);

    for (auto item : res)
    {
        cout << item << " ";
    }

    return 0;
}
