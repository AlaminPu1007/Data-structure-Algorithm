## Floor in BST

This problem involved about, you are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x. <br/>
Note: when x is smaller than the smallest node of BST then returns -1.<br/>

# Problem description

For better problem description, please visit [LeetCode Pages](https://www.geeksforgeeks.org/problems/floor-in-bst/1)

**Approach :**<br/>

1. Initialize the `floor` variable to -1.
2. Start with the root node.
3. While the current node is not NULL:
    - If the input value is equal to the current node's value, set `floor` to the current node's value and return `floor`.
    - If the input value is less than the current node's value, move to the left subtree.
    - If the input value is greater than or equal to the current node's value, set `floor` to the current node's value and move to the right subtree.
4. Return the final value of `floor` after the loop.

**Complexity Analysis :**<br/>

-   Time Complexity:

    1.  The time complexity of the search operation is `O(h)`, where h is the height of the BST.
    2.  In the worst case, where the tree is skewed, the time complexity is `O(n)`, where n is the number of nodes in the tree.
    3.  In the average case, for a balanced BST, the time complexity is `O(log n)`.

-   Space-Complexity: `O(1)` - since the iterative search is performed without using any additional data structures.
