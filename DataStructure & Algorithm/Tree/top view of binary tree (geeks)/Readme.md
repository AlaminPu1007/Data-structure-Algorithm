## Top View of Binary Tree

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

# Problem description

For better problem description, please visit [GeekForGeeks Pages](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

**Approach :**<br/>

1. First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.
2. Then we need a map data structure to store the lines and the nodes. This map will store the data in the form of sorted orders of keys(Lines).
3. Here we will follow the level order traversal.
4. Traverse through the nodes starting with root,0 and store them to the queue.
5. Until the queue is not empty, store the node and line no. in 2 separate variable .
6. Then check if that line is present in the map or not
7. If not present then store the line and the node->val to the map
8. Otherwise store the node->left and node->right along with there line nos. to the queue.
9. Then print the node->val from the map

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n)` - where n is the no of nodes of given tree
-   Space-Complexity: `O(h)` - where h is the height of the tree
