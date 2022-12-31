## DFS Algorithm to traverse a graph

**Approach:**<br>

DFS is a traversal technique which involves the idea of recursion and backtracking. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes. <br>

-   In DFS, we start with a node ‘v’, mark it as visited and store it in the solution vector. It is unexplored as its adjacent nodes are not visited.
-   We run through all the adjacent nodes, and call the recursive dfs function to explore the node ‘v’ which has not been visited previously. This leads to the exploration of another node ‘u’ which is its adjacent node and is not visited.
-   The adjacency list stores the list of neighbours for any node. Pick the neighbour list of node ‘v’ and run a for loop on the list of neighbours (say nodes ‘u’ and ‘w’ are in the list). We go in-depth with each node. When node ‘u’ is explored completely then it backtracks and explores node ‘w’.
-   This traversal terminates when all the nodes are completely explored.

**Complexity Analysis :**<br>

-   Time Complexity: For an undirected graph, `O(N) + O(2E)`, For a directed graph, `O(N) + O(E)`, Because for every node we are calling the recursive function once, the time taken is `O(N)` and `2E` is for total degrees as we traverse for all adjacent nodes.

-   Space Complexity: `O(3N) ~ O(N)`, Space for dfs stack space, visited array and an adjacency list.

**References :**<br>
[Learn more](https://takeuforward.org/data-structure/depth-first-search-dfs/)
[GeekForGeeks](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)
