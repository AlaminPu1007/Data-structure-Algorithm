## Boundary Traversal of binary tree

This problem involved about, given a Binary Tree, find its Boundary Traversal.

# Problem description

For better problem description, please visit [LeetCode Pages](https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)

**Approach :**<br/>

1. Initialization:
    - Check if the root is NULL. If true, return an empty vector.
2. Left Boundary Traversal:
    - Check if the root is a leaf node. If not, add it to the result vector.
    - Recursively traverse the left subtree (if exists) until a leaf node is reached.
3. Leaf Nodes Traversal
    - Recursively traverse the tree to identify and add all leaf nodes to the result vector.
4. Right Boundary Traversal:
    - Recursively traverse the right subtree (if exists) while avoiding leaf nodes.
    - Add each non-leaf node encountered to the result vector.
5. Return the final result vector containing the boundary elements of the binary tree.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n)` - The time complexity is O(n), where n is the number of nodes in the binary tree.
-   Space-Complexity: `O(h)` - where h is the height of the binary tree.
