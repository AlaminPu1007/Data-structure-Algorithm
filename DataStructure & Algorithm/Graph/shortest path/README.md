# List of some popular shortest path algorithm

This file include some popular shortest path algorithm with smallest description.

### 1. Dijkstra's Algorithm

Finds the shortest path from a single source node to all other nodes in a weighted graph with non-negative weights. <br/>
Note: Dijkstra’s Algorithm is not valid for negative weights or negative cycles.

### 2. Bellman-Ford Algorithm

The Bellman-Ford algorithm is best suited to find the shortest paths in a directed graph, with one or more negative edge weights, from the source vertex to all other vertices.<br/>

The Bellman-Ford algorithm can also be used for graphs with positive edges (both directed and undirected), like we can with Dijkstra's algorithm, but Dijkstra's algorithm is preferred in such cases because it is faster. <br/>

It's also used for to detect and report the presence of negative cycles.

### 3. Floyd Warshall Algorithm

The `Floyd Warshall Algorithm` is an all pair shortest path algorithm (multi source) unlike `Dijkstra` and `Bellman Ford` which are single source shortest path algorithms. This algorithm works for both the directed and undirected weighted graphs. But, it does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).<br/>

It follows Dynamic Programming approach to check every possible path going via every possible node in order to calculate shortest distance between every pair of nodes.