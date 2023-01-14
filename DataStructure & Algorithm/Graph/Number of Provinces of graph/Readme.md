## Number of Provinces

[Open Problem](https://practice.geeksforgeeks.org/problems/number-of-provinces/1)

**Approach :**<br>
A province is a group of directly or indirectly connected cities and no other cities outside of the group. Considering the above example, we can go from 1 to 2 as well as to 3, from every other node in a province we can go to each other. As we cannot go from 2 to 4 so it is not a province. We know about both the traversals, Breadth First Search (BFS) and Depth First Search (DFS). We can use any of the traversals to solve this problem because a traversal algorithm visits all the nodes in a graph. In any traversal technique, we have one starting node and it traverses all the nodes in the graph. Suppose there is an ‘N’ number of provinces so we need to call the traversal algorithm ‘N‘ times, i.e., there will be ‘N’ starting nodes. So, we just need to figure out the number of starting nodes<br>

-   The algorithm steps are as follows:

1. We need a visited array initialized to 0, representing the nodes that are not visited.<br>
2. Run the for loop looping from 0 to N, and call the DFS for the first unvisited node.<br>
3. DFS function call will make sure that it starts the DFS call from that unvisited node, and visits all the nodes that are in that province, and at the same time, it will also mark them as visited. <br>
4. Since the nodes traveled in a traversal will be marked as visited, they will no further be called for any further DFS traversal. <br>

5. Keep repeating these steps, for every node that you find unvisited, and visit the entire province.<br>
6. Add a counter variable to count the number of times the DFS function is called, as in this way we can count the total number of starting nodes, which will give us the number of provinces.<br>

**Complexity Analysis :**<br>

-   Time-Complexity: `O(N) + O(V+2E)`, Where `O(N)` is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of `O(V+2E)`.
-   Space-Complexity: `O(N) + O(N)`,Space for recursion stack space and visited array.

**References :**<br>
[Article](https://takeuforward.org/data-structure/number-of-provinces/)
[Video](https://www.youtube.com/watch?v=ACzkVtewUYA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=7)
