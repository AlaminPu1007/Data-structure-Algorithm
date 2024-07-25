# Kahn’s Algorithm for Topological Sorting

Given a Directed Acyclic Graph having `V` vertices and `E` edges, your task is to find any Topological Sorted order of the graph.<br/>

<bold>Kahn’s Algorithm</bold> for Topological Sorting is a method used to order the vertices of a directed graph in a linear order such that for every directed edge from vertex A to vertex B, A comes before B in the order. The algorithm works by repeatedly finding vertices with no incoming edges, removing them from the graph, and updating the incoming edges of the remaining vertices. This process continues until all vertices have been ordered.

## why Kahn’s Algorithm will fail for a directed cyclic graph?

If a directed graph contains a cycle, the in-degree of the nodes that are parts of that cycle will never be 0 due to the cyclic dependency. But in that algorithm, we push a node into the queue only if its in-degree becomes 0. So, those nodes of the cycle will never be pushed into the queue as well as included in the topological sorting. And here it violates the rules of topological sorting as topological sorting is a linear ordering of all V vertices.

**Algorithm :**<br/>

1. Add all nodes with in-degree 0 to a queue.
2. While the queue is not empty:
    - Remove a node from the queue.
    - For each outgoing edge from the removed node, decrement the in-degree of the destination node by 1.
    - If the in-degree of a destination node becomes 0, add it to the queue.
3. If the queue is empty and there are still nodes in the graph, the graph contains a cycle and cannot be topologically sorted.
4. The nodes in the queue represent the topological ordering of the graph.

<br/>
<br/>

### A Directed Acyclic Graph (DAG)

[!IMAGE](image_one.webp)

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(V + E)` - The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.
-   Space-Complexity: `O(V)` - The queue needs to store all the vertices of the graph. So the space required is O(V).

**References :**<br/>

-   [GFG](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)
-   [Take U Forward](https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/)
