## Inorder Successor in BST

This problem involved about, given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.<br/>

# Problem description

For better problem description, please visit [GeekForGeeks Pages](https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1)

**Approach :**<br/>

1. Initialize a pointer `successor` to NULL.
2. While the root is not NULL:
    - If the value of the current node is less than or equal to the value of the target node, move to the right subtree.
    - If the value of the current node is greater than the value of the target node, update the `successor` to the current node and move to the left subtree.
3. Return the `successor`, which represents the `inorder` successor of the target node.

**Complexity Analysis :**<br/>

-   Time-Complexity: ` O(n)` - where n is the number of elements in the input array.

-   Space-Complexity: `O(1)` - as the algorithm uses only a constant amount of extra space.
