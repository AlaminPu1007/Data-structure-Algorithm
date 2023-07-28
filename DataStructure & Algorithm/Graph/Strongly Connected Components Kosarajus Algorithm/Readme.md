## Strongly Connected Components – Kosaraju’s Algorithm

This problem involved about, given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

# Problem description

For better explanation, please visit [GeekForGeeks Page](https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)

**Approach :**<br/>

1. <b> Sort all the nodes according to their finishing time: </b> &nbsp; To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.

2. <b> Reverse all the edges of the entire graph: </b> &nbsp; Now, we will create another adjacency list and store the information of the graph in a reversed manner.

3. <b> Perform the DFS and count the no. of different DFS calls to get the no. of SCC: </b> &nbsp;Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get visited.

4. Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to store the nodes in some array during each individual DFS call in step 3.

**Note:**<br/>

-   The first step is to know, from which node we should start the DFS call.
-   The second step is to make adjacent SCCs unreachable and to limit the DFS traversal in such a way, that in each DFS call, all the nodes of a particular SCC get visited.
-   The third step is to get the numbers of the SCCs. In this step, we can also store the nodes of each SCC if we want to do so.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(V+E) + O(V+E) + O(V+E) ~ O(V+E)` , where `V = no. of vertices, E = no. of edges`. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take `O(V+E)` each.

-   Space-Complexity: `O(V) + O(V) + O(V+E)`, where `V = no. of vertices, E = no. of edges`. Two `O(V)` for the visited array and the stack we have used. `O(V+E)` space for the reversed adjacent list.

**References :**<br/>

-   [Learn from blog](https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/)
-   [Learn from video](https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=59)
