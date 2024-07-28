# Shortest Path Algorithm Using Priority Queue

This problem involved about, This document provides an approach for implementing Dijkstra's algorithm to find the shortest path in an undirected, weighted graph using a priority queue.
<br/>
Note: Dijkstra’s Algorithm is not valid for negative weights or negative cycles.

## Approach

1. We would be using a min-heap and a distance array of size V (where ‘V’ are the number of nodes in the graph) initialized with infinity (indicating that at present none of the nodes are reachable from the source node) and initialize the distance to source node as 0.

2. We push the source node to the queue along with its distance which is also 0.

3. For every node at the top of the queue, we pop the element out and look out for its adjacent nodes. If the current reachable distance is better than the previous distance indicated by the distance array, we update the distance and push it into the queue.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O( E * log(V) )` - Where E = Number of edges and V = Number of Nodes.
-   Space-Complexity: `O(V)` - V = Number of Nodes.