/*
    Topological is a technique, to find linear ordering of vertices
    such that for every directed edge `u -> v`, where vertex u comes before v in the ordering.
    NOTE: This algorithm is based on the in-degree of each node. It always working for a Directed Acyclic graph(DAG).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topologicalSort(vector<vector<int>> &edges, int n)
    {
        // initialization will be goes to here
        vector<int> adj[n];
        vector<int> res;
        vector<int> inDegree(n + 1, 0);
        queue<int> q;

        // count each node inDegree
        for (auto node : edges)
        {
            int u = node[0];
            int v = node[1];

            // create a adjacency of each node
            adj[u].push_back(v);

            // we considered only `v`, cause it has a edge that came from `u`.
            inDegree[v]++;
        }

        // now put all node in queue who's in-degree is `0`, cause only this node always came from other nodes
        for (int i = 0; i < n; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();

            // get front node from queue, and push into result array
            res.push_back(node);

            // remove it from queue
            q.pop();

            // iterate over the all neighbors node
            for (auto adjNode : adj[node])
            {
                // decrease edges count by one
                inDegree[adjNode]--;

                // if any node in-degree become to 0, then push into queue
                if (!inDegree[adjNode])
                    q.push(adjNode);
            }
        }

        // If the queue is empty and there are still nodes in the graph,
        // the graph contains a cycle and cannot be topologically sorted.
        if (res.size() != n)
            return {};

        return res;
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 1}, {5, 2}};
    // out put would be -> { 0, 4, 5, 1, 2, 3 }
    vector<int> res = obj.topologicalSort(edges, 6);

    cout << "The Liner order is : ";
    for (auto node : res)
        cout << node << " ";

    return 0;
}