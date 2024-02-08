
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

class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution
{
private:
    NodeValue largestBSTSubTreeHelper(Node *root)
    {
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // traverse the left subtree
        auto left = largestBSTSubTreeHelper(root->left);
        auto right = largestBSTSubTreeHelper(root->right);

        // do the business logic for current standing node

        // it it's a valid BST
        if ((left.maxNode < root->data) && (root->data < right.minNode))
        {
            // now return a valid BST where it's left value always small and right value always grater
            return NodeValue(
                // get the minimal value for left, min for to avoid null value
                min(root->data, left.minNode),
                // get the max value for right, max for to avoid null value
                max(root->data, right.maxNode),
                // calculate the bst size
                (left.maxSize + right.maxSize + 1));
        }

        // if it's not valid BST, then return larger value so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node *root)
    {
        return largestBSTSubTreeHelper(root).maxSize;
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
    cout << obj.largestBst(root) << endl;

    return 0;
}
