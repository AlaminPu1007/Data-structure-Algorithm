## Children Sum Property in Binary Tree | O(N) Approach

This problem involved about, The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).

**Approach :**<br/>

1. Initialization:

    - The `changeTree` function takes a root of a binary tree and modifies the tree values based on the sum of its children.

2. Reordering Function:

    - The core logic is implemented in the `reorder` function.
    - The function recursively traverses the binary tree and updates the values of each node based on the sum of its left and right children.

3. Value Update Logic:

    - If the value of the current node (`root->val`) is greater than the sum of its left and right children (`root->left->val + root->right->val`), update the values of left and right children to be equal to the value of the current node.
    - Otherwise, update the value of the current node to be equal to the sum of its left and right children.

4. Recursive Traversal:

    - Recursively call `reorder` on the left subtree (`reorder(root->left)`) and the right subtree (`reorder(root->right)`).

5. Update Root Value:

    - After completing the traversal of both left and right subtrees, update the value of the current node (`root->val`) to be the sum of its left and right children (`total = root->left->val + root->right->val`).

6. Result:
    - The `changeTree` function returns the modified binary tree.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n)`
-   Time-Complexity: `O(h)`
