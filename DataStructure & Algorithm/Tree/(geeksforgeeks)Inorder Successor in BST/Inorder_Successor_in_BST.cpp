
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
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if (root == NULL)
            return NULL;

        Node *successor = NULL;

        while (root != NULL)
        {
            if (root->data <= x->data)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
};

int main(void)
{
    // https : // www.geeksforgeeks.org/inorder-traversal-of-binary-tree/
    Node *root = new Node(20);

    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(4);
    root->left->right = new Node(12);

    root->right->left = new Node(21);
    root->right->right = new Node(25);

    Solution obj;

    Node *res = obj.inorderSuccessor(root, root->left->left);

    cout << res->data << endl;

    return 0;
}
