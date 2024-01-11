## 513. Find Bottom Left Tree Value

This problem involved about, given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

# Problem description

For better problem description, please visit [GeekForGeeks Pages](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

**Approach :**<br/>

1. Initialization:

    - Initialize an empty vector `res` to store the result.
    - Use a map `Map` to store the bottom view nodes with the horizontal position (`x`) as the key.

2. Breadth-First Search (BFS):

    - Use a queue `q` to perform level-order traversal of the binary tree.
    - Enqueue the root node along with its horizontal position (0) into the queue.

3. Level-Order Traversal:

    - While the queue is not empty:
        - Dequeue a pair containing a node and its horizontal position from the front of the queue.
        - Update the map `Map` with the current node's data at the horizontal position (`x`).
        - If the node has a left child, enqueue the left child with updated horizontal position (`x - 1`).
        - If the node has a right child, enqueue the right child with updated horizontal position (`x + 1`).

4. Build Result:

    - Iterate over the map `Map` and push the values into the result vector `res`.

5. Result:
    - Return the vector `res`.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n)` - where n is the no of nodes of given tree
-   Space-Complexity: `O(w)` - where W is the maximum width of the binary tree at any level. In the worst case, the queue can have all the nodes at the last level, resulting in O(W) space.
