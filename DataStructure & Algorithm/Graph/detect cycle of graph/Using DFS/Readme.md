## Detect cycle of Graph using DFS algorithm

**Approach :**<br>

-   In the DFS function call make sure to store the parent data along with the source node, create a visited array, and initialize to 0. The parent is stored so that while checking for re-visited nodes, we don’t check for parents.
-   We run through all the unvisited adjacent nodes using an adjacency list and call the recursive dfs function. Also, mark the node as visited
-   If we come across a node that is already marked as visited and is not a parent node, then keep on returning true indicating the presence of a cycle; otherwise return false after all the adjacent nodes have been checked and we did not find a cycle

Consider the following illustration to understand the process of detecting a cycle using DFS traversal:<br><br>
![CHEESE!](./image.gif)<br>

**Complexity Analysis :**<br>

-   Time Complexity:` O(N + 2E) + O(N)`, Where `N = Nodes`, `2E` is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another `O(N)` time.

-   Space Complexity: `O(N) + O(N) ~ O(N)`, Space for recursive stack space and visited area

**References :**<br>

-   [Learn From Video](https://www.youtube.com/watch?v=zQ3zgFypzX4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=12)
-   [Get helpful article](https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/)
