## Ceil in BST

This problem involved about, given a BST and a number X, find Ceil of X. <br/>
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.<br/>

If Ceil could not be found, return -1.<br/>

# Problem description

For better problem description, please visit [LeetCode Pages](https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1)

**Approach :**<br/>

1. Initialize the `ceil` variable to -1.
2. Start with the root node.
3. While the current node is not NULL:
    - If the input value is equal to the current node's value, set `ceil` to the current node's value and return `ceil`.
    - If the input value is greater than the current node's value, move to the right subtree.
    - If the input value is less than the current node's value, set `ceil` to the current node's value and move to the left subtree.
4. Return the final value of `ceil` after the loop.

**Complexity Analysis :**<br/>

-   Time Complexity:

    1.  The time complexity of the search operation is O(h), where h is the height of the BST.
    2.  In the worst case, where the tree is skewed, the time complexity is O(n), where n is the number of nodes in the tree.
    3.  In the average case, for a balanced BST, the time complexity is O(log n).

-   Space-Complexity: `O(1)` - since the iterative search is performed without using any additional data structures.
