## BFS Algorithm to traverse a Graph

**Approach :**<br>

-   Queue data structure: follows FIFO, and will always contain the starting.
-   Visited array: an array initialized to 0

In BFS, we start with a “starting” node, mark it as visited, and push it into the queue data structure.<br>
In every iteration, we pop out the node ‘v’ and put it in the solution vector, as we are traversing this node.<br>
All the unvisited adjacent nodes from ‘v’ are visited next and are pushed into the queue. The list of adjacent neighbors of the node can be accessed from the adjacency list.<br>
Repeat steps 2 and 3 until the queue becomes empty, and this way you can easily traverse all the nodes in the graph.<br>

**Complexity Analysis:**<br>

-   Time Complexity: `O(N) + O(2E)`, Where `N = Nodes`, `2E` is for total degrees as we traverse all adjacent nodes.
-   Space Complexity: `O(3N) ~ O(N)`, Space for queue data structure visited array and an adjacency list

**References :**<br>
[Learn from Geeks for Geeks](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
[Learn from Take U Forward](https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/)
